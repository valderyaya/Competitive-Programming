//#pragma GCC optimize("O2")
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

multiset<int> a,b;
int n,cnt;
signed main(){StarBurstStream
    cin>>n;
    for(int i=0,x;i<n;++i) cin>>x,a.insert(x);
    for(int i=0,x;i<n;++i) cin>>x,b.insert(x);
    while(!a.empty()){
        if(*a.rbegin()==*b.rbegin()){
            a.erase(a.find(*a.rbegin()));
            b.erase(b.find(*b.rbegin()));
        }else if(*a.rbegin()>*b.rbegin()){
            a.insert(*a.rbegin()/2);
            a.erase(a.find(*a.rbegin()));
            ++cnt;
        }else{
            int x=*b.rbegin();
            if(x&1) break;
            b.erase(b.find(x));
            b.insert(x/2);
            ++cnt;
        }
    }
    if(a.empty()) cout<<cnt;
    else cout<<-1;
}
