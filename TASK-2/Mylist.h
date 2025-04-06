#pragma once
#include "List.h"
template<typename T>
class Mylist:public List<T>
{
public:
	Mylist(int ms=5) : List<T>(ms) {}

	bool empty() {
		return List<T>::currentsize == 0;
	}

	bool Full() {
		return List<T>::currentsize == List<T>::maxsize;
	}

	int size() {
		return List<T>::currentsize;
	}

	bool insertAt(int index, T val){
		if (index < List<T>::maxsize) {
			List<T>::arr[index] = val;
			return true;
		}
		else
			return false;
	}

	T last() {
		return List<T>::arr[List<T>::currentsize];
	}

	bool search(T val) {
		for (int i = 0; i < List<T>::currentsize; i++) {
			if (List<T>::arr[i] == val) {
				return true;
			}
		}
		return false;
	}

	Mylist(const Mylist& other):List<T> (other) {}

	~Mylist() {}

	
	void addElementatfirstindex(T e) override {
		if (Full()) {
			cerr << "List is full! Cannot insert " << e << endl;
			return;
		}

		for (int i = List<T>::currentsize; i > 0; i--) {
			List<T>::arr[i] = List<T>::arr[i - 1];
		}

		List<T>::arr[0] = e;
		List<T>::currentsize++;
		}

	void addElementatlastindex(T e) override {
		if (Full()) {
			cerr << "List is full! Cannot insert " << e << endl;
			return;
		}

		List<T>::arr[List<T>::currentsize] = e;
		List<T>::currentsize++;
	}
	
	T removeElementfromEnd() override {
		if (!empty())
		{
			List<T>::currentsize--;
			return List<T>::arr[List<T>::currentsize];
		}

		else
			cerr << "Array is Empty!" << endl;
	}

	void removeElementfromStart() override {
		if (!empty())
		{
			int j = 1;
			for (int i = 0; i < List<T>::currentsize; i++) {
				List<T>::arr[j] = List<T>::arr[i];
				j++;
			}
			List<T>::currentsize--;
		}
		else
			cerr << "Array is Empty!" << endl;
	}

	void display() {
		for (int i = 0; i < List<T>::currentsize; i++) {
			cout << List<T>::arr[i] << " ";
		}
	}

};




