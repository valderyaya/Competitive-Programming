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


const int z=1e6+6;
vector<int> v[z];
ll d[z],ans[z],mx=0;
int a[z],c,n;
stack<int> st;
void dfs(int x,int p){
    int u=0,o=0; d[x]=1;
    for(auto &i:v[x]){
        if(i==p) continue;
        if(u==0) u=i;
        else o=i;
        dfs(i,x);
        d[x]+=d[i];
    }
    ans[x]+=(n-d[x])*(d[x]-1);
    if(v[x].size()==3) ans[x]+=d[u]*d[o];
    ans[x]+=n-1;
    ans[x]<<=1;
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n){
        cin>>a[i];
        while(!st.empty()&&a[st.top()]<a[i]){
            int x=st.top(); st.pop();
            if(st.empty()) v[i].em(x),v[x].em(i);
            else{
                int p=a[st.top()]>a[i]?i:st.top();
                v[p].em(x),v[x].em(p);
            }
        }
        st.emplace(i);
    }
    int x=st.top(); st.pop();
    while(!st.empty()){
        v[x].em(st.top());
        v[st.top()].em(x);
        x=st.top(); st.pop();
    }
    dfs(1,1);
    REP1(i,1,n) if(ans[i]>mx) mx=ans[i],c=i;
    cout<<mx<<' '<<c<<"\n";
    return 0;
}
