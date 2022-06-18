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


int n,m,f[33000],val[65];
pii a[65];
bool on[65];
vector<int> v[65];
int main(){Rosario
    cin>>n>>m;
    for(int x,i=1;i<=m;++i){
        cin>>a[i].F>>a[i].S>>x;
        val[i]=a[i].F*a[i].S;
        if(x) v[x].em(i),on[i]=1;
    }
    REP1(i,1,m)
        for(int j=n;!on[i]&&j>=a[i].F;--j){
            f[j]=max(f[j],f[j-a[i].F]+val[i]);
            if(v[i].size()>0&&j>=a[i].F+a[v[i][0]].F) f[j]=max(f[j],f[j-a[i].F-a[v[i][0]].F]+val[i]+val[v[i][0]]);
            if(v[i].size()>1&&j>=a[i].F+a[v[i][1]].F) f[j]=max(f[j],f[j-a[i].F-a[v[i][1]].F]+val[i]+val[v[i][1]]);
            if(v[i].size()>1&&j>=a[i].F+a[v[i][0]].F+a[v[i][1]].F) f[j]=max(f[j],f[j-a[i].F-a[v[i][0]].F-a[v[i][1]].F]+val[i]+val[v[i][0]]+val[v[i][1]]);
        }
    cout<<f[n]<<"\n";
    return 0;
}
