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
 
ll n,sum,ans=-1e18,x;
int main(){Rosario
    cin>>n;
    REP1(i,1,n){
        cin>>x;
        sum+=x;
        ans=max(ans,sum);
        if(sum<0) sum=0;
    }
    cout<<ans;
    return 0;
}
