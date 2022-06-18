//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

ll n,m,x;
set<ll> s;
map<ll,ll> ma;
int main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>x,ma[x]++,s.insert(x);
    x=0;
    for(ll i:s){
        auto it=s.lower_bound(i+m);
        if(*it==i+m) x+=ma[*it]*ma[i];
    }cout<<x<<"\n";
//    system("pause");
    return 0;
}
