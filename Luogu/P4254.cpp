#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back

const int maxn = 5e4+5;
struct li_chao_segment{
    struct segment{
        double m,k;
        double val(int x){return m*(x-1)+k;}
    }seg[maxn<<1];
    #define rt(l,r) (l+r|l!=r)
    void insert(int l,int r,segment v){
        if(l==r){
            if(seg[rt(l,r)].val(l)<v.val(l)) seg[rt(l,r)]=v;
            return;
        }
        int mid=l+r>>1;
        if(seg[rt(l,r)].m>v.m) swap(seg[rt(l,r)],v);
        if(seg[rt(l,r)].val(mid)<v.val(mid)){
            swap(seg[rt(l,r)],v);
            insert(l,mid,v);
        }else insert(mid+1,r,v);
    }
    double query(int l,int r,int x){
        if(l==r) return seg[rt(l,r)].val(l);
        int mid=l+r>>1;
        if(x<=mid) return fmax(query(l,mid,x),seg[rt(l,r)].val(x));
        else return fmax(seg[rt(l,r)].val(x),query(mid+1,r,x));
    }
}valder;
int n,d;
string s;
double x,y;
signed main(){Rosario
    cin>>n;
    while(n--){
        cin>>s;
        if(s[0]=='Q') cin>>d,cout<<int(valder.query(1,50000,d)/100)<<"\n";
        else cin>>x>>y,valder.insert(1,50000,{y,x});
    }
    return 0;
}
