#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

int n;
double mx=0,g[100005],sum[100005],mi[100005];
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>sum[i];
    mi[n]=sum[n];
    for(int i=n-1;i>1;--i){
        mi[i]=min(sum[i],mi[i+1]);
        sum[i]+=sum[i+1];
        g[i]=(sum[i]-mi[i])/(double)(n-i);
        mx=max(mx,g[i]);
    }
    REP1(i,2,n-1) if(mx==g[i]) cout<<i-1<<'\n';
//    wait
    return 0;
}
