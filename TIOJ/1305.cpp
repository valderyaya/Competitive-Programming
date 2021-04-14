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
#define lb(x) (x&-x)

const int z=1e5+5;
string s[100005];
int n,a[z],b[z],c[z],cnt=0;
bool on[z]={};
void add(int x,int v){for(;x<=n;x+=lb(x)) b[x]+=v;}
int kth(int x){
    int res=0,cnt=0;
    for(int i=19;~i;--i){
        res+=(1<<i);
        if(res>n||cnt+b[res]>=x) res-=(1<<i);
        else cnt+=b[res];
    }return ++res;
}
int main(){Rosario
    while(cin>>s[++n],s[n]!="exit") cin>>a[n],c[n]=a[n];
    --n;sort(c+1,c+n+1);
    int len=unique(c+1,c+1+n)-c-1;
    REP1(i,1,n){
        if(s[i][0]=='a'){
            if(a[i]>cnt||a[i]<1) cout<<"error\n";
            else cout<<c[kth(a[i])]<<"\n";
            continue;
        }
        int x=lower_bound(c+1,c+1+len,a[i])-c;
        if(s[i][0]=='i'&&on[x]==0) on[x]=1,add(x,1),cnt++;
        else if(s[i][0]=='r'&&on[x]) on[x]=0,add(x,-1),cnt--;
    }
    return 0;
}
