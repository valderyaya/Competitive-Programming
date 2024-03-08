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

int n,k,a[4000005];
deque<int> dq;
signed main(){StarBurstStream
    cin>>n>>k;
    REP1(i,1,n) cin>>a[i],a[i+n]=a[i];
    REP1(i,1,n+k-1){
        while(!dq.empty()&&a[i]>=a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty()&&i-dq.front()+1>k) dq.pop_front();
        if(i>=k) cout<<a[dq.front()]<<' ';
    }
}
