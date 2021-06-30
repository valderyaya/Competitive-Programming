//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

ll n,cnt=0;
vector<ll> v;
queue<ll> q;
int main(){//Rosario
    cin>>n;
    v.resize(n);
    REP(i,n) cin>>v[i];
    sort(ALL(v));
    while(!q.empty() || !v.empty()){
        ll mx=0;
        if(!q.empty()) mx=q.front();
        if(!v.empty()) mx=max(v.back(),mx);
        if(mx/2) q.emplace(mx/2);
        ++cnt;
        while(!q.empty()&&q.front()==mx) q.pop();
        while(!v.empty()&&v.back()==mx) v.pop_back();
    }
    cout<<cnt-1;
    return 0;
}
