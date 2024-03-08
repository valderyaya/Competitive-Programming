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

priority_queue<int,vector<int>,greater<int>> pq;
queue<int> q;
int n,k,x;
signed main(){StarBurstStream
    cin>>n;
    while(n--){
        cin>>k;
        if(k==1) cin>>x,q.emplace(x);
        else if(k==2){
            if(!pq.empty()) cout<<pq.top()<<"\n",pq.pop();
            else cout<<q.front()<<'\n',q.pop();
        }else while(!q.empty()) pq.emplace(q.front()), q.pop();
    }
}
