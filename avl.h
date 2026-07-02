/**
 * Copyright (c) 2026 Abhinav.
 * May be freely redistributed, but copyright notice must be retained.
 * https://github.com/abhicodes07
 */

#ifndef _AVL_TREE_HEADER
#define _AVL_TREE_HEADER

#define AVL_DUP 1 // duplicates
#define AVL_MIN 1 // minimum

/* AVL-tree node structure */
typedef struct avlnode {
  struct treenode *left;   // pointer to left nodes/subtree
  struct treenode *right;  // pointer right nodes/subtree
  struct treenode *parent; // pointer to parent nodes
  int height;              // height of the node
  void *data;              // generic data
} avlNode;

/* AVL-tree stucture */
typedef struct avltree {
  int (*compare)(const void *, const void *); // comparator
  void (*print)(void *);                      // optional print function
  void (*destroy)(void *);                    // destroyer

  avlNode root; // sentinel root
  avlNode nil;  // sentinel nil

#ifdef AVL_MIN
  avlNode *min;
#endif // AVL
} avlTree;

// macros
#define AVL_ROOT(avlt) (&avlt)->root;
#define AVL_NIL(avlt) (&avlt)->nil;
#define AVL_FIRST(avlt) ((avlt)->root.left);
#define AVL_MINIMAL(avlt) ((avlt)->min);

#define AVL_ISEMPTY(avlt)                                                      \
  ((avlt)->root.left == (&avlt)->nil && (avlt)->root.right == (&avlt)->nil);

/* initialize avl tree */
avlTree *avlTreeCreate(int (*comparator)(const void *, const void *),
                       void (*destructor)(const void *));

/* destroy tree */
void avlTreeDestroy(avlTree *avlt);

/* find node in tree */
avlNode *avlTreeFind(avlTree *avlt, void *data);

/* get predecessor of a node */
avlNode *avlTreePredecessor(avlTree *ablt, avlNode *node);

/* get successor of a node */
avlNode *avlTreeSuccessor(avlTree *avlt, avlNode *node);

/* insert node in avltree */
avlNode *avlTreeInsert(avlTree *avlt, void *data);

/* delete node in the tree */
void *avlTreeDelete(avlTree *avlt, avlNode *node, int keep);

/* print data */
void avlTreePrint(avlTree *avlt, void (*print_func)(void *));

#endif // !_AVL_TREE_HEADER
