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


int a[1000005],ans[1000005],pa[1000005],x,pri[1000005],n;
stack<int> st;
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>a[i],pri[a[i]]=i;
    pa[pri[1]]=0; st.emplace(pri[1]);
    REP1(i,2,n){
        if(pri[i]>st.top()){
            pa[pri[i]]=st.top(); st.emplace(pri[i]);
            continue;
        }
        while(!st.empty()&&st.top()>pri[i]) x=st.top(),st.pop();
        pa[pri[i]]= st.empty()?0:st.top();
        pa[x]=pri[i]; st.emplace(pri[i]);
    }
    REP1(i,1,n) ans[a[i]]=a[pa[i]];
    REP1(i,1,n) cout<<ans[i]<<'\n';
    return 0;
}
