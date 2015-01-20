Said-It Distance
=========

### Problem Statement

This problem combines two text/language processing metrics:

#### Edit distance (aka Levenshtein Distance)

The first measures the distance between two strings in terms of edits,
which consist of either single insertions, deletions, or substitutions
of letters. e.g.:

* cat => **h** at (distance: 1)
* plato => plat **_** => pla **n** => p **_** an => **m** an (distance: 4)

We will not use the variations that allow for transposition, etc.

#### Double Metaphone phonic encoding

The second encodes (and thus implicitly indexes) English words by
their characteristic sounds, giving two (possibly identical)
interpretations, e.g.:

* hello => `["HL","HL"]` (or `["HL",nil]` in some implementations)
* world => `["FRLT","ARLT"]`

Double Metaphone implementations may be found pretty easily--let's use the
following:

* C++: https://github.com/slacy/double-metaphone, example at
  https://github.com/slacy/double-metaphone/blob/master/dmtest.cc
* JVM: http://commons.apache.org/proper/commons-codec/, docs at
  http://commons.apache.org/proper/commons-codec/apidocs/org/apache/commons/codec/language/DoubleMetaphone.html
* Python: https://pypi.python.org/pypi/Metaphone/0.4, example at
  https://github.com/oubiwann/metaphone#example-code
* Ruby: https://www.ruby-toolbox.com/projects/text, example at
  https://github.com/threedaymonk/text#metaphone

#### Problem Statement, for realz

Given two words, find the shortest letterwise cumulative edit distance
traversal between them through legal (i.e. not made up/nonsense)
words, where each adjacent pair of words in the traversal has Double
Metaphone encodings an edit distance of `1` apart. If no such
traversal exists, give up. This requires a list of legal words; use
`/usr/share/dict/words` on your machine or `wordlist.txt` in this
directory.


### Examples

Adjacent words in this traversal must have Double Metaphone encodings
with a Levenstein distance of `1`:

`hello ["HL"] => low ["L"]`
or
`hello ["HL"] => he ["H"]`

and the cumulative, letterwise edit distance between start and end
should be minimized:

`hello => low => lathe`, `HL -> L -> L0`, with cumulative edit
distance `4 + 4 = 8` is beaten by `hello => he => the => lathe`, `HL
-> H -> 0 -> L0`, with cumulative distance `3 + 1 + 2 = 6`.

Sample word list is included in this directory.

### Variations

* For comparison's sake: When there is more than one solution with the
  same cumulative edit distance, pick the one with the shortest
  wordlist traversal. When there is also a tie based on this
  criterion, pick the wordlist whose concatenation sorts first
  alphabetically.

### Real-world problems this is close to

* Suggesting typo, mispelling or OCR corrections (edit distance)
* Resolving misheard/mistranscribed words to candidate interpretations
  (Double Metaphone)
