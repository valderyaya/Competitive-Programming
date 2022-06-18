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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

map<tuple<ll,ll,ll>,ll> m;
ll a,b,c,ans;
ll w(ll x,ll y,ll z){
    auto it=m.find({x,y,z});
    if(it!=m.end()&&it->S) return m[{x,y,z}];
    if(x<=0 || y<=0 || z<=0) return 1;
    if(x>20 || y>20 || z>20)  return m[{20,20,20}]=w(20,20,20);
    if(x<y&&y<z){
        m[{x,y,z-1}]=w(x,y,z-1);
        m[{x,y-1,z-1}]=w(x,y-1,z-1);
        m[{x,y-1,z}]=w(x,y-1,z);
        return m[{x,y,z-1}]+m[{x,y-1,z-1}]-m[{x,y-1,z}];
    }
    m[{x-1,y,z}]=w(x-1,y,z);
    m[{x-1,y-1,z}]=w(x-1,y-1,z);
    m[{x-1,y,z-1}]=w(x-1,y,z-1);
    m[{x-1,y-1,z-1}]=w(x-1,y-1,z-1);
    //cout<<m[{x-1,y,z}]<<' '<<m[{x-1,y-1,z}]<<' '<<m[{x-1,y,z-1}]<<' '<<m[{x-1,y-1,z-1}]<<endl;
    return m[{x-1,y,z}]+m[{x-1,y-1,z}]+m[{x-1,y,z-1}]-m[{x-1,y-1,z-1}];
}
int main(){
    //oi;
    while(scanf("%lld %lld %lld",&a,&b,&c)){
        if(a==-1&&b==-1&&c==-1) break;
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
    }
//    system("pause");
    return 0;
}
