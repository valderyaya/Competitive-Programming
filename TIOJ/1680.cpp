//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
 
int n,m,x,y,tmp[100005];
string s,ans="";
stack<int> st;
int main(){Rosario
    cin>>n>>m;
    REP(i,m) cin>>x,ans.push_back(x?'1':'0');
    REP(i,n){
        while(!st.empty()) st.pop();
        REP(i,m+1) cin>>tmp[i],st.emplace(tmp[i]);
        x=st.top(); st.pop();
        if(x>st.top()) s="1";
        else s="0";
        while(st.size()>1){
            y=st.top(); st.pop();
            if(abs(x-y)>st.top()) s="1"+s;
            else s="0"+s;
            x=y;
        }
        //cout<<s<<endl;
        if(s==ans){
            REP(i,m+1) cout<<tmp[i]<<' ';
            break;
        }
    }
    return 0;
}
