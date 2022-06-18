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

int n,cnt[200005];
vector<int> v[200005];
bitset<200005> sq;
ll ans=0;
signed main(){valder
    cin>>n;
    for(int i=1;i*i<=n;++i) sq[i*i]=1;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;j+=i)
            v[j].push_back(i);
    for(int i=1;i<=n;++i)
        for(int j=v[i].size()-1;j>=0;--j)
            if(sq[v[i][j]]){
                cnt[i/v[i][j]]++;
                break;            
            }
    //for(int i=1;i<=n;++i) cout<<cnt[i]<<" \n"[i==n];
    for(int i=1;i<=n;++i) ans+=cnt[i]*cnt[i];
    cout<<ans<<endl;
}
