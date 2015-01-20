Big O Lunch
===========

Chicago lunchtime programming problems group, public archive edition.
Hopefully someone finds some fun problems in here they've never seen
before!

### What?

We will pose a moderately challenging algorithmic/data structure-y
problem each week (something with a fast feedback mechanism, e.g. the
competition framework on http://hackerrank.com, or the test
files/checkers at http://code.google.com/codejam/) discussing
approaches and comparing solutions during the first 30 minutes. These
problems are in [/little_o_projects/](little_o_projects/) We will
spend the rest of the time each week on a longer topic, e.g.
[/big_o_projects/a_lossless_compression](big_o_projects/a_lossless_compression/).

Things we can look at that are not often enough explored in this
sort of group:

1. Parallelizable and otherwise scalable solutions.
2. Characteristically functional vs. imperative solutions.
3. Mathematical analysis complemented with real benchmarking.

### Why?

1. Because it's fun.
2. To keep developing our [chops](http://www.sweetwater.com/insync/chops/).
3. Because a well-defined and posed programming problem can smell an
   awful lot like well-compartmentalized and specified business logic.

### When? Where?

Thursdays, lunchtime in Chicago. Anytime on the World Wide Web (WWW). 
Open to live meetings in other locations too, if someone wants to run point.

### How?

Just fork it and submit a pull request with your work in the following
format:

`/<big-or-little-dir>/<problem-directory>/[<subproblem>/]<your-@-name>/[<a-language>/]<your-work>`

e.g.

`/little_o_projects/00_minfree/senorflor/the_answer.rb`

or

```
/little_o_projects/01_countdown/senorflor/java/...
/little_o_projects/01_countdown/senorflor/clj/...
/big_o_projects/a_lossless_compression/00_intro_and_huffman/senorflor/cobol/...
```

Tests, harnesses, benchmarking results, multiple languages/solutions,
and problem variations are all welcome, as time allows.

Pull requests will be left open for each problem until the day of the
meeting. Everyone should feel free to fetch, run, comment and bang on
each other's branches, documented for all to see and learn from on
the PR. No squashing/force pushing once submissions go to PR,
please--I think it would be more educational to fellow
implementers/readers for the history of review and revision to remain
unaltered. I will merge all related PRs once we're done with each
problem, for the benefit of future historians.
