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

const int z=5e6+5;
vector<int> p;
bitset<z> is;
vector<pii> v;
int main(){Rosario
    for(int i=2;i<z;++i){
        if(!is[i]){
            p.em(i);
            for(auto &j:p){
                if(i*j>=z) break;
                is[i*j]=1;
                if(i%j==0) break;
            }
        }
    }
    int q,n,mx;
    cin>>q;
    while(q--){v.clear();
        cin>>n; mx=0;
        if(n==1){cout<<"0\n";continue;}
        for(int i=0;p[i]*p[i]<=n;++i){
            if(n%p[i]==0){v.em(mkp(p[i],0));
                while(n%p[i]==0) v.back().S++,n/=p[i];
            }
        }
        if(n>1) v.em(mkp(n,1));
        for(auto &i:v){
            int cnt=0;
            while(i.S>0){
                cnt++; i.S--;
                int t=cnt;
                while(t%i.F==0) i.S--,t/=i.F;
            }
            mx=max(mx,cnt*i.F);
        }
        cout<<mx<<"\n";
    }
    return 0;
}
