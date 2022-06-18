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

int n,k,a[100];
void dfs(int x){
    if(x>k){
        REP1(i,1,k) cout<<setw(3)<<a[i];
        cout<<"\n"; return;
    }
    for(int i=a[x-1]+1;i<=n;++i) a[x]=i,dfs(x+1);
}
int main(){//Rosario
    cin>>n>>k;
    dfs(1);
    return 0;
//    wait
}
