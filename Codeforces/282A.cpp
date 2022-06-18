#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define SZ(x) (x).size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,x) for(int i=0;i<(x);i++)
int main(){
	int a;
	char n[5];
	while (cin >> a){
		int x = 0;
		REP(i, a){
			cin >> n;
			if (n[0] == '+' || n[2] == '+') x++;
			else if (n[0] == '-' || n[2] == '-') x--;
		}
		cout << x << endl;
	}
	return 0;
}
