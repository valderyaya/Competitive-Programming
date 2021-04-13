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

const int z=1e5+5;
struct qq{
    int id,x,y;
    bool operator<(const qq &a)const{
        if(x!=a.x) return x<a.x;
        if(y!=a.y) return y>a.y;
        return id<a.id;
    }
};
int n,m,t;
vector<qq> v[z],seg;
qq tmp[z<<1];
void P(vector<qq> &a){
    sort(ALL(a));
    int cnt=0;
    for(qq i:a){
        if(!cnt){tmp[cnt++]=i; continue;}
        if(tmp[cnt-1].y>=i.y) continue;
        else if(i.x<=tmp[cnt-1].y) tmp[cnt-1].y=max(tmp[cnt-1].y,i.y);
        else tmp[cnt++]=i;
    }
    a.resize(cnt);
    REP(i,cnt) a[i]=tmp[i];
}
void build(){
    seg.clear();
    REP1(i,1,n){
        if(v[i].empty()){seg.em(qq{i,0,m});continue;}
        int sz=v[i].size();
        if(v[i][0].x) seg.em(qq{i,0,v[i][0].x});
        for(int j=0;j<sz-1;++j) seg.em(qq{i,v[i][j].y,v[i][j+1].x});
        if(v[i][sz-1].y<m) seg.em(qq{i,v[i][sz-1].y,m});
    }
    sort(ALL(seg));
    int cnt=0;
    for(auto &i:seg){
        if(!cnt) {tmp[cnt++]=i;continue;}
        if(i.y<tmp[cnt-1].y) continue;
        if(i.y==tmp[cnt-1].y){
            if(i.x==tmp[cnt-1].x) continue;
            if(i.id>tmp[cnt-1].id) continue;
        }
        tmp[cnt++]=i;
        if(tmp[cnt-2].y<tmp[cnt-1].y) tmp[cnt-2].x=min(tmp[cnt-2].x,tmp[cnt-1].x);
    }
    seg.resize(cnt);
    REP(i,cnt) seg[i]=tmp[i];
}
int main(){Rosario
    while(cin>>n>>m,n+m){
        cin>>t;
        REP1(i,1,n) v[i].clear();
        for(int x,y,id;t;--t){
            cin>>id>>x>>y;
            v[id].em(qq{id,x,y});
        }
        REP1(i,1,n) if(!v[i].empty()) P(v[i]);
        build();
        int q,x;  cin>>q;
        while(q--){
            cin>>x;
            if(seg.empty()){cout<<"Oh, no!\n";continue;}
            else if(seg[0].x>x) {cout<<"Oh, no!\n";continue;}
            int l=0,r=seg.size();
            while(r-l>1){
                int mid=l+r>>1;
                if(x>=seg[mid].x) l=mid;
                else r=mid;
            }
            if(seg[l].y<=x) cout<<"Oh, no!\n";
            else cout<<seg[l].id<<' '<<seg[l].y-x<<"\n";
        }
    }
    return 0;
}
