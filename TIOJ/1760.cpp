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

int n,ans[300005];
struct qq{
    int x,y,id;
    bool operator<(const qq &a)const{return y==a.y?x>a.x:y<a.y;}
}q[300005];
set<int> s;
int main(){Rosario
    cin>>n;
    REP(i,n) cin>>q[i].x>>q[i].y,q[i].id=i;
    sort(q,q+n); int p=0,mx=-1;
    set<pii> s;
    for(int i=n-1;i>=0;--i){
        if(s.empty()){s.insert({q[i].x,i}),ans[q[i].id]=-1;continue;}
        for(auto it=s.rbegin();it!=s.rend();--it){
            if(it->F<=q[i].x) break;
            if(q[it->S].y>q[i].y){
                ans[q[i].id]=q[it->S].y;
                q[i].id=-1; s.insert({q[i].x,i});
                break;
            }
        }
        if(q[i].id!=-1) ans[q[i].id]=-1,s.insert({q[i].x,i});
    }
    //REP(i,n) cout<<q[i].x<<' '<<q[i].y<<' '<<q[i].id<<endl;
    REP(i,n) cout<<ans[i]<<" \n"[i==n-1];
    return 0;
}
