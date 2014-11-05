/*
 * test.cpp
 *
 *  Created on: Nov 4, 2014
 *      Author: Jackson
 */

#include <iostream>
#include "BinaryTree.h"
#include "ArrayDeque.h"
#include "BinarySearchTree.h"
#include "utils.h"
#include "DLList.h"
using namespace std;
using namespace ods;

void testPartOne() {
	BinarySearchTree<BSTNode1<int>, int> st;

	st.add(100);
	st.add(50);
	st.add(150);

	cout << "Height Tests..." << endl;
	cout << "Recursive height: " << st.height() << endl;
	cout << "Non-recursive height: " << st.height2() << endl;
	st.add(0);
	st.add(200);
	cout << "Recursive height: " << st.height() << endl;
	cout << "Non-recursive height: " << st.height2() << endl;
}

void testPartTwo() {
	BinarySearchTree<BSTNode1<int>, int> st;

	st.add(100);
	st.add(50);
	st.add(150);

	cout << "Balance tests..." << endl;
	cout << "Balanced? (Should be 1) " << st.isBalanced() << endl;

	st.add(200);

	cout << "Balanced? (Should be 1) " << st.isBalanced() << endl;

	st.add(125);

	cout << "Balanced? (Should be 0) " << st.isBalanced() << endl;

	st.add(0);

	cout << "Balanced? (Should be 1) " << st.isBalanced() << endl;
}

void testPartThree() {
	BinarySearchTree<BSTNode1<int>, int> st;

	st.add(100);
	st.add(50);
	st.add(150);

	st.preOrderNumber();
	st.postOrderNumber();
	st.inOrderNumber();

	st.printAll();
}

void testPartFour() {
	BinarySearchTree<BSTNode1<int>, int> st;

	st.add(555);
	st.add(400);
	st.add(300);
	st.add(450);
	st.add(175);
	st.add(310);
	st.add(425);
	st.add(475);
	st.add(600);
	st.add(556);
	st.add(650);
	st.add(557);
	st.add(625);
	st.add(651);
	st.add(558);
	st.add(559);

	cout << "Get less than tests..." << endl;
	DLList<int> *list = st.getLE(560);
	for (int i = 0; i < list->size(); i++) {
		cout << list->get(i) << " ";
	}
	cout << endl << "Done";
	delete list;
}

int main() {
	testPartOne();
	cout << endl;
	testPartTwo();
	cout << endl;
	testPartThree();
	cout << endl;
	testPartFour();
	return 0;
}

