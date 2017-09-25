#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>

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
			if (v.size() == 0) 
				return true;
			return false;
		}

		int len() {
			return v.size();
		}
	
};


bool isOperand(char c) {
	if(c >= '0' && c <= '9') return true;
	if(c >= 'a' && c <= 'z') return true;
	if(c >= 'A' && c <= 'Z') return true;
	return false;
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}

	return false;
}

int getOperatorWeight(char op) {
	switch(op) {
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		
		default:
			return 0;
	}
}

bool hasHigherPrecedent(char a, char b) {
	int weigth1;
	int weight2;
	weigth1 = getOperatorWeight(a);
	weight2 = getOperatorWeight(b);

 	return weigth1>weight2 ? true: false;
}

string InfixToPostfix(string exp) {

	//cout << exp;
	string out = "";
	ArrayStack s;
	int n = exp.size();
	char temp;

	for (int i=0; i<n; i++) {
		if (isOperand(exp[i])) {
			out += exp[i];
		}
		else if (isOperator(exp[i])) {
			while (!s.is_empty() && s.top()!='(' && hasHigherPrecedent(s.top(), exp[i])) {
				temp = s.pop();
				out += temp;
			}
			s.push(exp[i]);
		}

		else if (exp[i] == '(') {
			s.push(exp[i]);
		}

		else if (exp[i] == ')') {
			while (s.top() != '(') {
				temp = s.pop();
				out += temp;
			}
			s.pop();
		}
	}

	while (!s.is_empty()) {
		out += s.pop();
	}

	return out;
}

int cti(char a) {
	int x = a - '0';
	return x;
}

int evaluatePostFixExpression(string exp) {
	ArrayStack s;
	int n = exp.size();
	int op1;
	int op2;
	int temp;
	for (int i=0; i<n; i++) {
		if (isOperand(exp[i])) {
			s.push(cti(exp[i]));
		}

		else if (isOperator(exp[i])) {
			op2 = s.pop();
			op1 = s.pop();

			//cout << op1 << " " << op2 << endl;
			switch(exp[i]) {
				case '+':
					temp = op1 + op2;
					break;
				case '-':
					temp = op1 - op2;
					break;
				case '*':
					temp = op1 * op2;
					break;
				case '/':
					temp = op1 / op2;
					break;
			}
			s.push(temp);
		} 
	}

	return s.pop();
}


int main() {

	for (int i=0; i<8; i++) {
		string myString;
		string post;
		string postfix;
		string p_spaces = "";
		int output;

		cout << "Enter the infix expression: ";
		getline(cin, myString);

		//cout << myString;

		postfix = InfixToPostfix(myString);
		int j;
		for (j=0; j<(postfix.size()-1); j++) {
			p_spaces += postfix[j];
			p_spaces += " ";
		}
		p_spaces += postfix[j];

		output = evaluatePostFixExpression(postfix);

		cout << p_spaces << ", " << output << endl; 
	}

	

	return 0;
}