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

int n,a[200005],cnt[200005];
ll s;
signed main(){valder
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=200000;++i) cnt[i]+=cnt[i-1];
    for(int i=1;i<=n;++i)
        s+=(ll)cnt[a[i]-1]*(n-cnt[a[i]]);
    cout<<s<<endl;
}
