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
//#define line cout<<"-------------------------\n";

vector<int> mx,v;
int n,cnt=0;
void dfs(int x){
    if(x>n) return ++cnt,mx=max(mx,v),void();
    REP1(i,1,v.size()-1)
        if(x%(v[i-1]+v[i])==0){
            v.insert(v.begin()+i,x);
            dfs(x+1);
            v.erase(v.begin()+i);
        }
}
int main(){Rosario
    cin>>n;
    v.em(0),v.em(1);
    dfs(2);
    cout<<cnt<<"\n";
    for(auto &i:mx) cout<<i<<' ';
}
