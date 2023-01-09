#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
 
int n,ans,lst=-1;
pii a[200005];
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    sort(a,a+n,[&](pii x,pii y){return x.S!=y.S?x.S<y.S:x.F<y.F;});
    REP(i,n){
        while(i+1<n&&a[i].S==a[i+1].S) ++i;
        if(lst==-1||(a[lst].S<=a[i].F)) lst=i,++ans;
    }
    cout<<ans<<"\n";
    return 0;
}
