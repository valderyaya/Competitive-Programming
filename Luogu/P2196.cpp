#include<bits/stdc++.h>
#include<bits/extc++.h>
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

vector<int> ans,v[21];
int mx=0,n,a[21],m;
void dfs(int x,int sum,vector<int> q){
    if(sum>mx) mx=sum,ans=q;
    for(auto &i:v[x]) {
        q.em(i);
        dfs(i,sum+a[i],q);
        q.pop_back();
    }
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i];
    REP1(i,1,n-1){
        for(int j=i+1;j<=n;j++){
            cin>>m;
            if(m) v[i].em(j);
        }
    }
    vector<int> q;
    REP1(i,1,n) q.clear(),q.em(i),dfs(i,a[i],q);
    REP(i,ans.size()) cout<<ans[i]<<" \n"[i==ans.size()-1];
    cout<<mx<<"\n";
//    system("pause");
    return 0;
}
