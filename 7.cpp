#include<bits/stdc++.h>
using namespace std;

//Compiler Design Lab End Semester Exam
//Student Name: Akash Mahapatra
//Admission No.: 19JE0086

//Question - Recursive Descent Parsing
//Given Grammar
//S -> Aa | b
//A -> bdA' | eA'
//A' -> cA' | adA' | eps

string str;
int curr=-1;

bool isDelimiter(char ch){
	return ch==' '||ch=='\n'||ch=='\r'||ch=='\t'||ch==0;
}

void advance(){
	curr++;
	int len=str.length();
	if(curr>=len)
		curr=len;
}

vector<int> A_prime(){
	int i_old=curr;
	vector<int> match;
	match.push_back(curr-1);	
	if(str[curr]=='c'){
		advance();
		vector<int> a_prime_poss=A_prime();
		if(a_prime_poss.size()){
			for(auto poss: a_prime_poss){
			    curr=poss;	
			    match.push_back(curr);
			}
		}
	}

	curr=i_old;
	if(str[curr]=='a'){
		advance();
		if(str[curr]=='d'){
			advance();
			vector<int> a_prime_poss=A_prime();
			if(a_prime_poss.size()){
				for(auto poss: a_prime_poss){
				    curr=poss;						
				    match.push_back(curr);
				}
			}			
		}
	}

	return match;
}

vector<int> A(){
	vector<int> match;
	int i_old=curr;
	if(str[curr]=='b'){
		advance();
		if(str[curr]=='d'){
			advance();
			vector<int> a_prime_poss=A_prime();
			if(a_prime_poss.size()){
				for(auto poss: a_prime_poss){							
					curr=poss;			
					match.push_back(curr);
				}
			}
		}
	}

	curr=i_old;
	if(str[curr]=='e'){
		advance();
		vector<int> a_prime_poss=A_prime();
		if(a_prime_poss.size()){
			for(auto poss: a_prime_poss){
			    curr=poss;							
			    match.push_back(curr);
			}
		}
	}

	return match;
}

vector<int> S(){
	int i_old=curr;
	vector<int> a_poss=A();
	if(a_poss.size()){
		for(auto poss: a_poss){
			curr=poss;
			advance();
			if(str[curr]=='a'){
				advance();
				if(isDelimiter(str[curr]))
					return vector<int>(1, curr);
			}		
		}
	}
	curr=i_old;
	if(str[curr]=='b'){
		advance();
		if(isDelimiter(str[curr]))
			return vector<int>(1, curr);		
	}

	return vector<int>(0);
}

int main(){
	cout<<"Enter strings to be parsed. Enter -1 to end.\n";
    while(true){
		getline(cin, str);
        if(str=="-1")
            return 0;
        
		curr=-1;
		advance();
		cout<<(S().size()>0?"Success\n":"Unsuccessful\n");
	}
	return 0;
}
