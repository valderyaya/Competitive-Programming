//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

int n,m,i,j,k,op;
map<int,int> mp[100001];
int main(){Rosario
    cin>>n>>m;
    while(m--){
        cin>>op>>i>>j;
        if(op==1){
            cin>>k;
            mp[i][j]=k;
        }else{
            cout<<mp[i][j]<<"\n";
        }
    }
    return 0;
}
