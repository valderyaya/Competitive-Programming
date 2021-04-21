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
#define wait system("pause");

unsigned long long int n,m,x,mn,t;
set<unsigned long long int > s;
bool dfs(unsigned long long int  x,unsigned long long int  cnt){
    if(cnt>n) return 1;
    if(s.count(x)) return dfs(x<<1,cnt+1)&&dfs(x<<1|1,cnt+1);
    else return 0;
}
int main(){Rosario
    cin>>t;
    while(t--){s.clear();
        cin>>n>>mn; m=(1<<(n+1))-1; s.insert(mn);
        REP1(i,1,m-1) cin>>x,s.insert(x),mn=min(mn,x);
        cout<<(dfs(mn,0)?"dodge\n":"do not dodge\n");
    }
//    system("pause");
    return 0;
}
