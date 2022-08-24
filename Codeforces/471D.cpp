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
#define em emplace_back

int n,m,a[200005],b[200005],ans,f[200005];
signed main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>a[i];
    REP(i,m) cin>>b[i];
    for(int i=n-1;i;--i) a[i]=a[i]-a[i-1];
    for(int i=m-1;i;--i) b[i]=b[i]-b[i-1];
    for(int i=0;i<n-1;++i) a[i]=a[i+1];
    for(int i=0;i<m-1;++i) b[i]=b[i+1];
    --m; --n;
    if(m==0) return cout<<n+1<<"\n",0;
    if(n==0) return cout<<"0\n",0;
    for(int i=1;i<m;++i){
        int j=f[i-1];
        while(j&&b[i]!=b[j]) j=f[j-1];
        if(b[i]==b[j]) ++j;
        f[i]=j;
    }
    for(int i=0,j=0;i<n;++i){
        while(j&&a[i]!=b[j])j=f[j-1];
        if(a[i]==b[j]) ++j;
        if(j==m) ++ans,j=f[j-1];
    }
    cout<<ans<<"\n";
    return 0;
}
