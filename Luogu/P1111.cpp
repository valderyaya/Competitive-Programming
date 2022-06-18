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
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

struct qq{int a,b,w;}q[100005];
int n,m,i,p[1005],ran[1005]={};
bool cmp(qq x,qq y){return x.w<y.w;}
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
int main(){
    oi;
    cin>>n>>m;
    for(i=1;i<=n;i++) p[i]=i;
    for(i=0;i<m;i++){ cin>>q[i].a>>q[i].b>>q[i].w;}
    sort(q,q+m,cmp);
    for(i=0;i<m;i++){
        int a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b){
            if(ran[a]>ran[b]) p[b]=a;
            else if(ran[a]<ran[b]) p[a]=b;
            else {
                p[a]=b,ran[a]++;
            }
            n--;
        }
        if(n==1) break;
    }
    cout<<(n==1?q[i].w:-1)<<"\n";
//    system("pause");
    return 0;
}
