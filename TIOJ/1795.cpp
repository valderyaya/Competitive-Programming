#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

struct qq{
    int a,b,c;
    bool operator<(const qq &x)const{
        return c<x.c;
    }
}q[300005];
int n,m,k,mx=0,mi=0,p[100005],pa[100005],a,b;
int fin1(int x){return x==p[x]?x:p[x]=fin1(p[x]);}
int fin2(int x){return x==pa[x]?x:pa[x]=fin2(pa[x]);}
int main(){Rosario
    cin>>n>>m>>k;
    REP1(i,1,n) p[i]=pa[i]=i;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q,q+m);
    REP(i,m){
        a=fin1(q[i].a),b=fin1(q[i].b);
        if(a!=b) p[a]=b,mi+=q[i].c;
    }
    for(int i=m-1;i>=0;i--){
        a=fin2(q[i].a),b=fin2(q[i].b);
        if(a!=b) pa[a]=b,mx+=q[i].c;
    }
    if(mi<=k&&k<=mx) cout<<"TAK\n";
    else cout<<"NIE\n";
//    system("pause");
    return 0;
}
