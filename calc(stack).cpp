#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool is_operator(string &s,int i) {
	if (s[i] == '+' || s[i] == '*' || s[i] == '/') {
		return 1;
	}
	else if (s[i] == '-' && (s[i + 1] == ' ' || i == s.size() - 1)){
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	stack <int> a;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if ( s[i] != ' '){
			if (is_operator(s, i)) {
				if (a.size() < 2) {
					cout << "not enough arguments";
					return 0;
				}
				else {
					int x, y;
					x = a.top();
					a.pop();
					y = a.top();
					a.pop();
					if (s[i] == '+') {
						y = y + x;
					}
					else if (s[i] == '-' && (s[i + 1] == ' ' || i == s.size() - 1)) {
						y = y - x;
					}
					else if (s[i] == '*') {
						y = y * x;
					}
					else if (s[i] == '/') {
						if (x == 0) {
							cout << "Division by zero";
							return 0;
						}
						else {
							y = y / x;
						}
					}
					a.push(y);
				}
			}
			else {
				string t;
				int j = i;
				while (s[i] != ' '){
					i++;
				}
				t = s.substr(j, i);
				int p = stoi(t);
				a.push(p);
			}
		}
	}
	cout << a.top();
	return 0;
}
