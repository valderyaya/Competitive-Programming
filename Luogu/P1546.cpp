#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int pa[101];
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
struct qq{int a,b,w;};
vector<qq> v;
bool cmp(qq a,qq b){return a.w<b.w;}
int main(){
    oi;
    ll x,y,n,m,sum=0;
    cin>>n;
    REP(i,n) pa[i]=i;
    REP(i,n){
        REP(j,n){
            cin>>m;
            if(i<j){v.em(qq{i,j,m});}
        }
    }
    sort(ALL(v),cmp);
    REP(i,v.size()){
        x=fin(v[i].a),y=fin(v[i].b);
        if(x!=y){
            pa[x]=y;sum+=v[i].w;
        }
    }
    cout<<sum<<endl;
//    system("pause");
    return 0;
}
