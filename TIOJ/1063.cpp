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

int n,m,a[201][201],row[201],ma=0;
int main(){
    //oi;
    cin>>n>>m;
    REP(i,n){
        REP(j,m){
            cin>>a[i][j];
            row[j]=a[i][j]?row[j]+1:0;
            for(int k=j,l=row[j];k>=0&&a[i][k];k--,l=min(row[k],l)){
                ma=max(ma,l*(j-k+1));
            } 
        }
    }
    cout<<ma<<"\n";
//    system("pause");
    return 0;
}
