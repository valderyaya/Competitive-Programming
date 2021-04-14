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
#define lb(x) (x&-x)


const int z=1000005;
int a[z]={},n,tag[z],te=0,s;
void add(int x,int v){
    for(;x<z;x+=lb(x)){
        if(tag[x]!=te) a[x]=0;
        a[x]+=v, tag[x]=te;
    }
}
int getsum(int x){
    int res=0;
    for(;x;x-=lb(x)) if(tag[x]==te) res+=a[x];
    return res;
}
struct qq{
    int x,v;
    bool operator<(const qq &c){return x==c.x?v>c.v:x<c.x;}
}q[z];
int main(){Rosario
    while(cin>>n){ll sum=0;
        REP(i,n) cin>>q[i].x>>q[i].v,++q[i].v;
        sort(q,q+n);
        REP(i,n){
            sum+=i-getsum(q[i].v);
            add(q[i].v,1);
        }
        cout<<sum<<"\n";
        ++te;
    }
    return 0;
}
