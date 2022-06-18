//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------------\n";

struct qq{
    int a,b;
    double c;
    bool operator<(const qq &x)const{return c<x.c;}
}q[250005];
int n,m,len=0,sum,pa[505];
pii p[505];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
int main(){Rosario
    cin>>n>>m;sum=m;
    REP(i,m) cin>>p[i].F>>p[i].S,pa[i]=i;
    REP(i,m) for(int j=i+1;j<m;j++) q[len++]=qq{i,j,sqrt((p[i].F-p[j].F)*(p[i].F-p[j].F)+(p[i].S-p[j].S)*(p[i].S-p[j].S))};
    sort(q,q+len);
    REP(i,len){
        int a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b){
            pa[a]=b;
            if(--sum==n){
                cout<<fixed<<setprecision(2)<<q[i].c<<"\n";
                break;
            }
        }
    }
//    system("pause");
    return 0;
}
