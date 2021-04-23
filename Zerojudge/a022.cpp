#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s,s2;
	while (cin >> s) {
		if (s.size() % 2) {
			s.erase( s.size()/ 2, 1);
		}
		s2 = s;
		reverse(s.begin(), s.end());
		if (s2 == s)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
