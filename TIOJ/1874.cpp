#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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

vector<int> prime;
int vis[10000001]={};
inline int solve(int x){
    int i=vis[x],c=1,cnt;
    while(x!=1&&i){
        cnt=0;
        while(x%i==0) cnt++,x/=i;
        i=vis[x];c*=cnt+1;
    }
    return c;
}
int main(){Rosario
    for(int i=2;i<=10000000;i++){
        if(!vis[i]) vis[i]=i,prime.em(i);
        REP(j,prime.size()){
            if(i*prime[j]>10000000) break;
            vis[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    int n,m;
    cin>>n;
    while(n--) cin>>m,cout<<solve(m)<<"\n";
//    system("pause");
    return 0;
}
