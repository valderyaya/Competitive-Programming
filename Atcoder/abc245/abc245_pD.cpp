#pragma GCC optimize("O2")
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

int n,m,k;
vector<int> a,b,c;
signed main(){valder
    cin>>n>>m; k=n+m+1;
    a.resize(n+1);
    b.resize(m+1);
    c.resize(k);
    ++n,++m;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<k;++i) cin>>c[i];
    reverse(ALL(a));
    reverse(ALL(c));
    for(int i=0;i<k-n+1;++i){
        //cout<<c[i]<<' '<<a[0]<<' '<<c[i]/a[0]<<endl;
        b[i]=c[i]/a[0];
        for(int j=i,l=0;l<n;++j,++l)
            c[j]-=b[i]*a[l];
    }
    for(int i=m-1;i>=0;--i) cout<<b[i]<<' ';
}
