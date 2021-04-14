#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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

const int z=100000;
int n,l,r,t,d;
vector<int> v[z+5],m[z+5];
int main(){Rosario
    while(cin>>n){bool ck=1;
        REP1(i,1,n) v[i].clear(),m[i].clear();
        REP(i,n) cin>>l>>r>>t>>d,v[l].em(r),m[t].em(d);
        priority_queue<int,vector<int>,greater<int>> q;
        REP1(i,1,z){
            for(auto &j:v[i]) q.push(j);
            if(!q.empty()){
                if(q.top()<i){ck=0;break;}
                else q.pop();
            }
        }
        if(ck){
            REP1(i,1,z){
                for(auto &j:m[i]) q.push(j);
                if(!q.empty()){
                    if(q.top()<i){ck=0;break;}
                    else q.pop();
                }
            }
        }
        cout<<(ck?"YES":"NO")<<"\n";
    }
    return 0;
}
