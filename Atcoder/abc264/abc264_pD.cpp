#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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



int ans,nxt[10],pos[26],bit[10];
string s,p="atcoder";
void add(int x){
    for(;x<10;x+=lb(x)) bit[x]++;
}
int qry(int x){
    int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
signed main(){StarBurstStream
    cin>>s;
    for(int i=p.size()-1;~i;--i){
        nxt[i]=pos[p[i]-'a'];
        pos[p[i]-'a']=i;
    }
    for(int i=0;i<s.size();++i){
        int x=pos[s[i]-'a']+1;
        pos[s[i]-'a']=nxt[i];
        ans+=qry(9)-qry(x);
        add(x);
    }
    cout<<ans;
}
