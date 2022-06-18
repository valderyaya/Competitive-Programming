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


int n,x,a[4],p;
signed main(){valder
    cin>>n;
    while(n--){
        cin>>x;
        a[0]=1;
        for(int i=3;i>=0;--i)
            if(a[i]){
                if(i+x>3) ++p,a[i]=0;
                else a[i+x]=1,a[i]=0;
            }
    }
    cout<<p;
}
