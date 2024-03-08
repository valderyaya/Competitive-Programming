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


priority_queue<int,vector<int>> mx;
priority_queue<int,vector<int>,greater<int>> mn;
int x,n;
signed main(){StarBurstStream
    cin>>n;
    while(n--){
        cin>>x;
        if(!mx.empty() && x > mx.top()) mn.emplace(x);
        else mx.emplace(x);
        while(mx.size()>mn.size()+1) mn.emplace(mx.top()), mx.pop();
        if(mn.size() > mx.size()) mx.emplace(mn.top()), mn.pop();
        cout<<mx.top()<<' ';
    }
}
