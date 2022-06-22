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

#define int ll
const int z=200005;
vector<int> v[z];
map<int,int> mp;
int n,a[z];
ll ans;
signed main(){valder
    for(int i=1;i<=200000;++i)
        for(int j=i;j<=200000;j+=i)
            v[j].em(i);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(int i=1;i<=n;++i){
        for(int &j:v[a[i]]){
            ans+=mp[j]*mp[a[i]/j];
        }
    }
    cout<<ans;
}
