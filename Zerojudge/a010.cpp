#include<iostream>
using namespace std;
#define REP(i,x) for(int i=0;i<(x);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

int main(){
	int n;
	while (cin >> n){
		for (int i = 2; i <= n; ++i){
			int power = 0;
			while (!(n % i)){
				++power;
				n /= i;
			}
			if (power > 0){
				cout << i;
				if (power > 1) cout << '^' << power;
				if (n > 1) cout << " * ";
			}
			if (n < 2) break;
		}
		cout << endl;
	}

	return 0;
}
