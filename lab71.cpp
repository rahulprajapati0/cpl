#include<bits/stdc++.h>
using namespace std;

// Q6 - Lab Exam
// S -> Aa | b
// A -> bdA' | A'
// A' -> epsilon | cA' | adA'

string str;
char ch;
int ptr = -1;

bool delimiter(char c) {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == 0;
}

void advance() {
	ptr++;
	ptr = min(ptr, (int)str.length());
}

vector<int> A_prime() {
	int isave = ptr;
	vector<int> match;
	match.push_back(ptr - 1);
	if (str[ptr] == 'c') {
		advance();
		vector<int> positions = A_prime();
		match.insert(match.end(), positions.begin(), positions.end());
	}
	ptr = isave;
	if (str[ptr] == 'a') {
		advance();
		if (str[ptr] == 'd') {
			advance();
			vector<int> positions = A_prime();
			match.insert(match.end(), positions.begin(), positions.end());
		}
	}
	return match;
}

vector<int> A() {
	vector<int> match;
	int isave = ptr;
	if (str[ptr] == 'b') {
		advance();
		if (str[ptr] == 'd') {
			advance();
			vector<int> positions = A_prime();
			match.insert(match.end(), positions.begin(), positions.end());
		}
	}
	ptr = isave;
	if (str[ptr] == 'e') {
		advance();
		vector<int> positions = A_prime();
		match.insert(match.end(), positions.begin(), positions.end());
	}
	return match;
}

bool S() {
	int isave = ptr;
	vector<int> a_poss = A();
	if (a_poss.size()) {
		for (auto poss : a_poss) {
			ptr = poss;
			advance();
			if (str[ptr] == 'a') {
				advance();
				if (delimiter(str[ptr]))
					return true;
			}
		}
	}
	ptr = isave;
	if (str[ptr] == 'b') {
		advance();
		if (delimiter(str[ptr]))
			return true;
	}
	return false;
}


int main() {
	cout << "\n";
	cout << "Enter the string to be parsed: ";
	getline(cin, str);
	ptr = -1;
	advance();
	if (S()) {
		cout << "Successful parsing\n";
	} else {
		cout << "Unsuccessful parsing\n";
	}
	cout << "\n";
	return 0;
}