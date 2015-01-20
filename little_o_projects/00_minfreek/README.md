minfreek
========

Could have been k-minfree, but this way it sounds more like a dance
move that Miley Cyrus might appropriate.

### Problem Statement

Given an unordered list `l` of non-negative integers and a length `k`,
find the first (closest to zero) group of k contiguous, non-negative
integers all not in `l`.

History was squashed for publication, but thanks to
https://github.com/michaelficarra for the statement clarification.

### Examples

```
minfree ([2,3,1], 1)     => [0]
minfree ([4,5,2,0], 2)   => [6,7]
minfree ([5,1], 3)       => [2,3,4]
```

### Real-world problems this is close to

* First-fit memory/disk allocation

### Based on

Speaking of appropriation, minfreek was inspired by working through
http://www.amazon.com/Pearls-Functional-Algorithm-Design-Richard/dp/0521513383,
problem 1, and recalling various tidbits from
[Operating Systems](http://www.ittc.ku.edu/~kulkarni/) and
[Intro to Algorithms](http://people.eecs.ku.edu/~kinners/).
