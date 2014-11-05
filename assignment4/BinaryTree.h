/*
 * BinaryTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstdlib>
#include <cmath>

#include "ArrayDeque.h"

namespace ods {

template<class N>
class BTNode {
public:
	N *left;
	N *right;
	N *parent;
	BTNode() {
		left = right = parent = NULL;
	}
};

template<class Node>
class BinaryTree {
protected:
	Node *r;    // root node
	Node *nil;  // null-like node
	virtual bool isBalanced(Node *u);
	virtual int size(Node *u);
	virtual int height(Node *u);
	virtual int height2(Node *u);
	virtual void traverse(Node *u);
public:
	virtual bool isBalanced();
	virtual int height2();
	virtual ~BinaryTree();
	BinaryTree();
	BinaryTree(Node *nil);
	virtual void clear();
	virtual int depth(Node *u);
	virtual int size();
	virtual int size2();
	virtual int height();
	virtual void traverse();
	virtual void traverse2();
	virtual void bfTraverse();
};

class BTNode1: public BTNode<BTNode1> {
};

template<class Node>
bool BinaryTree<Node>::isBalanced(Node *u) {
	if (u->left == nil) {
		if (u->right == nil || size(u->right) == 1) {
			return true;
		} else {
			return false;
		}
	} else if (u->right == nil) {
		if (u->left == nil || size(u->left) == 1) {
			return true;
		} else {
			return false;
		}
	}
	if (abs(size(r->left) - size(r->right)) > 1) {
		return false;
	} else {
		return (isBalanced(u->left) && isBalanced(u->right));
	}
}

template<class Node>
bool BinaryTree<Node>::isBalanced() {
	return isBalanced(r);
}

template<class Node>
int BinaryTree<Node>::height2() {
	return height2(r);
}

template<class Node>
int BinaryTree<Node>::height2(Node* u) {
	u = r;
	Node *prev = nil, *next;
	int n = 0;
	int max = 0;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil) {
				n++;
				next = u->left;
			} else if (u->right != nil) {
				n++;
				next = u->right;
			} else {
				n--;
				next = u->parent;
			}
		} else if (prev == u->left) {
			if (u->right != nil) {
				n++;
				next = u->right;
			} else {
				n--;
				next = u->parent;
			}
		} else {
			n--;
			next = u->parent;
		}
		if (n > max) {
			max = n;
		}
		prev = u;
		u = next;
	}
	return max;
}

template<class Node>
BinaryTree<Node>::~BinaryTree() {
	clear();
}

template<class Node>
void BinaryTree<Node>::clear() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		if (next == u->parent)
			delete u;
		u = next;
	}
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree(Node *nil) {
	this->nil = nil;
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree() {
	nil = NULL;
	r = nil;
}

template<class Node>
int BinaryTree<Node>::depth(Node *u) {
	int d = 0;
	while (u != r) {
		u = u->parent;
		d++;
	}
	return d;
}

template<class Node>
int BinaryTree<Node>::size() {
	return size(r);
}

template<class Node>
int BinaryTree<Node>::size(Node *u) {
	if (u == nil)
		return 0;
	return 1 + size(u->left) + size(u->right);
}

template<class Node>
int BinaryTree<Node>::size2() {
	Node *u = r, *prev = nil, *next;
	int n = 0;
	while (u != nil) {
		if (prev == u->parent) {
			n++;
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
	return n;
}

template<class Node>
int BinaryTree<Node>::height() {
	return height(r);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
	if (u == nil)
		return -1;
	return 1 + max(height(u->left), height(u->right));
}

template<class Node>
void BinaryTree<Node>::traverse() {
	traverse(r);
}

template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
	if (u == nil)
		return;
	traverse(u->left);
	traverse(u->right);
}

template<class Node>
void BinaryTree<Node>::traverse2() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
			if (u->left != nil)
				next = u->left;
			else if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nil)
				next = u->right;
			else
				next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
}

template<class Node>
void BinaryTree<Node>::bfTraverse() {
	ArrayDeque<Node*> q;
	if (r != nil)
		q.add(q.size(), r);
	while (q.size() > 0) {
		Node *u = q.remove(q.size() - 1);
		if (u->left != nil)
			q.add(q.size(), u->left);
		if (u->right != nil)
			q.add(q.size(), u->right);
	}
}

} /* namespace ods */
#endif /* BINARYTREE_H_ */
