//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define int ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
pii operator+(const pii &a,const pii &b){return {a.F+b.F,a.S+b.S};}
pii operator-(const pii &a,const pii &b){return {a.F-b.F,a.S-b.S};}
int dot(pii a,pii b){return a.F*b.F+a.S*b.S;}
int cross(pii a,pii b){return a.F*b.S-a.S*b.F;}
int ori(pii a,pii b,pii c){
    int ret=cross(b-a,c-a);
    if(!ret) return 0;
    return ret>0?1:-1;
}
bool inside(pii a,pii b,pii c){
    if(cross(a-c,b-c)) return 0;
    //cout<<a.F<<' '<<a.S<<' '<<b.F<<' '<<b.S<<' '<<c.F<<' '<<c.S<<' '<<dot(a-c,b-c)<<endl;
    return dot(a-c,b-c)<=0;
}
bool intersect(pii p1,pii p2,pii p3,pii p4){
    int a123=ori(p1,p2,p3), a124=ori(p1,p2,p4), a341=ori(p3,p4,p1), a342=ori(p3,p4,p2);
    if(a123==0 && a124==0) return inside(p1,p2,p3)||inside(p1,p2,p4)||inside(p3,p4,p1)||inside(p3,p4,p2);
    return ((a123*a124<=0)&&(a341*a342<=0));
}
int t;
pii pt[4];
signed main(){Aincrad
    cin>>t;
    while(t--){
        REP(i,4) cin>>pt[i].F>>pt[i].S;
        cout<<(intersect(pt[0],pt[1],pt[2],pt[3])?"YES\n":"NO\n");
    }
    return 0;
}
