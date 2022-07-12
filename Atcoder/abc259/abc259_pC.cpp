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

string a,b;
signed main(){StarBurstStream
    cin>>a>>b;
    int i=0,j=0;
    while(i<a.size()&&j<b.size()){
        int x=1,y=1;
        if(a[i]!=b[j]) break;
        while(i+x<a.size()&&a[i]==a[i+x]) ++x;
        while(j+y<b.size()&&b[j]==b[j+y]) ++y;
        //cout<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
        if(x==y||x<y&&x>1){
            i+=x;
            j+=y;
        }else break;
    }
    if(i>=a.size()&&j>=b.size()) cout<<"Yes";
    else cout<<"No";
}
