//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

int n,t,a[1001];
int cal(int x){return (x>1?abs(a[x]-a[x-1]):0)+(x<n?abs(a[x]-a[x+1]):0);}
int main(){Rosario
    cin>>t;
	while(t--){
		cin>>n;
		REP1(i,1,n) cin>>a[i];
		REP1(i,1,n){
			pii ans={0,i};
			REP1(j,1,n){
				if(i==j) continue;
				pii x={-cal(i)-cal(j),j};
				swap(a[i],a[j]);
				x.F+=cal(i)+cal(j);
				ans=min(ans,x);
				swap(a[i],a[j]);
			}cout<<ans.S<<' ';
		}cout<<"\n";
	}
    return 0;
}
