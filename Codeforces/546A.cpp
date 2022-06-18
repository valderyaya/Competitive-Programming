#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define SZ(x) (x).size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,x) for(int i=0;i<(x);i++)
int main(){
	int k, n, w,s=0;
	cin >> k >> n >> w;
	for (int i = 1; i <= w; i++){
		s += i*k;
	}
	cout << max(s - n,0) << endl;
	return 0;
}
