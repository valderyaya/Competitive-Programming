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
#define wait system("pause");

struct qq{
    int x,y,z;
    bool operator<(const qq &a)const{return z>a.z;}
}q[1000005];
int t,n,cnt,fa[1000005],num[2000005];
int fin(int x){return fa[x]==x?x:fa[x]=fin(fa[x]);}
int main(){Rosario
    cin>>t;
    while(t--){
        cin>>n; cnt=0;
        REP1(i,1,n) cin>>q[i].x>>q[i].y>>q[i].z,num[++cnt]=q[i].x,num[++cnt]=q[i].y;
        sort(num+1,num+1+cnt);
        int len=unique(num+1,num+1+cnt)-num-1;
        sort(q+1,q+1+n);
        REP1(i,1,len) fa[i]=i;
        REP1(i,1,n){
            int a=fin(lower_bound(num+1,num+1+len,q[i].x)-num);
            int b=fin(lower_bound(num+1,num+1+len,q[i].y)-num);
            if(q[i].z){if(a!=b) fa[a]=b;}
            else if(a==b){cnt=-1;break;}
        }
        cout<<(cnt!=-1?"YES":"NO")<<"\n";
    }
//    system("pause");
    return 0;
}
