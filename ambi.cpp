#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> productions;
map<string, int> op_level;
vector<set<string>> first, last;
map<pair<string, string>, vector<string> > table;

bool isTerminal(string s) {
	return !(s.size()>0 && s[0] >= 'A' && s[0] <= 'Z');
}

int main(){
    cout << "Enter the number of productions:\t";
	cin >> n;
	string temp;
	getline(cin, temp);
	productions.resize(n);

	cout << "Enter productions, one by one (with terminals, non-terminals,etc. separated by space) :\n";
	for (int i = 0; i < n; i++) {
		getline(cin, temp);
		stringstream ss;
		ss << temp;
		string word;
		while (ss >> word)
			productions[i].push_back(word);
	}
    
    int levels;
    cout<<"Enter levels of precedence: ";
    cin>>levels;

    for(int i=1; i<=levels; i++){
        cout<<"\nEnter level "<<i<<" operators separated by space (lower level is higher precedence): ";
        getline(cin, temp);
        stringstream ss;
		ss << temp;
		string word;
		while (ss >> word)
			op_level[word] = i;
    }
}