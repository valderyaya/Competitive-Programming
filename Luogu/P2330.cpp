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
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int pa[301];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
struct qq{int a,b,w;}q[100001];
bool cmp(qq x,qq y){return x.w<y.w;}
int main(){
    oi;
    int ma=0,cnt=0,n,m,a,b,c;
    cin>>n>>m;
    REP1(i,1,n) pa[i]=i;
    REP(i,m) cin>>q[i].a>>q[i].b>>q[i].w;
    sort(q,q+m,cmp);
    REP(i,m){
        a=fin(q[i].a),b=fin(q[i].b);
        if(a!=b){
            ma=max(q[i].w,ma);
            cnt++;
            pa[a]=b;
        }
    }
    cout<<cnt<<' '<<ma;
//    system("pause");
    return 0;
}
