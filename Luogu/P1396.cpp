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

int n,m,s,t,p[10005];
struct qq{
    int a,b,c;
    bool operator<(const qq &x)const{return c<x.c;}
}q[20005];
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
int main(){Rosario
    cin>>n>>m>>s>>t; int a,b;
    REP1(i,1,n) p[i]=i;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q,q+m);
    REP(i,m){
        a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b) p[a]=b;
        if(fin(s)==fin(t)){cout<<q[i].c<<"\n";break;}
    }
    return 0;
}
