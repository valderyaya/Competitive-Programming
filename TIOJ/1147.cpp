#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

pii a[1005];
int n,ans=1e9,tmp,x,y;
int main(){
    oi;
    cin>>n;
    REP(i,n) cin>>a[i].F>>a[i].S;
    REP(i,n){
        tmp=0;
        REP(j,n){
            tmp+=abs(a[i].F-a[j].F)+abs(a[i].S-a[j].S);
        }
        if(tmp<ans){ans=tmp,x=a[i].F,y=a[i].S;}
        else if(tmp==ans){
            if(a[i].F<x){
                x=a[i].F,y=a[i].S;
            }else if(a[i].F==x){
                y=a[i].S;
            } 
        }
    }
    cout<<x<<' '<<y<<'\n'<<ans<<"\n";
//    system("pause");
    return 0;
}
