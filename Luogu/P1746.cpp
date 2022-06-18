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

string m[1001];
int n,a[1001][1001],dx[]={1,0,0,-1},dy[]={0,1,-1,0};
pii st,ed;
queue<pii> q;
int solve(){
    st.F--,st.S--;
    q.emplace(st); m[st.F][st.S]='.';
    while(!q.empty()){
        pii x=q.front();q.pop();
        REP(i,4){
            int xx=x.F+dx[i],yy=x.S+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=n||m[xx][yy]!='0') continue;
            m[xx][yy]='.',a[xx][yy]=a[x.F][x.S]+1; q.emplace(mkp(xx,yy));
        }
    }
    return a[ed.F-1][ed.S-1];
}
int main(){//Rosario
    cin>>n;
    REP(i,n) cin>>m[i];
    cin>>st.F>>st.S>>ed.F>>ed.S;
    cout<<solve()<<"\n";
    return 0;
}
