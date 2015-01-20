Countdown
=========

### Problem Statement

*WARNING*: this one is all over the internet, so do not Google it
unless you get desparate `||` like spoilers `||` are a fan of the
Yankees. Consider this an exercise in willpower as well as algorithmic
and data structure prowess.

Let's do a classic. Given 6 positive integers, find an arithmetic
expression combining some/all of them using the usual *binary*
arithmetic operators, `+`, `-`, `*`, and `/`, plus parentheses, to
return a positive integer as close as possible to a provided seventh
number, and then return the difference between the desired and
acheived results. `/` may only be used where the reduced result of the
expression/subexpression is a positive integer. You do not have to use
all of the numbers, nor all of the available operators. Each number
may only be used once or not at all, but you may repeat operators as
necessary.

It's illegal to ever have a non-integral or non-positive number at any
level of evaluation or partial evaluation, so `(20 / 7) * (14 / 10)`
is an illegal way of getting to 4, but `(20 * 14) / (7 * 10)` is
legal. Similary, `(2 - 2) - 1` is illegal (a subexpression evaluates
to 0, not a positive integer), while `2 - (2 - 1)` is A-OK.

For bonus points, make it a constructive solution, i.e. output the
arithmetic expression itself, not just the minimum distance
achievable. If you are using something LISPy, an s-expression format
would be just fine instead of naked infix.

### Examples

```
countdown ([1,1,1,1,1,1], 6)          => 0
    example expressions:
    "1 + 1 + 1 + 1 + 1 + 1"     = 6
    "(1 + 1) * (1 + 1 + 1)"     = 6
    "(1 + 1) * (1 + 1) + 1 + 1" = 6

countdown ([1,3,25,7,10,50], 831)     => 1
    example expressions:
    "7 + (1 + 10) * (25 + 50)" = 832
    "((50 + 7 + 25) + 1) * 10" = 830

// Horribly contrived example:
countdown ([1234,234,26,23,1,15], 26) => 0
    minimally long expression: "26"
```
### Variations

* Generalize this to "given a list of positive integers" (the search
  space blows up pretty quickly above 6 candidates).
* For extra bonus points, make it a second-order ranking criterion to
  find a solution with the fewest possible non-space characters.
  Parentheses count as non-space characters.
* Come up with a different set of binary operators, e.g. `+`, `%`,
  `div`, and `**` (exponentiation).
* Rank solutions secondarily based on how many additions/subtractions
  they imply for naive implementations of `*` and `/`. Naively `n * m`
  implies `min(n,m)` additions, and `n / m` implies `n/m` subtractions
  or additions (plus some comparisons, but ignore those).
* PR any other interesting ones you can think of!

### Real-world problems this is close to

* http://en.wikipedia.org/wiki/Countdown_(game_show)
