#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,s[50000], a=0, b=0, c=0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		if (!(s[i] % 3))
			a++;
		else if (s[i] % 3 == 1)
			b++;
		else
			c++;
	}
	cout << a << ' ' << b << ' ' << c;
}
