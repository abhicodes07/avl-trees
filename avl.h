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
  void (*destroy)(void *);                    // destoryer

  avlNode root; // sentinel root
  avlNode nil;  // sentinel nil

#ifdef AVL_MIN
  avlNode *min;
#endif // AVL
} avlTree;

#endif // !_AVL_TREE_HEADER
