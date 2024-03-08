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
 
const int z=1e5+1;
int n,k,a[z],b[z];
signed main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0,x;i<n;++i) {
        REP(j,3) cin>>x,a[i]+=x;
        b[i]=a[i];
    }
    sort(b,b+n,greater<int>());
    REP(i,n){
        if(a[i]+300>=b[k-1]) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
