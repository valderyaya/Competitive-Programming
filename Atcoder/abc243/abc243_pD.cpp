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


ll n,x,d;
string s;
vector<char> v;
signed main(){valder
    cin>>n>>x>>s;
    for(ll tmp=x;tmp;tmp>>=1) ++d;
    for(auto &i:s){
        if(i=='U') {
            if(d==1) continue;
            --d;
            if(!v.empty()&&v.back()!='U') v.pop_back();
            else v.em(i);
        }else{
            ++d;
            v.em(i);
        }
    }
    for(auto &i:v){
        if(i=='U') x>>=1;
        else if(i=='L') x<<=1;
        else x=x<<1|1;
    }
    cout<<x;
}
