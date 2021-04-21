#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

int n,m;
char a[101][101];
void add(int x,int y){
    if(x<0||x>=n||y<0||y>=m||a[x][y]=='X') return;
    a[x][y]++;
}
int main(){
    Rosario
    while(cin>>n>>m){
        REP(i,n){
            REP(j,m){
                cin>>a[i][j];
                if(a[i][j]=='1') a[i][j]='X';
            }
        }
        REP(i,n){
            REP(j,m){
                if(a[i][j]=='X'){
                    add(i,j+1),add(i+1,j+1),add(i+1,j),add(i+1,j-1),add(i,j-1),add(i-1,j-1),add(i-1,j),add(i-1,j+1);
                }
            }
        }
        REP(i,n){
            REP(j,m) cout<<a[i][j]<<' ';
            cout<<"\n";
        }    
    }
//    system("pause");
    return 0;
}
