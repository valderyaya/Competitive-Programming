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

int n,k,a[200005];
bool ck=1;
signed main(){valder
    cin>>n>>k;
    for(int i=1;i<=n;++i) {
        cin>>a[i];
        if(a[i]<a[i-1]) ck=0;
    }
    if(k==1||ck) return cout<<"Yes",0;
    for(int i=1;i<=k;++i){
        vector<int> v;
        for(int j=i;j<=n;j+=k) v.push_back(a[j]);
        sort(ALL(v));
        for(int j=i,l=0;j<=n;j+=k,++l) a[j]=v[l];
    }
    ck=1;
    for(int i=1;i<=n;++i) if(a[i]<a[i-1]){ck=0;break;}
    cout<<(ck?"Yes":"No");
}
