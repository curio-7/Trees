So if we can index all the nodes whether they are present or not.
so the width will be the max-min+1 index of a particular level.
so now how can we index them as in tc's there will be the case where nodes are not present.
Ex :.
         node(1)
       /      \
    node2     node3                      .
    /           \
  node4        node7                       .

Since nodes are not present but still we are indexing it .
​if we are considering 0-based indxng then left will have (2*i+1) ans right will have (2*i+2) index as i is the index of root.
But in a skew tree it will not work properly (overflow).
so we have to prevent overflow.
so inorder to do that we have to restart indexing at each level .
ex:
         node(0)
       /      \
    node(0)     node(1)
    /           \
  node(0)         node(3)
So it will not produce overflow error in case of skew trees.
So formula is changed as convert i = i - (min value ind at that level) then treat i as before as left will have (2*i+1) ans right will have (2*i+2) index.

We will do L.O.T in this ques.


