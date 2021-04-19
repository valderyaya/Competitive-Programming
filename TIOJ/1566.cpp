//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<ll,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll x,l=1,n,m,k;
deque<pii> mx,mi;
vector<pii> ans;
int main(){Rosario
    cin>>n>>m>>k;
    REP1(i,1,n){
        cin>>x;
        if(i>m) l++;
        if(mx.size() && mx.front().S+m<=i) mx.pop_front();
        if(mi.size() && mi.front().S+m<=i) mi.pop_front();
        while(mx.size() && mx.back().F<x)mx.pop_back();
        while(mi.size() && mi.back().F>x)mi.pop_back();
        mx.em(mkp(x,i)),mi.em(mkp(x,i));
        if(mx.front().F-mi.front().F==k&&i-l>=1) ans.em(mkp(l,i));
    }
    while(n- ++l>=1){
        while(mx.size()&&mx.front().S<l) mx.pop_front();
        while(mi.size()&&mi.front().S<l) mi.pop_front();
        if(mx.front().F-mi.front().F==k) ans.em(mkp(l,n));
    }cout<<ans.size()<<"\n";
    for(auto &i:ans) cout<<i.F<<' '<<i.S<<"\n";
//    system("pause");
    return 0;
}


// int power(int a,int n){
//     int ans=1;
//     for(;n;n>>=1,a*=a)
//         if(n&1)
//             ans*=a;
//     return ans;
// }

// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }
