/*
 * BinarySearchTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <climits>
#include <cmath>
#include "BinaryTree.h"
#include "utils.h"
#include "DLList.h"

namespace ods {

template<class Node, class T>
class BSTNode: public BTNode<Node> {
public:
	T x;
};

// this makes sense, so dont use it
template<class K, class T>
class Node {
	Node *left;
	Node *right;
	Node *parent;
	K key;
	T data;
};

/**
 * A binary search tree class.  The Node parameter should be a subclass
 * of BSTNode<T> (or match it's interface)
 */
template<class Node, class T>
class BinarySearchTree: public BinaryTree<Node> {
protected:
	using BinaryTree<Node>::r;
	using BinaryTree<Node>::nil;
	int n;
	T null;
	virtual void printAll(Node *u);
	virtual void addAll(Node *u, DLList<T> &list);
	virtual void helper(Node *u, DLList<T> &list, T z);
	virtual Node *findLast(T x);
	virtual Node *preOrderNumber(Node *u, int &x);
	virtual Node *postOrderNumber(Node *u, int &x);
	virtual Node *inOrderNumber(Node *u, int &x);
	virtual bool addChild(Node *p, Node *u);
	virtual void splice(Node *u);
	virtual void remove(Node *u);
	virtual void rotateRight(Node *u);
	virtual void rotateLeft(Node *u);
	virtual bool add(Node *u);
public:
	virtual void printAll();
	virtual Node* getNode(T x);
	virtual void preOrderNumber();
	virtual void postOrderNumber();
	virtual void inOrderNumber();
	virtual DLList<T> *getLE(T x);
	BinarySearchTree();
	BinarySearchTree(T null);
	virtual ~BinarySearchTree();
	virtual bool add(T x);
	virtual bool remove(T x);
	virtual T find(T x);
	virtual T findEQ(T x);
	virtual int size();
	virtual void clear();
};

template<class T>
class BSTNode1: public BSTNode<BSTNode1<T>, T> {
public:
	int preorderNumber;
	int inorderNumber;
	int postorderNumber;
};

template<class T>
class BinarySearchTree1: public BinarySearchTree<BSTNode1<T>, T> {
public:
	BinarySearchTree1();
};

/*
 * FIXME: Why doesn't this work?
 template<class Node>
 BinarySearchTree<Node,int>::BinarySearchTree()  {
 this->null = INT_MIN;
 n = 0;
 }
 */

template<class Node, class T>
void BinarySearchTree<Node, T>::printAll() {
	printAll(r);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::printAll(Node *u) {
	if (u == nil) {
		return;
	}

	cout << u->x << endl;
	cout << "Preorder: " << u->preorderNumber << endl;
	cout << "Postorder: " << u->postorderNumber << endl;
	cout << "Inorder: " << u->inorderNumber << endl;

	printAll(u->left);
	printAll(u->right);
}

template<class Node, class T>
Node* BinarySearchTree<Node, T>::getNode(T x) {
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return z == nil ? nil : z;
}

template<class Node, class T>
DLList<T> *BinarySearchTree<Node, T>::getLE(T x) {
	DLList<T> *list = new DLList<T>();
	helper(r, *list, x);
	return list;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::helper(Node* u, DLList<T> &list, T z) {
	if (u == nil) {
		return;
	} else if (u->x < z) {
		list.add(u->x);
		addAll(u->left, list);
		helper(u->right, list, z);
	} else if (u->x == z) {
		list.add(u->x);
		addAll(u->left, list);
	} else {
		helper(u->left, list, z);
	}
}

template<class Node, class T>
void BinarySearchTree<Node, T>::addAll(Node* u, DLList<T> &list) {
	if (u == nil) {
		return;
	} else {
		list.add(u->x);
		addAll(u->left, list);
		addAll(u->right, list);
	}
}

template<class Node, class T>
void BinarySearchTree<Node, T>::preOrderNumber() {
//	int *x = new int;
//	*x = 0;
//	preOrderNumber(r, x);
//	delete x;
	int x = 0;
	preOrderNumber(r, x);
}

template<class Node, class T>
Node *BinarySearchTree<Node, T>::preOrderNumber(Node *u, int &x) {
	if (u == nil) {
		return nil;
	}

	u->preorderNumber = x;

	x++;
	if (preOrderNumber(u->left, x) == nil) {
		x--;
	}

	x++;
	if (preOrderNumber(u->right, x) == nil) {
		x--;
	}

	return u;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::postOrderNumber() {
	int x = 0;
	postOrderNumber(r, x);
}

template<class Node, class T>
Node *BinarySearchTree<Node, T>::postOrderNumber(Node *u, int &x) {
	if (u == nil) {
		return nil;
	}

	postOrderNumber(u->left, x);
	postOrderNumber(u->right, x);

	u->postorderNumber = x;
	x++;

	return u;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::inOrderNumber() {
	int x = 0;
	inOrderNumber(r, x);
}

template<class Node, class T>
Node *BinarySearchTree<Node, T>::inOrderNumber(Node *u, int &x) {
	if (u == nil) {
		return nil;
	}

	inOrderNumber(u->left, x);

	u->inorderNumber = x;
	x++;

	inOrderNumber(u->right, x);

	return u;
}

template<class Node, class T>
BinarySearchTree<Node, T>::BinarySearchTree() {
	this->null = (T) NULL;  // won't work for non-primitive types
	n = 0;
}

template<class Node, class T>
BinarySearchTree<Node, T>::BinarySearchTree(T null) {
	this->null = null;
	n = 0;
}

template<class Node, class T>
Node* BinarySearchTree<Node, T>::findLast(T x) {
	Node *w = r, *prev = nil;
	while (w != nil) {
		prev = w;
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return prev;
}

template<class Node, class T>
T BinarySearchTree<Node, T>::findEQ(T x) {
	Node *w = r;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return null;
}

template<class Node, class T>
T BinarySearchTree<Node, T>::find(T x) {
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return z == nil ? null : z->x;
}

template<class Node, class T>
BinarySearchTree<Node, T>::~BinarySearchTree() {
	// nothing to do - BinaryTree destructor does cleanup
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::addChild(Node *p, Node *u) {
	if (p == nil) {
		r = u;              // inserting into empty tree
	} else {
		int comp = compare(u->x, p->x);
		if (comp < 0) {
			p->left = u;
		} else if (comp > 0) {
			p->right = u;
		} else {
			return false;   // u.x is already in the tree
		}
		u->parent = p;
	}
	n++;
	return true;
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(T x) {
	Node *p = findLast(x);
	Node *u = new Node;
	u->x = x;
	return addChild(p, u);
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(Node *u) {
	Node *p = findLast(u->x);
	return addChild(p, u);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::splice(Node *u) {
	Node *s, *p;
	if (u->left != nil) {
		s = u->left;
	} else {
		s = u->right;
	}
	if (u == r) {
		r = s;
		p = nil;
	} else {
		p = u->parent;
		if (p->left == u) {
			p->left = s;
		} else {
			p->right = s;
		}
	}
	if (s != nil) {
		s->parent = p;
	}
	n--;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::remove(Node *u) {
	if (u->left == nil || u->right == nil) {
		splice(u);
		delete u;
	} else {
		Node *w = u->right;
		while (w->left != nil)
			w = w->left;
		u->x = w->x;
		splice(w);
		delete w;
	}
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::remove(T x) {
	Node *u = findLast(x);
	if (u != nil && compare(x, u->x) == 0) {
		remove(u);
		return true;
	}
	return false;
}

template<class Node, class T> inline
int BinarySearchTree<Node, T>::size() {
	return n;
}

template<class Node, class T> inline
void BinarySearchTree<Node, T>::clear() {
	BinaryTree<Node>::clear();
	n = 0;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateLeft(Node *u) {
	Node *w = u->right;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->right = w->left;
	if (u->right != nil) {
		u->right->parent = u;
	}
	u->parent = w;
	w->left = u;
	if (u == r) {
		r = w;
		r->parent = nil;
	}
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateRight(Node *u) {
	Node *w = u->left;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->left = w->right;
	if (u->left != nil) {
		u->left->parent = u;
	}
	u->parent = w;
	w->right = u;
	if (u == r) {
		r = w;
		r->parent = nil;
	}
}

/*
 template<class T>
 BinarySearchTree1<T*>::BinarySearchTree1() : BinarySearchTree<BSTNode1<T*>, T*>(NULL) {
 }
 */

template<class T>
BinarySearchTree1<T>::BinarySearchTree1() {
}

} /* namespace ods */
#endif /* BINARYSEARCHTREE_H_ */
