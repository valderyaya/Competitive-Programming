//#pragma GCC optimize("Ofast")
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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n;
bool a[3001][3001];
void dfs(int x,int y,int z){
    if(x<0||y<0||z<0||x>n||y>n||z>n||a[x][y]) return;
    a[x][y]=1;
    dfs(y,x,z);dfs(x,z,y);dfs(z,y,x);dfs(2*y-x+1,2*x-y-1,z);
}
int main(){Rosario
    int x1,x2,y1,y2,z1,z2;
    while(cin>>n>>x1>>y1>>z1>>x2>>y2>>z2,n){
        if(x1+y1+z1!=x2+y2+z2){cout<<"No\n";continue;}
        memset(a,0,sizeof(a));
        dfs(x1,y1,z1);
        cout<<(a[x2][y2]?"Yes":"No")<<"\n";
    }
//    system("pause");
    return 0;
}
