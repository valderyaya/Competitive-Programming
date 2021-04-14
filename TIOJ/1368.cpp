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

#define int ll
int n,a[100005],sum[100005],l[100005],r[100005];
stack<int> st;
 main(){Rosario
    while(cin>>n){while(!st.empty()) st.pop();
        REP1(i,1,n) cin>>a[i],sum[i]=sum[i-1]+a[i];
        REP1(i,1,n){
            while(!st.empty()&&a[st.top()]>a[i]) r[st.top()]=i-1,st.pop();
            st.emplace(i);
        }
        while(!st.empty()) r[st.top()]=n,st.pop();
        for(int i=n;i>0;--i){
            while(!st.empty()&&a[st.top()]>a[i]) l[st.top()]=i,st.pop();
            st.emplace(i);
        }
        while(!st.empty()) l[st.top()]=0,st.pop();
        int mx=0,x; pii ans;
        REP1(i,1,n){
            x=a[i]*(sum[r[i]]-sum[l[i]]);
            if(x>mx) ans={l[i],r[i]},mx=x;
        }cout<<mx<<"\n"<<ans.F+1<<' '<<ans.S<<"\n";
    }
    return 0;
}
