#include<bits/stdc++.h>
using namespace std;

// Symbols
string E = "E";
string E_PRIME = "E'";
string T = "T";
string T_PRIME = "T'";
string F = "F";
string id = "id";
string eps = "";

map<string, map<string, vector<string>>> table;

void fill_table() {
	table[E][id] = {E_PRIME, T};
	table[E]["("] = {E_PRIME, T};

	table[E_PRIME][id] = {eps};
	table[E_PRIME]["+"] = {E_PRIME, T, "+"};
	table[E_PRIME]["*"] = {eps};
	table[E_PRIME]["("] = {eps};
	table[E_PRIME][")"] = {eps};
	table[E_PRIME]["$"] = {eps};

	table[T][id] = {T_PRIME, F};
	table[T]["("] = {T_PRIME, F};

	table[T_PRIME][id] = {eps};
	table[T_PRIME]["+"] = {eps};
	table[T_PRIME][""] = {T_PRIME, F, ""};
	table[T_PRIME]["("] = {eps};
	table[T_PRIME][")"] = {eps};
	table[T_PRIME]["$"] = {eps};

	table[F][id] = {id};
	table[F]["("] = {")", E, "("};

	table[id][id] = {"pop"};
	table["+"]["+"] = {"pop"};
	table[""][""] = {"pop"};
	table["("]["("] = {"pop"};

	table[")"][")"] = {"pop"};

	table["$"]["$"] = {"acc"};
}

int len = 25;

void print(vector<string> st, vector<string> input, string msg) {
	string st1, inp;
	for (auto el : st) {
		st1 += el;
		st1 += " ";
	}
	for (int i = input.size() - 1; i >= 0; i--) {
		inp += input[i];
	}
	cout << setw(4) << left << " ";
	cout << setw(2 * len) << left << st1;
	cout << setw(len) << right << inp;
	cout << setw(4) << left << " ";
	cout << setw(10) << left << msg;
	cout << endl;
}

string stringify(char c) {
	string s;
	s.push_back(c);
	return s;
}

int main() {

	fill_table();

	cout << "Enter the string to be parsed : ";
	string temp;
	getline(cin, temp);
	cout << "\n";
	vector<string> input;
	stringstream ss;
	ss << temp;
	string word;
	while (ss >> word) input.push_back(word);
	input.push_back("$");
	reverse(input.begin(), input.end());

	vector<string> st;

	st.push_back("$");
	st.push_back(E);
	cout << setw(4) << left << " ";
	cout << setw(2 * len) << left << "STACK";
	cout << setw(len) << right << "INPUT";
	cout << setw(4) << left << " ";
	cout << setw(10) << left << "COMMENTS";
	cout << endl;

	string message = "";

	while (true) {

		while (st.back() == eps) st.pop_back();

		vector<string> old_st = st, old_input = input;

		string c_in = input.back();
		string c_st = st.back();

		message = "";

		if (table[c_st][c_in].size() == 0) {
			message = "ERROR";
			print(old_st, old_input, message);
			break;
		}

		string action = table[c_st][c_in][0];

		if (action == "acc") {
			message = "Accepted";
		} else if (action == "pop") {
			st.pop_back();
			input.pop_back();
		} else {
			st.pop_back();
			for (auto i : table[c_st][c_in]) st.push_back(i);
		}


		print(old_st, old_input, message);
		if (message == "Accepted") {
			break;
		}
	}

	cout << "\n\n";

	if (message != "Accepted") {
		cout << "Unsuccessful parsing\n";
	} else {
		cout << "Successful parsing\n";
	}

	cout << "\n\n";
}