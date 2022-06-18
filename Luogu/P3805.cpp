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
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

char ch[22200005];
int p[22200005],idx=0,ans=0;
void read(){
    char c=getchar(); ch[0]='.',ch[++idx]='|';
    while(c<'a'||c>'z') c=getchar();
    while(c>='a'&&c<='z') ch[++idx]=c,ch[++idx]='|',c=getchar();
}
int main(){
    read();
    for(int i=1,r=0,mid=0;i<=idx;++i){
        if(i<=r) p[i]=min(p[(mid<<1)-i],r-i+1);
        while(ch[i-p[i]]==ch[i+p[i]]) ++p[i];
        if(p[i]+i>r) r=p[i]+i-1,mid=i;
        ans=max(ans,p[i]);
    }
    //REP1(i,1,idx) cout<<ch[i]<<" \n"[i==idx];
    //REP1(i,1,idx) cout<<p[i]<<" \n"[i==idx];
    printf("%d\n",ans-1);
    return 0;
}
