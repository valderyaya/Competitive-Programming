#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,a,b) for(int i=a;i<=b;i++)

struct qq{int x,y,idx;}pt[100005];
struct edge{
    int a,b,c;
    bool operator<(const edge &x)const{
          return c<x.c;
    }
}q[1000005];
bool cmp1(qq a,qq b){return a.x==b.x?a.y<b.y:a.x<b.x;}
bool cmp2(qq a,qq b){return a.y==b.y?a.x<b.x:a.y<b.y;}
int n,t,pa[100005],cnt,len;
ll sum;
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
      cin>>t;
      while(t--){
            cin>>n;
            sum=len=0;cnt=n;
            REP(i,n) cin>>pt[i].x>>pt[i].y,pt[i].idx=i,pa[i]=i;
            sort(pt,pt+n,cmp1);
            REP1(i,1,n-1) if(pt[i].x==pt[i-1].x)  q[len++]=edge{pt[i].idx,pt[i-1].idx,pt[i].y-pt[i-1].y};
            sort(pt,pt+n,cmp2);
            REP1(i,1,n-1) if(pt[i].y==pt[i-1].y) q[len++]=edge{pt[i].idx,pt[i-1].idx,pt[i].x-pt[i-1].x};
            sort(q,q+len);
            REP(i,len){
                    if(cnt==1) break;
                    int a=fin(q[i].a),b=fin(q[i].b);
                    if(a!=b) pa[a]=b,sum+=q[i].c,cnt--;
            }
            cout<<sum<<"\n";
      }
//      system("pause");
}
