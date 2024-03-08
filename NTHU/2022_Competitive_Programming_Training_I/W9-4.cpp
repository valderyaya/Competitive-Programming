#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
struct qwq{int x,y,c;}e[200005];
int n,m,pa[100005];
ll cs;
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void merge(int x,int y,int c){
    if(fin(x)==fin(y)) return;
    pa[fin(x)]=pa[fin(y)];
    cs+=c; --n;
}
signed main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) pa[i]=i;
    REP(i,m) cin>>e[i].x>>e[i].y>>e[i].c;
    sort(e,e+m,[&](qwq a,qwq b){return a.c<b.c;});
    REP(i,m){
        merge(e[i].x,e[i].y,e[i].c);
        if(n==1) break;
    }
    if(n==1) cout<<cs;
    else cout<<"IMPOSSIBLE\n";
}
