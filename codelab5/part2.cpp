#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int findCharOrder(char a) {
	//cout << int(a)-64;
	return int(a)-64;
}


int excelIndexToColumnNumber(string s1) {
	int number=0;
	int order;
	for (int i=s1.length()-1; i>=0; i--) {
		order = s1.length()-i-1;
		number += pow(26, order)*findCharOrder(s1[i]);
	}

	return number;
}


int main() {

	string str;

	for (int i=0; i<5; i++) {

		cout << "Enter the excel Index to find equivalent column number: ";
		cin >> str;

		int col = excelIndexToColumnNumber(str);

		cout << "The equicalent column number is " << col << endl;

	}


	return 0;
}