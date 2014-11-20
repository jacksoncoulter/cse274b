//============================================================================
// Name        : hw5.cpp
// Author      : Pierre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace std;
using namespace ods;

const int TRIALS = 20;
const int LIMIT = 50000;

void testChainedHashTable() {

	cout << "ChainedHashTable:" << endl;

	DataStructureTester<ChainedHashTable<int>> chtTestS;
	DataStructureTester<ChainedHashTable<int>> chtTestR;

	double averageDSA = 0;
	double averageDRA = 0;
	double averageDSF = 0;
	double averageDRF = 0;
	double averageDSR = 0;
	double averageDRR = 0;

	for (int i = 0; i < TRIALS; i++) {
		averageDSA += chtTestS.DoSequentialAdd(1, LIMIT, 1);
		averageDRA += chtTestR.DoRandomAdd(LIMIT);
		averageDSF += chtTestS.DoSequentialFind(1, LIMIT, 1);
		averageDRF += chtTestR.DoRandomFind(LIMIT);
		averageDSR += chtTestS.DoSequentialRemove(1, LIMIT, 1);
		averageDRR += chtTestR.DoRandomRemove(LIMIT);
	}

	averageDSA /= TRIALS;
	averageDRA /= TRIALS;
	averageDSF /= TRIALS;
	averageDRF /= TRIALS;
	averageDSR /= TRIALS;
	averageDRR /= TRIALS;

	cout << "Average DoSequentialAdd Runtime: " << averageDSA << "ms" << endl;
	cout << "Average DoRandomAdd Runtime: " << averageDRA << "ms" << endl;
	cout << "Average DoSequentialFind Runtime: " << averageDSF << "ms" << endl;
	cout << "Average DoRandomFind Runtime: " << averageDRF << "ms" << endl;
	cout << "Average DoSequentialRemove Runtime: " << averageDSR << "ms"
			<< endl;
	cout << "Average DoRandomRemove Runtime: " << averageDRR << "ms" << endl;

	cout << endl;

}

void testBinarySearchTree() {
	cout << "BinarySearchTree:" << endl;

	DataStructureTester<BinarySearchTree<BSTNode1<int>, int>> bstTestS;
	DataStructureTester<BinarySearchTree<BSTNode1<int>, int>> bstTestR;

	double averageDSA = 0;
	double averageDRA = 0;
	double averageDSF = 0;
	double averageDRF = 0;
	double averageDSR = 0;
	double averageDRR = 0;

	for (int i = 0; i < TRIALS; i++) {
		averageDSA += bstTestS.DoSequentialAdd(1, LIMIT, 1);
		averageDRA += bstTestR.DoRandomAdd(LIMIT);
		averageDSF += bstTestS.DoSequentialFind(1, LIMIT, 1);
		averageDRF += bstTestR.DoRandomFind(LIMIT);
		averageDSR += bstTestS.DoSequentialRemove(1, LIMIT, 1);
		averageDRR += bstTestR.DoRandomRemove(LIMIT);
	}

	averageDSA /= TRIALS;
	averageDRA /= TRIALS;
	averageDSF /= TRIALS;
	averageDRF /= TRIALS;
	averageDSR /= TRIALS;
	averageDRR /= TRIALS;

	cout << "Average DoSequentialAdd Runtime: " << averageDSA << "ms" << endl;
	cout << "Average DoRandomAdd Runtime: " << averageDRA << "ms" << endl;
	cout << "Average DoSequentialFind Runtime: " << averageDSF << "ms" << endl;
	cout << "Average DoRandomFind Runtime: " << averageDRF << "ms" << endl;
	cout << "Average DoSequentialRemove Runtime: " << averageDSR << "ms"
			<< endl;
	cout << "Average DoRandomRemove Runtime: " << averageDRR << "ms" << endl;

	cout << endl;
}

void testLinearHashTable() {
	cout << "LinearHashTable:" << endl;

	DataStructureTester<LinearHashTable<int>> lhtTestS;
	DataStructureTester<LinearHashTable<int>> lhtTestR;

	double averageDSA = 0;
	double averageDRA = 0;
	double averageDSF = 0;
	double averageDRF = 0;
	double averageDSR = 0;
	double averageDRR = 0;

	for (int i = 0; i < TRIALS; i++) {
		averageDSA += lhtTestS.DoSequentialAdd(1, LIMIT, 1);
		averageDRA += lhtTestR.DoRandomAdd(LIMIT);
		averageDSF += lhtTestS.DoSequentialFind(1, LIMIT, 1);
		averageDRF += lhtTestR.DoRandomFind(LIMIT);
		averageDSR += lhtTestS.DoSequentialRemove(1, LIMIT, 1);
		averageDRR += lhtTestR.DoRandomRemove(LIMIT);
	}

	averageDSA /= TRIALS;
	averageDRA /= TRIALS;
	averageDSF /= TRIALS;
	averageDRF /= TRIALS;
	averageDSR /= TRIALS;
	averageDRR /= TRIALS;

	cout << "Average DoSequentialAdd Runtime: " << averageDSA << "ms" << endl;
	cout << "Average DoRandomAdd Runtime: " << averageDRA << "ms" << endl;
	cout << "Average DoSequentialFind Runtime: " << averageDSF << "ms" << endl;
	cout << "Average DoRandomFind Runtime: " << averageDRF << "ms" << endl;
	cout << "Average DoSequentialRemove Runtime: " << averageDSR << "ms"
			<< endl;
	cout << "Average DoRandomRemove Runtime: " << averageDRR << "ms" << endl;

	cout << endl;
}

void testRedBlackTree() {
	cout << "RedBlackTree:" << endl;

	DataStructureTester<RedBlackTree<RedBlackNode1<int>, int>> rbtTestS;
	DataStructureTester<RedBlackTree<RedBlackNode1<int>, int>> rbtTestR;

	double averageDSA = 0;
	double averageDRA = 0;
	double averageDSF = 0;
	double averageDRF = 0;
	double averageDSR = 0;
	double averageDRR = 0;

	for (int i = 0; i < TRIALS; i++) {
		averageDSA += rbtTestS.DoSequentialAdd(1, LIMIT, 1);
		averageDRA += rbtTestR.DoRandomAdd(LIMIT);
		averageDSF += rbtTestS.DoSequentialFind(1, LIMIT, 1);
		averageDRF += rbtTestR.DoRandomFind(LIMIT);
		averageDSR += rbtTestS.DoSequentialRemove(1, LIMIT, 1);
		averageDRR += rbtTestR.DoRandomRemove(LIMIT);
	}

	averageDSA /= TRIALS;
	averageDRA /= TRIALS;
	averageDSF /= TRIALS;
	averageDRF /= TRIALS;
	averageDSR /= TRIALS;
	averageDRR /= TRIALS;

	cout << "Average DoSequentialAdd Runtime: " << averageDSA << "ms" << endl;
	cout << "Average DoRandomAdd Runtime: " << averageDRA << "ms" << endl;
	cout << "Average DoSequentialFind Runtime: " << averageDSF << "ms" << endl;
	cout << "Average DoRandomFind Runtime: " << averageDRF << "ms" << endl;
	cout << "Average DoSequentialRemove Runtime: " << averageDSR << "ms"
			<< endl;
	cout << "Average DoRandomRemove Runtime: " << averageDRR << "ms" << endl;

	cout << endl;
}

int main() {

	testChainedHashTable();
	testBinarySearchTree();
	testLinearHashTable();
	testRedBlackTree();

	return 0;
}
