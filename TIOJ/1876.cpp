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


const int z=1e6+5;
pll operator+(pll a,pll b){return mkp(a.F+b.F,a.S+b.S);}
pll operator-(pll a,pll b){return mkp(a.F-b.F,a.S-b.S);}
pll operator*(pll a,int n){return mkp(a.F*n,a.S*n);}
pll operator/(pll a,int n){return mkp(a.F/n,a.S/n);}
ll dot(pll a,pll b){return a.F*b.F+a.S*b.S;}
ll cross(pll a,pll b){return a.F*b.S-a.S*b.F;}
bool gx(pll a,pll b,pll c){return cross(a-c,b-c)==0;}
int ori(pll a,pll b,pll c){
    double res=cross(b-a,c-a);
    if(res==0) return 0;
    return res>0?1:-1;
}
bool online(pll a,pll b,pll c){
    if(!gx(a,b,c)) return 0;
    return dot(a-c,b-c)<0;
}
ll n,cntA,cntB,xj,mnx=1e9;
pll pt[z],op[2],mn,mn2;
bool inter2(pll a,pll b,pll c,pll d){
    if(online(a,b,c)||online(a,b,d)) return 0;
    int x=ori(a,b,c),y=ori(a,b,d),u=ori(c,d,a),o=ori(c,d,b);
    if(!(x|y)) return (gx(a,b,c)||gx(a,b,d)||gx(c,d,a)||gx(c,d,b));
    if(x*y<=0&&o*u<=0) return 1;
    return 0;
}
void ck1(ll &o,pll &x,pll &y,pll &z){
    if(!~o||y.S-z.S==0) return;
    if(online(x,y,z)) return o=-1,void();
    if(online(x,mn,y))
        if(y.S>z.S) ++o;
    if(online(x,mn,z))
        if(z.S>y.S) ++o;
    if(inter2(x,mn,y,z)) ++o;
}
void ck2(ll &o,pll &x,pll &y,pll &z){
    if(!~o||y.S-z.S==0) return;
    if(online(x,y,z)) return o=-1,void();
    if(online(x,mn2,y))
        if(y.S>z.S) ++o;
    if(online(x,mn2,z))
        if(z.S>y.S) ++o;
    if(inter2(x,mn2,y,z)) ++o;
}
void solve(){
    mn=mkp(mnx-10,op[0].S);
    mn2=mkp(mnx-10,op[1].S);
    REP(i,n){
        ck1(cntA,op[0],pt[i],pt[i+1]);
        ck2(cntB,op[1],pt[i],pt[i+1]);
        if(i!=n-1) 
            if(inter2(op[0],op[1],pt[i],pt[i+1])) xj=1;
    }
    if(cntA==-1) cntA=1;
    if(cntB==-1) cntB=1;
    if((cntB%2==0)&&(cntA%2==0)) cout<<"ERROR!\n";
    else if(cntA%2==0) cout<<"A troll!";
    else if(cntB%2==0) cout<<"B troll!";
    else if(xj) cout<<"Bug!";
    else cout<<"Okay!";
}
main(){Rosario
    cin>>n;
    REP(i,n) cin>>pt[i].F>>pt[i].S,mnx=min(mnx,pt[i].F);
    pt[n]=pt[0]; cin>>op[0].F>>op[0].S>>op[1].F>>op[1].S;
    solve();
    return 0;
}
