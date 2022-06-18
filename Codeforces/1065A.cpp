#include<iostream>
using namespace std;
int main(){
	long long t, s, a, b, c;
	cin >> t;
	while (t--) {
		cin >> s >> a >> b >> c;
		cout << s / c + (s / c / a * b) << endl;
	}
	return 0;
}
