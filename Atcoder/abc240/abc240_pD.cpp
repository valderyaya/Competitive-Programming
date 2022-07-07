#pragma GCC optimize("O2")
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

int n;
vector<pii> v;
signed main(){StarBurstStream
    cin>>n;
    for(int x;n--;){
        cin>>x;
        if(v.empty()||v.back().F!=x) v.em(x,1);
        else if(v.back().F==x) v.em(x,v.back().S+1);
        if(v.back().F==v.back().S){
            int tmp=v.back().F;
            while(!v.empty() && v.back().F==tmp) v.pop_back();
        }
        cout<<v.size()<<"\n";
    }
}
