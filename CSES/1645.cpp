//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
 
int n,a[200005],l[200005];
signed main(){StarBurstStream
    cin>>n;
    REP1(i,1,n){
        cin>>a[i];
        if(a[i]>a[i-1]) l[i]=i-1;
        else {
            l[i] = l[i-1];
            while(a[i]<=a[l[i]]) l[i]=l[l[i]];
        }
        cout<<l[i]<<' ';
    }
}
