#include <iostream>
#include <time.h>
#include <stdlib.h>

namespace ods {

template<class T>
class DataStructureTester {
protected:
	T list;

public:
	void AddRandom(int i) {
		list.add(i);
		//std::cout << "find " << list.find(i) << std::endl;
	}
	int DoSequentialAdd(int start, int end, int step);
	int DoRandomAdd(int n);
	int DoSequentialRemove(int start, int end, int step);
	int DoRandomRemove(int n);
	int DoSequentialFind(int start, int end, int step);
	int DoRandomFind(int n);
};

template<class T>
int DataStructureTester<T>::DoSequentialAdd(int start, int end, int step) {
	clock_t t;
	t = clock();
	for (int i = start; i <= end; i += step) {
		list.add(i);
	}
	t = clock() - t;
	return (int) (((float) t / CLOCKS_PER_SEC) * 1000);
}

template<class T>
int DataStructureTester<T>::DoRandomAdd(int n) {
	clock_t t;
	t = clock();
	for (int i = 0; i < n; i++) {
		srand(i);
		list.add((rand() % 1000) + 1);
	}
	t = clock() - t;
	return (int) (((float) t / CLOCKS_PER_SEC) * 1000);
}

template<class T>
int DataStructureTester<T>::DoSequentialRemove(int start, int end, int step) {
	clock_t t;
	t = clock();
	for (int i = start; i <= end; i++) {
		list.remove(i);
	}
	t = clock() - t;
	return (int) (((float) t / CLOCKS_PER_SEC) * 1000);
}

template<class T>
int DataStructureTester<T>::DoRandomRemove(int n) {
	clock_t t;
	t = clock();
	for (int i = 0; i < n; i++) {
		srand(i);
		list.remove((rand() % 1000) + 1);
	}
	t = clock() - t;
	return (int) (((float) t / CLOCKS_PER_SEC) * 1000);
}

template<class T>
int DataStructureTester<T>::DoSequentialFind(int start, int end, int step) {
	clock_t t;
	t = clock();
	for (int i = start; i <= end; i++) {
		list.find(i);
	}
	t = clock() - t;
	return (int) (((float) t / CLOCKS_PER_SEC) * 1000);
}

template<class T>
int DataStructureTester<T>::DoRandomFind(int n) {
	clock_t t;
	t = clock();
	for (int i = 0; i < n; i++) {
		srand(i);
		list.find((rand() % 1000) + 1);
	}
	t = clock() - t;
	return (int) (((float) t / CLOCKS_PER_SEC) * 1000);
}

}
