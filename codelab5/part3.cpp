#include <iostream>
#include <string>
#include <cmath>

using namespace std;


char FindEquivalentChar(int a) {
	//cout << int(a)-64;
	return char(a+64);
}

string findEquivalentIndex(int col) {
	string index = "";
	int temp;
	while (col != 0) {
		temp = col % 26;
		index = FindEquivalentChar(temp) + index;
		col = floor(col/26);
	}
	return index;
}


int main() {
	int col;
	string str;

	for (int i=0; i<5; i++) {
		cout << "Enter the column Number to convert into Excel Index: ";
		cin >> col;

		str = findEquivalentIndex(col);

		cout << "The equicalent excel index is " << str << endl;

	}

	
	return 0;
}