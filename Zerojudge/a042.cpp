#include<iostream>
using namespace std;
int main() {
	int x;
	while (cin >> x) {
		if (x != 0)
			cout << x * x - x + 2<<endl;
		else
			cout << 1 << endl;
	}  
}
