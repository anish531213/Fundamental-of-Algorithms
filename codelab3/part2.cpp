#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


string countAndSay(string& s) {
	int temp = 0;
	string ans = "";
	char tempChar = s.at(0);
	int i;
	for (i=0; i<s.length(); i++) {
		if (s.at(i) == tempChar) {
			temp += 1;
		} else {
			ans += to_string(temp) + tempChar;
			tempChar = s.at(i);
			temp = 1;
		}
	}
	ans += to_string(temp) + tempChar;

	return ans;


}


// This function generates "n" random numbers in the range a-b, a inclusive b exclusive
vector<int> generateRandomNumber(int a, int b, int n) {
	vector<int> v;
	int random;
	int i = n;
	while (i > 0) {
		random = rand()%(b-a)+a;
		if(find(v.begin(), v.end(), random) != v.end()) {
	    	/* v contains random */
	    	continue;
		} else {
			/* v does not contain random */
			v.push_back(random);
		    i--;
		}
		
	}

	return v;
}

//This function generates count and say from 1 to n
vector<string> generateCountAndSay(int n) {
	vector<string> c;
	string out = "1";
	c.push_back(out);
	string temp;
	while (n > 1) {
		out = countAndSay(out);
		c.push_back(out);
		n--;
	}

	return c;
}

void printVector(vector<int> vec, int n) {
	for (int i=0; i<n; i++) {
		cout << vec.at(i) << " ";
	}
	cout << endl;
}

void printStrVector(vector<string> vec, int n) {
	for (int i=0; i<n; i++) {
		cout << vec.at(i) << " ";
	}
	cout << endl;
}

vector<string> countAndSayForRandomNumbers() {
	int n = 10;
	vector<int> randomNumbers;
	vector<string> countSay;
	vector<string> countAndSayRandom;
	string temp;
	int t;

	randomNumbers = generateRandomNumber(5, 15, n);

	countSay = generateCountAndSay(15);

	cout << "Random Numbers: " << endl;
	printVector(randomNumbers, 10);
	//printStrVector(countSay, 15);

	for (int i=0; i<10; i++) {
		t = randomNumbers.at(i);
		temp = countSay.at(t-1);
		countAndSayRandom.push_back(temp);
	}

	printStrVector(countAndSayRandom, 10);

	return countAndSayRandom;
}



int main() {
	// To generate new random everytime
	srand(time(NULL));

	vector<string> c_array;
	c_array = countAndSayForRandomNumbers();

	return 0;
}