#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
typedef long long ll;
using namespace std;
int main(){
	int n,a,b,s,t=1;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		s = 0;
		for (int i = a; i <=b; i++) {
			for (int j = 1; j <= sqrt(i); j++) {
				if (i == j * j)
					s+=i;
			}
		}
		cout << "Case " << t++ << ": " << s<<endl;
	}
	return 0;
}
