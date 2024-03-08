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


int t,n,a[25][25],mx;
vector<int> ans,now;
void dfs(int nw,int cnt){
    if(cnt==5){
        int cal=0;
        REP(i,5) REP(j,5){
            int c=1e9;
            for(int &k:now) c=min(c,(abs(k/5-i)+abs(k%5-j))*a[i][j]);
            cal+=c;
        }
        if(cal<mx){
            mx=cal;
            ans=now;
        }
        return;
    }
    if(nw>=25) return;
    for(int i=nw;i<25;++i){
        now.em(i);
        dfs(i+1,cnt+1);
        now.pop_back();
    }
}
signed main(){StarBurstStream
    cin>>t;
    while(t--){
        cin>>n; mx=1e9;
        memset(a,0,sizeof(a));
        for(int x,y,z,i=0;i<n;++i) cin>>x>>y>>z,a[x][y]=z;
        dfs(0,0);
        for(int i=0;i<5;++i) cout<<ans[i]<<" \n"[i==4];
    }
}
