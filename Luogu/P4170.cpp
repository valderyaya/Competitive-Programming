//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int inf=1e9;
char s[55];
int f[55][55];
int main(){//Rosario
	scanf("%s",s+1);
	int n=strlen(s+1);
	REP1(i,1,n) f[i][i]=1;
	REP1(i,1,n) for(int j=i-1;j;--j){
		f[j][i]=inf;
		for(int k=j;k<i;++k) f[j][i]=min(f[j][i],f[j][k]+f[k+1][i]);
		if(s[i]==s[j]) --f[j][i];
	}
	printf("%d\n",f[1][n]);
	return 0;
}
