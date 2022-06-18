#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

struct qq{
    int a,b,c;
    bool operator<(const qq &x)const{
        return c<x.c;
    }
}q[10005];
int n,m,p[2005];
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) p[i]=i;
    int a,b,s=n;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q,q+m);
    REP(i,m){
        a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b){
            p[a]=b;
            if(--s==1) {cout<<q[i].c<<"\n";break;}
        }
    }
//    wait
    return 0;
}
