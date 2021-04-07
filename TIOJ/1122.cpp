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

int n,a[21][21],b[21][21],m,ans;
int main(){
    oi;
    while(cin>>n>>m){
        a[1][1]=m;
        REP1(i,1,n){
            REP1(j,1,n){
                if(i==1&&j==1) continue;
                if(j==1) a[i][j]=m+i;
                else if(j>1) a[i][j]=a[i][j-1]*17%103*((i+j)&1?-1:1);
            }
            b[i][1]=a[i][1];
            REP1(j,2,n) b[i][j]=b[i][j-1]+a[i][j];
        }
        REP1(i,2,n){
            REP1(j,1,n) b[i][j]+=b[i-1][j];
        }
        ans=0;
        REP1(i,1,n){
            REP1(j,1,n){
                REP1(k,0,i-1){
                    REP1(l,0,j-1){
                        ans=max(ans,b[i][j]-b[k][j]-b[i][l]+b[k][l]);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
//    system("pause");
    return 0;
}

