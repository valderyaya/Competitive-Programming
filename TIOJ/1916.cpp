#include<bits/stdc++.h>
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
 
int n,a[2005][2005];
int main(){
    oi;
    while(cin>>n,n){
    REP(i,n){
        REP(j,n) cin>>a[i][j];
    }
    cin>>n;
    while(n--){
        int hp=0,now=-1,r,rr,c,cc,cnt=0;
        cin>>r>>rr>>c>>cc;
        for(int i=r;i<=rr;i++){
            for(int j=c;j<=cc;j++){
                if(now!=a[i][j]){
                    if(hp==0){
                        now=a[i][j];hp++;
                    }else{
                        hp--;
                        if(hp==0) now=-1;
                    }
                }else hp++;
            }
        }
        for(int i=r;i<=rr;i++){
            for(int j=c;j<=cc;j++){
                if(a[i][j]==now) cnt++;
            }
        }
        cout<<((cnt*2>(rr-r+1)*(cc-c+1))?now:-1)<<"\n";
    }
    }
//    system("pause");
    return 0;
}
