#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int z=10000;
vector<pii> v[z+5],nv[z+5];
int n,l,r,t,d;
int main(){Rosario
    while(cin>>n,n){
        REP(i,n){
            cin>>l>>t>>r>>d;
            ++l,++t,++r,++d;
            v[t].em(mkp(l,1));
            v[t].em(mkp(r,-1));
            nv[d].em(mkp(l,1));
            nv[d].em(mkp(r,-1));
        }
        multiset<pii> s; ll sum=0;
        REP1(i,1,z){
            int now=0,ls=1;
            for(auto &j:nv[i]) s.erase(s.find(j));
            for(auto &j:v[i]) s.insert(j);
            for(auto &j:s){
                sum+=(1LL<<now)*(j.F-ls);
                now+=j.S; ls=j.F;
            }
            if(s.empty()) sum+=z;
            else sum+=z-prev(s.end())->F+1;
        } cout<<sum<<"\n";
        REP1(i,0,z) v[i].clear(),nv[i].clear();
    }
    return 0;
}
