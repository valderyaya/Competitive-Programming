//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair


int t,n,a[15],b[15];
vector<int> v;
bool f;
set<vector<int>> mp;
void dfs(int id,int sum){
    if(sum==t){
        if(mp.count(v)) return;
        mp.insert(v); f=0;
        for(int i=0;i<v.size();++i) cout<<v[i]<<"+\n"[i+1==v.size()];
    }
    if(sum>t||id>n||sum + b[n] - b[id-1] < t) return;
    for(;id<=n;++id){
        v.em(a[id]);
        dfs(id+1,sum+a[id]);
        v.pop_back();
    }
}
signed main(){StarBurstStream
    while(cin>>t>>n,n||t){
        REP1(i,1,n) cin>>a[i],b[i]=a[i]+b[i-1];
        sort(a+1,a+1+n,greater<int>());
        f=1; mp.clear();
        cout<<"Sums of "<<t<<":\n";
        dfs(1,0);
        if(f) cout<<"NONE\n";
    }
    return 0;
}
