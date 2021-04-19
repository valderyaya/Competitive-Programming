//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int a,n,b,cnt=0;
stack<int> st;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>a>>b;
        bool ck=0;
        while(!st.empty()&&st.top()>=b){
            if(st.top()==b) ck=1;
            st.pop();
        }
        if(!ck) ++cnt;
        st.emplace(b);
    }
    cout<<cnt<<"\n";
    return 0;
}
