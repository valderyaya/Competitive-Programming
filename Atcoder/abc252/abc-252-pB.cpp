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

int mx,n,k;
vector<int> v;
signed main(){valder
    cin>>n>>k;
    for(int x,i=1;i<=n;++i){
        cin>>x;
        if(x>mx){
            mx=x;
            v.clear();
            v.em(i);
        }else if(x==mx) v.em(i);
    }
    for(int x,i=1;i<=k;++i){
        cin>>x;
        for(auto &j:v) if(x==j) return cout<<"Yes",0;
    }
    cout<<"No";
}
