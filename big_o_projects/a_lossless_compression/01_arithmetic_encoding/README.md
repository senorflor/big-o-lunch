## Arithmetic Encoding

Now it's time to get real, or at least rational, or maybe algebraic
(but probably not).

### The pure maths way

Imagine you have the probability of occurence
[\(i.i.d.\)](en.wikipedia.org/wiki/Independent_and_identically_distributed_random_variables)
for each member of an alphabet. Map these onto [0,1] as a cumulative
distribution function (cdf). Encode any string by starting with this
interval, "going into" the interval denoted by the first character's
ordering/"jump" on the cdf, then rescaling that interval for the cdf
of character 2. Repeat ad infinitesimalum.

(Since that was the least clear copy ever, I'll draw an example on the
board here.)

This procedure will map all strings uniquely to real numbers in [0,1].
For the case where the alphabet follows a geometric distribution, it
produces the same encoding as Huffman encoding does, and can thus be
seen a generalization of that procedure.

It is theoretically beautiful, and thus horribly impractical for
computation. There are a number of ways to adapt the central idea to
actual computable (binary, discrete) things, though:

### The quasi-floating point way:

The number of bits needed to represent a string X = [x1,x2,...,xn]
uniquely is

```
⌈              ⌉
  lg (1/P(X))   + 1.
```

(Those are ceiling brackets, acc. to Unicode. I probably should have
LaTeχ'd this.)

Once we know that we will be on one or another side of 0.5, we can
emit the MSB (1 for [0.5,1], 0 for [0,0.5]), rescale the new
subinterval, then keep going recursively. On the decode side, once you
are fixed in the interval corresponding to a letter, you may emit that
letter, rescale, then keep going.

### The integer-based way:

(Didn't have the fortitude/time to read this section of the book I'm
going through.)

### Adaptive Arithmetic Coding

Start with a uniform presumed distribution, and reweight the intervals
at every string member.

### Binary Arithmetic Coding

When `1` is more or less likely than `0`, this is better than a binary
literal. There are some optimizations that, instead of the
multiplicative relationship that's implied in recursive descent into
the interval [0,1], use the assumption that the more probable symbol
has a probability of 1, rescaling only every time that the less
probable symbol occurs.
