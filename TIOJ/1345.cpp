#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define lb(x) (x&-x)


void rd(int &x){
	x=0;register char c=getchar_unlocked();
	while(c<'0'||c>'9') c=getchar_unlocked();
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar_unlocked();
}
int B,n,m,d,bit[150005];
void add(int x,int v){
    for(;x<=150000;x+=lb(x)) bit[x]+=v;
}
int que(int x){
    if(x>150000) x=150000;
    if(x<0) x=0;
    int res=0;
    for(;x;x-=lb(x)) res+=bit[x];
    return res;
}
void opt1(){
    vector<int> v(n);
    ll sum=0;
    REP(i,n) rd(v[i]);
    sort(ALL(v));
    for(int i=0,j=0;i<n;++i){
        while(v[i]-v[j]>d) ++j;
        sum+=i-j;
    }
	printf("%lld",sum);
}
bool cmp(pii x,pii y){return x.S<y.S;}
void opt2(){
    vector<pii> v(n);
    for(int x,y,i=0;i<n;++i) rd(x),rd(y),v[i].F=x+y,v[i].S=x-y;
    sort(ALL(v),cmp);
    ll sum=0;
    for(int i=0,j=0;i<n;++i){
        while(v[i].S-v[j].S>d) add(v[j++].F,-1);
        sum+=(que(v[i].F+d)-que(v[i].F-d-1));
        add(v[i].F,1);
    }
    printf("%lld",sum);
}
int cnt[80][205][205]={};
struct qq{
    int x,y,z;
    bool operator<(const qq &a)const{
        if(z!=a.z) return z<a.z;
        if(x!=a.x) return x<a.x;
        return y<a.y; 
    }    
}q[100005];
void opt3(){
    int x,y,z;
    REP(i,n){
        rd(x),rd(y),rd(z);
        q[i].x=x+y;
        q[i].y=x-y+m;
        q[i].z=z;
        ++cnt[z][q[i].x][q[i].y];
    }
    sort(q,q+n);
    for(int k=1;k<=m;++k)
        REP1(i,1,200) REP1(j,1,200) cnt[k][i][j]+=cnt[k][i-1][j]+cnt[k][i][j-1]-cnt[k][i-1][j-1];
    ll sum=0,ans=0;
    REP(i,n){
        for(int dd,j=max(1,q[i].z-d);j<q[i].z;++j){
            dd=d-(q[i].z-j);
            int x1=max(1,q[i].x-dd),y1=max(1,q[i].y-dd),x2=min(200,q[i].x+dd),y2=min(200,q[i].y+dd);
            sum+=cnt[j][x2][y2]-cnt[j][x1-1][y2]-cnt[j][x2][y1-1]+cnt[j][x1-1][y1-1];
        }
        int x1=max(1,q[i].x-d),y1=max(1,q[i].y-d),x2=min(200,q[i].x+d),y2=min(200,q[i].y+d);
        ans+=cnt[q[i].z][x2][y2]-cnt[q[i].z][x1-1][y2]-cnt[q[i].z][x2][y1-1]+cnt[q[i].z][x1-1][y1-1];
    }
    ans-=n;
    ans>>=1;
	printf("%lld",sum+ans);
}
int main(){//Rosario
    rd(B),rd(n),rd(d),rd(m);
    if(B==1) opt1();
    else if(B==2) opt2();
    else opt3();
    return 0;
}
