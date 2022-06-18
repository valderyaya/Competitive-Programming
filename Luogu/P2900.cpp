//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)
#define line cout<<"-------------------------------\n";

struct qq{ll h,w;
    bool operator<(const qq &x)const{
        return w==x.w?h<x.h:w<x.w;
    }
}q[50005],st[50005];
ll n,dp[50005]={},idx=0,qe[50005];
ll cal(int x,int y){return dp[y]+st[x].w*st[y+1].h;}
double slope(int i,int j){return 1.*(dp[i]-dp[j])/(-st[i+1].h+st[j+1].h);}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>q[i].w>>q[i].h,dp[i]=1e9;
    sort(q+1,q+1+n);
    REP1(i,1,n){
        while(idx&&st[idx].h<=q[i].h) idx--;
        st[++idx]=q[i];
    }
    n=idx;
    int l=1,r=0;
    qe[++r]=0;
    REP1(i,1,n){
        while(l<r&&slope(qe[l],qe[l+1])<=st[i].w) l++;
        dp[i]=cal(i,qe[l]);
        while(l<r&&slope(qe[r-1],qe[r])>=slope(qe[r],i)) r--;
        qe[++r]=i;
    }cout<<dp[n]<<"\n";
//    system("pause");
    return 0;
}
