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

int n;
string s[1001];
signed main(){StarBurstStream
    cin>>n;
    for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            int r=0, d=0, rd=0, ld=0;
            for(int k=0;k<6;++k){
                if(j+k<n&&s[i][j+k]=='#') ++r;
                if(i+k<n&&s[i+k][j]=='#') ++d;
                if(i+k<n&&j+k<n&&s[i+k][j+k]=='#') ++rd;
                if(i+k<n&&j-k>=0&&s[i+k][j-k]=='#') ++ld;
                if(r>=4&&j+5<n) return cout<<"Yes",0;
                if(d>=4&&i+5<n) return cout<<"Yes",0;
                if(rd>=4&&i+5<n&&j+5<n) return cout<<"Yes",0;
                if(ld>=4&&i+5<n&&j-5>=0) return cout<<"Yes",0;
            }
        }
    cout<<"No";
}
