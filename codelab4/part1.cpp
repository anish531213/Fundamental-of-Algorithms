#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;


class ArrayStack
{
	private:
		vector<char> v;	

	public:
		void push(char x) {
			v.push_back(x);
		}

		char pop() {
			if (v.back() > -1) {
				char temp = v.back();
				v.pop_back();
				return temp;
			}
			else {
				return 'q';
			}
		}

		char top() {
			if (v.back() > -1)
				return v.back();
			else
				return 'q';
		}

		bool is_empty() {
			if (v.back() <= 0) 
				return true;
			return false;
		}

		int len() {
			return v.size();
		}
	
};


class ArrayQueue
{
	private:
		vector<char> queue;	

	public:
		void enqueue(char x) {
			queue.insert(queue.begin(), x);
		}

		char dequeue() {
			if (queue.back() > -1) {
				char temp = queue.back();
				queue.pop_back();
				return temp;
			}
			else {
				return 'q';
			}
		}

		char first() {
			if (queue.back() > -1)
				return queue.back();
			else
				return 'q';
		}

		bool is_empty() {
			if (queue.back() < 0) 
				return true;
			return false;
		}

		int len() {
			return queue.size();
		}
	
};

bool is_pallindrome() {

	string myString;
	ArrayStack myStack;

	cout << "Enter the string you want to check if pallindrome: ";
	getline(cin, myString);

	if (myString.size() == 0)
		return true;

	int i;
	int n = myString.size();
	for (i=0; i<n; i++) {
		if (isalpha(myString[i])) {
			myStack.push(myString[i]);
		}
	}

	for (i=0; i<n; i++) {
		if (isalpha(myString[i])) {
			if (tolower(myString[i]) != tolower(myStack.pop())) {
				return false;
			}
		}
	}

	return true;

}


int main() {

	string s = "My name";

	for (int i=0; i<10; i++) {
		bool check;
		check = is_pallindrome();
		if (check) {
			cout << "Given string is pallindrome" << endl;
		} else {
			cout << "Given string is not pallindrome" << endl;
		}
	}
	

	return 0;
}