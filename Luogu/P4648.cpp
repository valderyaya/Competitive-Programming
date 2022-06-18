#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define lb(x) (x&-x)

int B,n,m,D;
/////////////////////////////////  B=1
void solve_1(){
    vector<int> v(n);
    ll ans=0;
    for(int i=0; i<n; ++i) cin>>v[i];
    sort(ALL(v));
    for(int i=0, j=0; i<n; ++i){
        while(v[i]-v[j]>D) ++j;
        ans+= i-j;
    }
    cout<<ans<<"\n";
}
//////////////////////////////////

////////////////////////////////// B=2
int bit[150005];
void add(int x,int v){
    for(;x<=150000;x+=lb(x))
        bit[x]+=v;
}
int query(int x){
    x=min(x,150000); // 把x设在合理的范围
    x=max(0,x);  // 同上
    int res=0;
    for(;x;x-=lb(x))
        res+=bit[x];
    return res;
}
bool cmp(pii x,pii y){return x.S<y.S;} // 比较函式
void solve_2(){
    vector<pii> v(n);
    for(int x,y,i=0; i<n; ++i){
        cin>>x>>y;
        v[i].F= x+y;
        v[i].S= x-y;
    }
    sort(ALL(v),cmp);
    ll ans=0;
    for(int i=0, j=0; i<n; ++i){
        while(v[i].S-v[j].S>D) add(v[j++].F,-1);
        ans+= query(v[i].F+D) - query(v[i].F-D-1);// 询问 x-D ~ x+D 有多少个点
        add(v[i].F,1);
    }
    cout<<ans<<"\n";
}
///////////////////////////////////

/////////////////////////////////// B=3
int sum[80][205][205]; // 前缀和
struct point{
    int x,y,z;
    bool operator<(const point &a)const{
        if(z!=a.z) return z<a.z;
        if(x!=a.x) return x<a.x;
        return y<a.y;
    }
}p[100005];
void solve_3(){
    for(int x,y,z,i=0; i<n; ++i){
        cin>>x>>y>>z;
        p[i].x= x+y;
        p[i].y= x-y+m; // 因为会有负数，所以 +m
        p[i].z= z;
        sum[z][p[i].x][p[i].y]++;
    }
    sort(p,p+n);
    for(int k=1; k<=m; ++k)
        for(int i=1; i<=200; ++i)
            for(int j=1; j<=200; ++j)
                sum[k][i][j]+= sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1];
                //  算前缀和
    ll ans=0,cnt=0;
    for(int i=0; i<n; ++i){
        for(int j=max(1,p[i].z-D); j < p[i].z; ++j){
            int d= D-(p[i].z-j); // 减掉z的差值后还有多少距离
            int x1=max(1,p[i].x-d),y1=max(1,p[i].y-d),x2=min(200,p[i].x+d),y2=min(200,p[i].y+d);
            ans+= sum[j][x2][y2]-sum[j][x1-1][y2]-sum[j][x2][y1-1]+sum[j][x1-1][y1-1];
            // 在 z轴=j 的时候有多少点可以和当前点配对，加进ans
        }
        int x1=max(1,p[i].x-D),y1=max(1,p[i].y-D),x2=min(200,p[i].x+D),y2=min(200,p[i].y+D);
        int nw=p[i].z;
        cnt+= sum[nw][x2][y2]-sum[nw][x1-1][y2]-sum[nw][x2][y1-1]+sum[nw][x1-1][y1-1];
        // 当前平面有多少点可以和当前的点(p[i]) 配对，加进cnt
    }
    cnt-=n; //去重
    cnt/=2; //去重
    cout<<ans+cnt<<"\n";
}
///////////////////////////////////
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>B>>n>>D>>m;
    if(B==1) solve_1();
    else if(B==2) solve_2();
    else solve_3();
    return 0;
}
