# AVL trees in c

- AVL Tree can be defined as height balance binary search tree (BST).
- It is a self balancing binary search tree in which each node maintains extra information called as balance factor whose value is either `-1`, `0` or `+1`.

## Balance Factor

- Balance factor of a node in an AVL tree is the difference between the height of the left subree and that of the right subtree of that node.

`balance_factor = height of left-subtree - height of right-subtree`

- The self balancing proptery of an AVL tree is maintained by the balance factor.

## Files

- `avl.h` : AVL tree header file
- `avl.c` : AVL tree library file
