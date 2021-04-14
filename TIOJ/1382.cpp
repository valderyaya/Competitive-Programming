//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

int n,a[100005],b[100005];
int kth(int x){
    int res=0,cnt=0;
    for(int i=19;~i;--i){
        res+=(1<<i);
        if(res>=n||cnt+a[res]>=x) res-=(1<<i);
        else cnt+=a[res];
    }return ++res;
}
void add(int x,int v){for(;x<=n;x+=lb(x)) a[x]+=v;}
int main(){Rosario
    while(cin>>n){int now=1;
        REP1(i,1,n) cin>>b[i],a[i]=lb(i);
        for(int i=1;i<=n;i++){
            now=(now+b[i]-2)%(n-i+1)+1; //cout<<now<<endl;
            int x=kth(now); add(x,-1);
            cout<<x<<' ';
        }cout<<"\n";
    }
    return 0;
}
