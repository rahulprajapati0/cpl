#include<bits/stdc++.h>
using namespace std;

// Number of states
int states = 10;

vector<pair<string, vector<string>>> grammar(4);
vector<string> id(4);
vector<map<string, string>> action(10);
vector<map<string, int>> goTo(10);


void fill_grammar() {
	grammar[0] = {"S'", {"S"}};
	grammar[1] = {"S", {"C", "C"}};
	grammar[2] = {"C", {"c", "C"}};
	grammar[3] = {"C", {"d"}};
}


void fill_action() {
	action[0]["c"] = "s3";
	action[0]["d"] = "s4";
	action[1]["$"] = "acc";
	action[2]["c"] = "s6";
	action[2]["d"] = "s7";
	action[3]["c"] = "s3";
	action[3]["d"] = "s4";
	action[4]["c"] = "r3";
	action[4]["d"] = "r3";
	action[5]["$"] = "r1";
	action[6]["c"] = "s6";
	action[6]["d"] = "s7";
	action[7]["$"] = "r3";
	action[8]["c"] = "r2";
	action[8]["d"] = "r2";
	action[9]["$"] = "r2";
}

void fill_goto() {
	goTo[0]["S"] = 1;
	goTo[0]["C"] = 2;
	goTo[2]["C"] = 5;
	goTo[3]["C"] = 8;
	goTo[6]["C"] = 9;
}

void fill_table() {
	fill_action();
	fill_goto();
}


int len = 0;

void print(vector<string> st, string input, string msg) {
	string st1, inp;
	for (auto el : st) {
		st1 += el;
		st1 += " ";
	}
	for (int i = input.size() - 1; i >= 0; i--) {
		inp += input[i];
	}
	cout << setw(4) << left << " ";
	cout << setw(4 * len) << left << st1;
	cout << setw(len) << right << inp;
	cout << setw(4) << left << " ";
	cout << setw(10) << left << msg;
	cout << endl;
}

string stringify(string s) {
	return s;
}

string stringify(char c) {
	string s;
	s.push_back(c);
	return s;
}

string stringify(int n) {
	char c = n + '0';
	return stringify(c);
}


int main() {
	fill_grammar();
	fill_table();

	string input;
	cin >> input;
	len = input.size() + 5;
	input += "$";
	reverse(input.begin(), input.end());

	vector<string> stck;
	stck.push_back("0");

	cout << setw(4) << left << " ";
	cout << setw(4 * len) << left << "STACK";
	cout << setw(len) << right << "INPUT";
	cout << setw(4) << left << " ";
	cout << setw(10) << left << "ACTION";
	cout << endl;

	string message = "";

	while (true) {
		int c_state = stck.back()[0] - '0';
		string c_symbol;
		c_symbol.push_back(input.back());

		vector<string> old_stck = stck;
		string old_input = input;

		message = "";

		if (action[c_state].find(c_symbol) == action[c_state].end()) {
			message = "Error";
			print(old_stck, input, message);
			break;
		}

		string act = action[c_state][c_symbol];
		if (act == "acc") {
			message = "Accepted";
			print(old_stck, input, message);
			break;
		}

		message = act;

		if (act[0] == 's') {
			stck.push_back(stringify(input.back()));
			stck.push_back(stringify(act[1]));
			input.pop_back();
		} else {
			assert(act[0] == 'r');
			int num = act[1] - '0';
			int len = grammar[num].second.size();
			len *= 2;
			if (stck.size() < len ) {
				print(stck, input, "");
				// cout << c_state << " " << c_symbol << " " << act << " " << len << " " << stck.size();
				break;
			}
			while (len--) stck.pop_back();

			int state = stck.back()[0] - '0';
			stck.push_back(stringify(grammar[num].first));
			stck.push_back(stringify(goTo[state][stck.back()]));
		}

		print(old_stck, old_input, message);
	}

	cout << "\n\n";

	if (message == "Accepted") {
		cout << "Successful parsing\n";
	} else {
		cout << "Unsuccessful parsing\n";
	}

	cout << "\n\n";
}