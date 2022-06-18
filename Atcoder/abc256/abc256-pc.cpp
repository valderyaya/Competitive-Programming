#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair
#define endl "\n"


int h[3],w[3],cnt;
signed main(){valder
    REP(i,3) cin>>h[i];
    REP(i,3) cin>>w[i];
    for(int a=1;a<30;++a){
        for(int b=1;b+a<h[0];++b){
            for(int c=1;c+a<w[0];++c){
                for(int d=1;d+b<w[1]&&c+d<h[1];++d){
                    int e=h[0]-a-b, f=h[1]-c-d, i=w[1]-b-d, j=w[0]-a-c;
                    //if(e<=0 || f<=0 || i<=0|| j<=0 || w[2]-e-f!=h[2]-i-j ) break;
                    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
                    if(e>0 && f>0 && i>0 && j>0 && w[2]-e-f==h[2]-i-j && w[2]-e-f>0) ++cnt;
                }
            }
        }
    }
    cout<<cnt;
}
