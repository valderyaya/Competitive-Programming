//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m;
string s;
map<string,set<int>> mp;
int main(){Rosario
    cin>>n;
    REP1(i,1,n){
        cin>>m;
        while(m--) cin>>s,mp[s].insert(i);
    }
    cin>>m;
    while(m--){
        cin>>s;
        for(auto &i:mp[s]) cout<<i<<' ';
        cout<<"\n";
    }
    return 0;
}
