## Lossless Compression: intro

(These are post-hoc notes)

We talked about:

### Lossless vs. lossy data compression

The former is a perfect roundtrip (i.e. `unzip(zip(data)) == data` for
all inputs), while the latter discards some data in order to acheive
even better compression (while maintaining sufficient
quality/faithfulness for the intended application). We are studying
lossless data compression this time, but if anyone wants to run
point on a complementary series on lossy compression, please do!

### An intro to the theory behind lossless data compression

#### Kolmogorov Complexity

Kolmogorov complexity `k(u,s)` is the minimal length for an encoding
of a string `s` in some fixed universal description language `u`. This
means that if `u` can describe all strings in some alphabet, `k` gives
the length of a shortest desciption in `u` of the string `s` such that
`s` could be completely reconstructed from that description. `k` is in
general incomputable \(see
[wikipedia](http://en.wikipedia.org/wiki/Kolmogorov_complexity#Incomputability_of_Kolmogorov_complexity)\).

#### What does that mean?

It's a mininum bound on the compression of any possible string/file,
and is thus a measure of that file's complexity. Random files/strings
have high complexity, while files with patterns/common subsequences
have lower complexity. As an example, if we use only grouping and
precise quantification in a regular expression-like language:

```
vneioalfmsuxasdep393bf21 => /vneioalfmsuxasdep393bf21/
abababababababababababab => /(ab){12}/
aaaaaaaaaaaaaaaaaaaaaaaa => /a{24}/
```

#### In practice:

A lossless compression algorithm will approach this bound by
discovering repeated patterns in a file and representing them
concisely, or by utilizing known/discovered frequencies/distributions.
These algorithms are combined into the compression utilities that we
know from use in day-to-day work and application development, e.g.
`compress/uncompress` or `zip/unzip` (older), `gzip/gunzip` or
`bzip2/bunzip2` (newer).

This is particularly interesting in the context of an algorithms group
like ours, because most of what we look at/practice involves trading
memory for cpu (e.g. using the extra indexing mechanisms in a hash map
to speed up access to items keyed by it) but compression is a family
of algorithms that trades cpu (running the compression/decompression)
for memory (smaller format). This is obviously useful in terms of
reduced network bandwidth and smaller persistent file storage, but
work has also been done showing some usefulness of data compression on
cache lines in running programs
\([here's a pdf](http://research.cs.wisc.edu/multifacet/papers/isca04_adaptive_compression.pdf)\).
Furthermore, some algorithms can operate with fewer operations over
compressed files (imagine `cat`ing 10MB of `a`s through `tr a b` as
opposed to replacing one in the representation `a{10000000}`).

5 data files are provided in [./data](data/) to play around with; they
are all 10,000,000 bytes to start, so try compressing and
uncompressing them to compare compression ratios and runtime for
various compression utilities.

### For next week:

**Implement Huffman coding/decoding.**

This is a common problem in undergraduate algorithms classes, so you
may have experience with this particular algorithm, but if
not, the wiki is pretty informative:
http://en.wikipedia.org/wiki/Huffman_coding. The encoder should pass
enough information along with the encoded text so that the decoder can
decode it, obviously, but otherwise there are no restrictions on the
format of the compressed file. As with all lossless compression
algorithms, the test is easy: does a round trip through encode/decode
return an identical file for all test inputs, and is the compressed
file (including the decoding key!) smaller than the original?

### Huffman Encoding

(We talked about it lots, and had/reviewed some implementations.)

General summary: it's a weight-balanced tree where the leaf nodes
represent a code point in the alphabet being encoded/decoded, and the
L(0) vs R(1) traversal from root to a letter's leaf node is that
letter's code. Can be constructed up-front, given a known probability
distribution for the alphabet, or incrementally/adaptively.

Works well for: Alphabets with a geometric probability distribution
(e.g. P(a) = .5, P(b) = .25, P(c) = .125, etc.), or
chunking/discretization that ends up with an approximately geometric
distribution.

Disadvantages: large codebooks for large alphabets with a fair bit of
memory/transmission overhead (can be mitigated by table-based or
hybrid table-tree approaches); need to transmit decode tree for the
up-front version.

Common applications: it's a step in many common compression
tools/formats (e.g. gzip, bzip2, jpeg, png,
\[where the data is quantized in a lossy manner first, then those quanta are code-wise compressed\],
 mp3 \[similar procedure to jpeg\]).
