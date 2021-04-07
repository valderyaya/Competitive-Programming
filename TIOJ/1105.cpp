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
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

struct qq{int x,y,id;}q[3001],st[3001];
int n,mx,idx,idx2;
pii ans,tmp;
bool cmp(qq a,qq b){return a.x==b.x?a.y<b.y:a.x<b.x;}
qq operator-(qq a,qq b){return qq{a.x-b.x,a.y-b.y};}
int cross(qq a,qq b){return a.x*b.y-a.y*b.x;}
int ori(qq a,qq b,qq c){
    int x=cross(b-a,c-a);
    if(x==0) return 0;
    return x>0?1:-1;
}
int dis(qq a,qq b){
    int x=a.x-b.x,y=a.y-b.y;
    return x*x+y*y;
}
int main(){Rosario
    while(cin>>n,n){mx=idx=0;
        REP(i,n) cin>>q[i].x>>q[i].y,q[i].id=i;
        sort(q,q+n,cmp);
        REP(i,n){
            while(idx>1&&ori(st[idx-2],st[idx-1],q[i])<=0) idx--;
            st[idx++]=q[i];
        }idx2=idx;
        for(int i=n-1;i>=0;i--){
            while(idx2-idx>0&&ori(st[idx2-2],st[idx2-1],q[i])<=0) idx2--;
            st[idx2++]=q[i];
        }--idx2;
        int j=2;
        REP(i,idx2){
            while(abs(cross(st[i]-st[j],st[i+1]-st[j]))<abs(cross(st[i]-st[j+1],st[i+1]-st[j+1]))){
                j++;
                if(j==idx2) j=0;
            }
            int x=dis(st[i],st[j]);
            tmp=mkp(min(st[i].id,st[j].id),max(st[i].id,st[j].id));
            if(x>mx||x==mx&&tmp<ans) ans=tmp,mx=x;
        }cout<<ans.F<<' '<<ans.S<<"\n";
    }
//    system("pause");
    return 0;
}
