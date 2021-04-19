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

const int z=2e5;
bitset<z+5> v,cnt;
vector<int> p;
inline void pre(){
    REP1(i,2,z){
        if(!v[i]) p.em(i);
        for(int j:p){
            if(i*j>=z) break;
            v[i*j]=1;
            if(i%j==0) break;
        }
    }
}
int t,l,r,ans;
int main(){Rosario
    pre();
    cin>>t;
    while(t--){cnt.reset();
        cin>>l>>r; 
        for(int i:p){
            if(i>r) break;
            for(int j=(l-1)/i+1;j*i<=r;++j) cnt[i*j-l]=1;
            if(l<=i&&i<=r) cnt[i-l]=0;
        }
        for(r-=l,ans=l=0;l<=r;++l) if(!cnt[l]) ++ans;
        cout<<ans<<"\n";
    }
    return 0;
}
