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

int n,l,r,h;
int main(){Rosario
    while(cin>>n,n){
        map<int,array<vector<int>,2>> m;
        multiset<int> s{0};
        vector<pii> ans;
        while(n--) cin>>l>>h>>r,m[l][0].em(h),m[r][1].em(h);
        for(auto &i:m){
            for(auto &j:i.S[0]) s.insert(j);
            for(auto &j:i.S[1]) s.erase(s.find(j));
            h=*--s.end();
            if(ans.empty()||ans.back().S!=h) ans.em(mkp(i.F,h));
        }
        REP(i,ans.size()) cout<<ans[i].F<<' '<<ans[i].S<<" \n"[i+1==ans.size()];
    }
//    system("pause");
    return 0;
}
