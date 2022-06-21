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

char mp[1000][1000];
int n,a,b;
signed main(){valder
    cin>>n>>a>>b;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            for(int k=0;k<a;++k){
                for(int l=0;l<b;++l)
                    mp[i*a+k][j*b+l]=((i+j)&1?'#':'.');
            }
        }
    for(int i=0;i<n*a;++i){
        for(int j=0;j<n*b;++j) cout<<mp[i][j];
        cout<<endl;
    }
}
