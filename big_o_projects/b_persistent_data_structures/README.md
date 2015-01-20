## Persistent Data Structures

(These are post-hoc notes)

We talked about:

### Requirements and the implicit design space

Our requirements are that we preserve referential integrity (i.e. a
thing does not change) for any collection that we create. An example
of this--if we concatenate two lists `a` and `b`:

```haskell
a = [1,2,3,4]
b = [5,6,7,8]
c = a ++ b
```

or

```clojure
(def c (concat a b))
```

or

```java
PersistentList<Integer> c = a.concat(b);
```

then `a` should still equal `[1,2,3,4]`, `b` should still equal
`[5,6,7,8]`, and c should equal `[1,2,3,4,5,6,7,8]`.

Another example--if we "replace" the nth element in a sequence and
assign the result, the original list should persist as long as we hold
the reference to it:

```ruby
a = ImmutableArray.new([1,2,3,4,5])
b = a.set_nth(4, "derp")
```

So here, `a` should still equal `[1,2,3,4,5]`, while `b` should equal
`[1,2,3,4,"derp"]`.

The naive way of preserving all these referenced collections would
just be to defensively clone every data structure on every operation
that "mutates", but if we can manage to share some of the underlying
state, we could reduce memory usage and allocation time, drastically
in some cases (e.g. replacing the first item of a list of 1,000,000
items).

So how can we share state? We had a good spitballing session on this
in our meeting, but there is a great summary at
http://en.wikipedia.org/wiki/Persistent_data_structure . Basically, we
can either keep a value/pointer history at each "node" of the data
structure, or we can copy the path from the root element of our data
structure to the change site. Both of these approaches imply that we
are using some sort of recursive datatype, e.g. a Node-based linked
list or tree. There is an interesting hybrid approach in the
aforementioned wiki, which also has excellent illustrations of the
path copying approach.

### Assignment, should you choose to accept it

1. Make a persistent linked list using the path copying
   implementation. The list should support `a.concatenate(b)`,
   `a.insert(v,n)` (insert value v at position n), `a.head()` (get the
   first value), `a.tail()` (get all but the first node), `a.take(n)`
   (get the first N nodes), and `a.drop(n)` (get all the nodes minus
   the first n).

2. Make a persistent binary tree.

3. Make a self-balancing persistent binary search tree (the previous
   unbalanced tree should persist after a rebalancing insert).
