#include <iostream>
#include <string>

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


int main() {

	int count_say;

	cout << "Enter the count and say number: ";
	cin >> count_say;

	string output = "1";

	while (count_say > 1) {
		output = countAndSay(output);
		count_say--;
	}

	cout << output << endl;



	return 0;
}