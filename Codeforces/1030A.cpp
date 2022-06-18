#include<iostream>
using namespace std;
int main() {
	int s=0,a, x[10000];
	cin >> a;
	for (int i = 0; i < a; i++)
		cin>>x[i];
	for (int i = 0; i < a; i++) {
		if (x[i] > s)
			s = x[i];
	}
	if (s == 1)
		cout << "HARD";
	else
		cout << "EASY";
	return 0;
}
