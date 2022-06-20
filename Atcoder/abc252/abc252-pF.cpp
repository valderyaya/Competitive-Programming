#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"

priority_queue<ll,vector<ll>,greater<ll> > pq;
ll n,L,sum;
signed main(){valder
    cin>>n>>L;
    for(ll x,i=0;i<n;++i){
        cin>>x;
        sum+=x;
        pq.emplace(x);
    }
    if(sum!=L) pq.emplace(L-sum);
    sum=0;
    while(pq.size()!=1){
        ll x=pq.top(); pq.pop();
        ll y=pq.top(); pq.pop();
        sum+=(x+=y);
        pq.emplace(x);
    }
    cout<<sum;
}
