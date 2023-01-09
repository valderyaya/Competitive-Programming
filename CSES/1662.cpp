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
 
ll n,sum,ans,x;
map<ll,int> mp;
int main(){Rosario
    cin>>n;
    mp[0]++;
    REP(i,n){
        cin>>x;
        sum=(sum+x)%n;
        if(sum<0) sum+=n;
        ans+=mp[sum];
        mp[sum]++;
    }
    cout<<ans;
    return 0;
}
