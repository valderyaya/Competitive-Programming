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
//#define lb(x) (x&-x)

int n,qe[15],cnt=0;
bool ck(int r,int c){
    for(int i=1;i<r;++i){
        if(qe[i]==c) return 0;
        if(r-i==abs(qe[i]-c)) return 0;
    }
    return 1;
}
void dfs(int x){
    REP1(i,1,n){
        qe[x]=i;
        if(ck(x,i)){
            if(x==n){
                if(++cnt<=3) REP1(j,1,n) cout<<qe[j]<<" \n"[j==n];
                return;
            }
            dfs(x+1);
        }
        qe[x]=-1;
    }
}
int main(){//Rosario
    REP1(i,1,13) qe[i]=-1;
    cin>>n;
    dfs(1);
    cout<<cnt<<"\n";
    return 0;
}
