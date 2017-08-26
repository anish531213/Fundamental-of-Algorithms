#include <iostream>
#include <string>

using namespace std;


void bubbleSort(string array[], int size) {
	string temp;
	for (int i=size-1; i>=0; i--) {
		for (int j=i; j<size-1; j++) {
			if (array[j]>array[j+1]) {
				swap(array[j], array[j+1]);
			}
		}
	}
}

void printArray(string array[], int size, string statement) {
	cout << "\n**** " << statement << " ****" << endl;
	for (int i=0; i<size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {
	int size;
	cout << "How many names would you like to sort ?: ";
	cin >> size;
	string myArray[size];

	for (int i=0; i<size; i++) {
		cout << "Enter the name: ";
		cin >> myArray[i];
	}

	printArray(myArray, size, "Printing unsorted array");

	bubbleSort(myArray, size);

	printArray(myArray, size, "Printing sorted array");

}
