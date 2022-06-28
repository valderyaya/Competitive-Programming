//#pragma GCC optimize("O2")
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

int n,m,a[10],mn=1e9;
signed main(){
    cin>>n;
    for(int i=1;i<10;++i){
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    m = n/mn;
    for(int i=1;i<=m;++i)
        for(int j=9;j;--j){
            if((m-i)*mn + a[j] <= n){
                cout<<j;
                n-=a[j];
                break;
            }
        }
}
