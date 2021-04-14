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

const int inf=1e9,mm=-2147483648;
struct qq{
    int x,y;
    bool operator<(const qq &a)const{return x==a.x?y<a.y:x<a.x;}
}p[100005],q[100005];
int n,m,L,R;
int sol(qq *a,int x,int l,int r){
    if(l==r){
        REP(i,x) if(a[i].x<=l&&r<=a[i].y) return 1;
        return inf;
    }int cnt=0,i=0;
    sort(a,a+x);
    while(l<r){
        int mx=mm;
        while(i<x&&a[i].x<=l) mx=max(mx,a[i++].y);
        if(mx<=l) return inf;
        ++cnt; l=mx; 
    }
    return cnt;
}
int main(){Rosario
    while(cin>>n>>m){
        REP(i,n) cin>>p[i].x>>p[i].y;
        REP(i,m) cin>>q[i].x>>q[i].y;
        cin>>L>>R; int a=sol(p,n,L,R),b=sol(q,m,L,R);
        if(a==inf&&b==inf) cout<<"TIE\n";
        else if((a!=inf&&a<=b)||b==inf) cout<<"A WIN\n";
        else cout<<"B WIN\n";
    }
    return 0;
}
