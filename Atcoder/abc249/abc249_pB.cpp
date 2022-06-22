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
#define endl "\n"

string s;
bool up,low,ck[130];
signed main(){valder
    cin>>s;
    for(auto &i:s){
        if(isupper(i)) up=1;
        if(islower(i)) low=1;
        if(ck[i]) return cout<<"No",0;
        else ck[i]=1;
    }
    if(up&&low) cout<<"Yes";
    else cout<<"No";
}
