#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int a, b;
	while (cin >> a >> b){
		cout << __gcd(a, b) << endl;
	}

	return 0;
}
