//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int z=200005;
int mn[z],mx[z],n,m,f[z];
deque<int> dq;
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n+1) mn[i]=i;
    for(int x,y;m;--m){
        cin>>x>>y;
        mn[y]=min(mn[y],x);
        mx[y+1]=max(mx[y+1],x);
    }
    for(int i=n;i;--i) mn[i]=min(mn[i],mn[i+1]);
    REP1(i,1,n+1) mx[i]=max(mx[i],mx[i-1]);
    dq.pb(0);
    for(int i=1,j=1;i<=n+1;++i){
        for(;j<mn[i];++j) if(f[j]!=-1){
            while(!dq.empty()&&f[dq.back()]<f[j]) dq.pop_back();
            dq.pb(j);
        }
        while(!dq.empty()&&dq.front()<mx[i]) dq.pop_front();
        if(dq.empty()) f[i]=-1;
        else f[i]=f[dq.front()]+(i!=n+1);
    }cout<<f[n+1];
    return 0;
}
