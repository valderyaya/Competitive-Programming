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


pair<string,string> s[105];
int n;
signed main(){valder
    cin>>n;
    for(int i=0;i<n;++i) cin>>s[i].F>>s[i].S;
    for(int i=0;i<n;++i){
        bool a=1,b=1;
        for(int j=0;j<n;++j){
            if(i==j) continue;
            if(s[i].F==s[j].F||s[i].F==s[j].S) a=0;
            if(s[i].S==s[j].F||s[i].S==s[j].S) b=0;
            if(a==0&&b==0) return cout<<"No",0;
        }
    }
    cout<<"Yes";
}
