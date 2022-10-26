#include <bits/stdc++.h>
using namespace std;

/*
    In output:
    Unary Plus -> p
    Unary Minus -> m
*/
/*
    Grammar:
            E -> E + T | E - T | T
            T -> T * F | T / F | F
            F -> - F | + F | P
            P -> (E) | digit
            digit -> 0 | 1  ... | 9
*/

string input, output;
stringstream stream;
char lookahead;

void E();
void T();
void F();
void P();
void digit();
void display(char terminal);
void match(char terminal);

void E(){
  T();
  while (true) {
    if (lookahead == '+') {
        match('+');
        T();
        display('+');
    } else if (lookahead == '-') {
        match('-');
        T();
        display('-');
    } else {
       return;
    }
   }	
}

void T() {
  F();
  while (true) {
      if (lookahead == '*') {
          match('*');
          F();
          display('*');
      }
      else if (lookahead == '/') {
          match('/');
          F();
          display('/');
      }
      else {
          return;
      }
  }
}

string error_message(char ch){
  return "Syntax error near " + string(1, ch);
}

void F() {
  if(lookahead == '-') {
	  match('-');
	  F();
	  display('m');	  
  }else if (lookahead == '+') {
      match('+');
      F();
	  display('p');	  
  }else {
      P();
  }
}

void P() {
  if (isdigit(lookahead)) {
      digit();
  }else if (lookahead == '(') {
      match('(');
      E();
      match(')');
  }else {
      cout<<"Syntax error near " << string(1, lookahead);
      exit(0);
  }
}

void digit(){
  display(lookahead);
  match(lookahead);
}

void display(char terminal){
  output += terminal;
}

void match(char terminal){
  if (terminal == lookahead) {
    lookahead = stream.get();
  }else {
    cout<<"Syntax error near " << string(1, lookahead);
    exit(0);
  }
}

int main(){	
    while(true){
        output.clear();
        cout << "Enter input (infix string): ";
	    cin>>input;
	    stream = stringstream(input);
	    lookahead = stream.get();
	    E();
	    cout<<"\nPostfix: ";
	    cout<<output<<endl;
    }
	return 0;
}