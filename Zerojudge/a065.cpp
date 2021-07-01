#include<iostream>
#include<cmath>
using namespace std;
int main() {
	char a[7];
	while (cin >> a) {
		for (int i = 0; i <= 5; i++) 
			cout << abs(a[i + 1] - a[i]);
		cout << endl;
	}
	return 0;
}
