//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

vector<int> p;
bitset<10005> vis;
int n,x;
int main(){Rosario
    for(int i=2;i<10000;++i){
        if(!vis[i]) p.em(i);
        for(auto &j:p){
            if(i*j>10000) break;
            vis[i*j]=1;
            if(i%j==0) break;
        }
    }
    cin>>n;
    while(n--){
        cin>>x;
        if(x<=1) cout<<"("<<x<<")";
        else{
            REP(i,p.size()){
                if(p[i]>x) break;
                int cnt=0;
                for(int j=x;j;cnt+=(j/=p[i]));
                if(i) cout<<'*';
                if(cnt==1) cout<<'('<<p[i]<<')';
                else cout<<'('<<p[i]<<'^'<<cnt<<')';
            }
        }
        cout<<"\n";
    }
    return 0;
}
