#pragma once
#include <iostream>
using namespace std;
template <typename T>
class List
{
	protected:
	T* arr;
	int maxsize;
	int currentsize;
public:

	List(int ms=5) : maxsize(ms), currentsize(0) {
		arr = new T[maxsize];
	}

	List(const List<T>& other) {
		maxsize = other.maxsize;
		currentsize = other.currentsize;
		arr = new T[maxsize];
		for (int i = 0; i < currentsize; i++) {
			arr[i] = other.arr[i];
		}
	}

	virtual void addElementatfirstindex(T e) = 0;
	virtual void addElementatlastindex(T e) = 0;
	virtual T removeElementfromEnd() = 0;
	virtual void removeElementfromStart() = 0;

	~List() {
		if (arr) delete[] arr;
	}
};

