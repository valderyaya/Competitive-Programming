//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,x,a[10005];
void dfs(int l,int r){
    if(l>r) return;
    if(l==r) return cout<<a[l]<<' ',void();
    int id,mn=1e9;
    REP1(i,l,r) if(a[i]<mn) mn=a[i],id=i;
    cout<<a[id]<<' ';
    dfs(l,id-1),dfs(id+1,r);
}
int main(){Rosario
    while(cin>>n,n){
        REP(i,n) cin>>a[i];
        dfs(0,n-1); cout<<"\n";
    }
    return 0;
}
