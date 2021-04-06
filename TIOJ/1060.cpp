#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define lb(x) (x&(-x)) 

map<ll,ll> f_,h_,g_;
ll g(ll x){
    if(g_.find(x)!=g_.end()) return g_[x];
    else{
        if(x<=2){
            g_[x]=x*x-1;
            return g_[x];
        }else return 2;
    }
}
ll h(ll x){
    if(x<2) return -1;
    if(h_.find(x)!=h_.end()) return h_[x];
    else{
        h_[x]=2+h(x-1)-h(x-2);
        return h_[x];
    } 
}
ll f(ll x){
    if(f_.find(x)!=f_.end()) return f_[x];
    ll tmp=h(x);
    if(x>tmp) return f(x-1)-h(x);
    if(x<tmp) return f(g(x))-g(x);
    return 1;
}
int main(){
    //oi;
    ll n;
    while(cin>>n) cout<<f(n)<<"\n";
//    system("pause");
    return 0;
}
