#pragma once
#include "Mylist.h"
template <typename T> 
bool isPrime(T val) {
	if (val == 0 || val == 1) {
		return false;
	}

	for (int i = 2; i <= sqrt(val); i++) {
		if (val % i == 0) {
			return false;
		}
	}
	return true;
}

template <typename T>
class CustomList:public Mylist<T> 
{
public:

	CustomList(int ms=5):Mylist<T>(ms) {}

	CustomList(const CustomList<T>& other) :Mylist<T>(other) {}

	~CustomList() {}

	T sumofPrime() {
		T sum = 0;
		for (int i = 0; i < List<T>::currentsize; i++) {
			if (isPrime(List<T>::arr[i])) {
				sum += List<T>::arr[i];
			}
				
		}
		return sum;
	}

	T secondmaxeven() {
		for (int i = 0; i<List<T>::currentsize-1; i++) {
			for (int j = 0; j<List<T>::currentsize - i - 1; j++) {
				if (List<T>::arr[j] < List<T>::arr[j + 1]) {
					swap(List<T>::arr[j], List<T>::arr[j + 1]);
				}
			}
		}
		int evencount = 0;

		for (int i = 0; i < List<T>::currentsize; i++) {
			if (List<T>::arr[i] % 2 == 0) {
				evencount++;
			}
		}
		T* temp = new T[evencount];
		int k = 0;
		for (int i = 0; i < List<T>::currentsize; i++) {
			if (List<T>::arr[i] % 2 == 0) {
				temp[k++] = List<T>::arr[i]; 
			}
		}
		T secondmax = temp[1];
		delete[] temp;
		return secondmax;
	}

	void printduplicates() {
		bool found = false;
		for (int i = 0; i < List<T>::currentsize - 1; i++) {
			for (int j = i + 1; j < List<T>::currentsize; j++) {
				if (List<T>::arr[i] == List<T>::arr[j]) {
					cout << List<T>::arr[i] << " ";
					found = true;
					break;
				}
			}
		}
		cout << (found ? "\n" : "No Duplicates found!\n");
	}

	T secondminodd() {
		for (int i = 0; i<List<T>::currentsize - 1; i++) {
			for (int j = 0; j<List<T>::currentsize - i - 1; j++) {
				if (List<T>::arr[j] > List<T>::arr[j + 1]) {
					swap(List<T>::arr[j], List<T>::arr[j + 1]);
				}
			}
		}

		int oddcount = 0;

		for (int i = 0; i < List<T>::currentsize; i++) {
			if (List<T>::arr[i] % 2 != 0) {
				oddcount++;
			}
		}
		T* temp = new T[oddcount];
		int k = 0;
		for (int i = 0; i < List<T>::currentsize; i++) {
			if (List<T>::arr[i] % 2 != 0) {
				temp[k++] = List<T>::arr[i];
			}
		}
		T secondminodd = temp[1];
		delete[] temp;
		return secondminodd;
	}

	void rotateclockwise(int r) {
		int mid = List<T>::currentsize / 2; 

		
		for (int k = 0; k < r; k++) {
			int last = List<T>::arr[mid - 1];
			for (int i = mid - 1; i > 0; i--) {
				List<T>::arr[i] = List<T>::arr[i - 1];
			}
			List<T>::arr[0] = last;
		}

		
		for (int k = 0; k < r; k++) {
			int last = List<T>::arr[List<T>::currentsize - 1];
			for (int i = List<T>::currentsize - 1; i > mid; i--) {
				List<T>::arr[i] = List<T>::arr[i - 1];
			}
			List<T>::arr[mid] = last;
		}
	}

	void rotateAntiClockwise(int rt) {
		int mid = List<T>::currentsize / 2;

		
		for (int i= 0; i < rt; i++) {
			int first = List<T>::arr[0];
			for (int j = 0; j < mid - 1; j++) {
				List<T>::arr[j] = List<T>::arr[j + 1];
			}
			List<T>::arr[mid - 1] = first;
		}

		
		for (int k = 0; k < rt; k++) {
			int first = List<T>::arr[mid];
			for (int i = mid; i < List<T>::currentsize - 1; i++) {
				List<T>::arr[i] = List<T>::arr[i + 1];
			}
			List<T>::arr[List<T>::currentsize - 1] = first;
		}
	}

	void display() {
		cout << "\nList Display: " << endl;
		for (int i = 0; i < List<T>::currentsize; i++) {
			cout << List<T>::arr[i] << " ";
		}
	}
};

