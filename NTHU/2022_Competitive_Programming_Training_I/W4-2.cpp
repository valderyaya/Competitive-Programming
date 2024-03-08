#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
 
map<ll,int> mp;
ll ans,n,m,a[200005];
int main(){Rosario
    cin>>n>>m;
    mp[0]++;
    REP1(i,1,n){
        cin>>a[i],a[i]+=a[i-1];
        ans+=mp[a[i]-m];
        mp[a[i]]++;
    }
    cout<<ans<<"\n";
    return 0;
}
