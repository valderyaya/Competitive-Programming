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


int n,m,x=-1,y;
string s[105];
signed main(){valder
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            if(s[i][j]=='o'){
                if(x==-1) x=i,y=j;
                else return cout<<abs(x-i)+abs(y-j),0;
            }
        }
}
