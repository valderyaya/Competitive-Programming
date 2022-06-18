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

stack<int> st;
priority_queue<int> del,ins;
int n,x;
int main(){Rosario
    cin>>n;
    while(n--){
        cin>>x;
        if(x==0) cin>>x,st.emplace(x),ins.emplace(x);
        else if(x==1&&!st.empty()) del.emplace(st.top()),st.pop();
        else if(x==2){
            while(!del.empty()&&del.top()==ins.top()) del.pop(),ins.pop();
            cout<<(ins.empty()?0:ins.top())<<"\n";
        }
    }
    return 0;
}
