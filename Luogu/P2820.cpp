#include<bits/stdc++.h>
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

struct qq{
    int a,b,c;
    bool operator<(const qq &x)const{
        return c<x.c;
    }
}q[100005];
int p[105],ran[105],n,m,sum=0,sum2=0;
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
inline void un(int a,int b){
    if(ran[a]>ran[b]) p[b]=a;
    else{
        p[b]=a;
        if(ran[a]==ran[b]) ran[b]++;
    }
}
int main(){Rosario
    cin>>n>>m;
    REP1(i,1,n) p[i]=i;
    int a,b;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].c;
    sort(q,q+m);
    REP(i,m){
        sum+=q[i].c;
        a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b) un(a,b),sum2+=q[i].c;
    }cout<<sum-sum2<<"\n";
//    system("pause");
    return 0;
}
