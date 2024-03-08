//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

#define int ll
int t,n;
struct qwq{
    int sum,mx,id,cnt;
    vector<int> v;
    bool operator<(const qwq &x){
        if(sum != x.sum) return sum > x.sum;
        else if(mx!=x.mx) return mx>x.mx;
        else if(cnt!=x.cnt) return cnt>x.cnt;
        else return id < x.id;
    }
}a[2005];
void cmx(int &x,int y){if(x<y) x=y;}
signed main(){StarBurstStream
    cin>>t; int x;
    while(t--){
        cin>>n;
        REP(i,n){
            cin>>a[i].cnt;
            a[i].id = i;
            a[i].mx = a[i].sum=0;
            a[i].v.clear();
            REP(j,a[i].cnt) cin>>x,cmx(a[i].mx,x), a[i].sum += x, a[i].v.em(x);
        }
        sort(a,a+n);
        REP(i,n) REP(j,a[i].v.size()) cout<<a[i].v[j]<<" \n"[j==a[i].v.size()-1];
    }
}
