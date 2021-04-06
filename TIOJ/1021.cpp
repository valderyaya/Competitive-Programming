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

int n,k;
ll dfs(int p,int now,int lst){
    ll res=0;
    if(now<k) res=0;
    else if(now==k) res=n%lst+1;
    else res=lst;
    if(!p)
        if(k) return res;
        else return 0;
    res+=(p-!k)*lst;
    return res+dfs(p/10,p%10,lst*10);
}
int main(){Rosario
    while(cin>>n>>k) cout<<dfs(n/10,n%10,1)<<"\n";
    return 0;
}
