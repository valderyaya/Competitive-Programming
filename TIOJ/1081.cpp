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

int n,m,cnt,dx[]={1,0,0,-1,1,1,-1,-1},dy[]={0,1,-1,0,1,-1,1,-1},x,y,xx,yy;
string s[1005];
queue<pii> q;
int main(){
    //oi;
    while(cin>>n>>m,n){
        REP(i,n)cin>>s[i];
        cnt=0;
        REP(i,n){
            REP(j,m){
                if(s[i][j]=='1'){
                    cnt++;s[i][j]='#';
                    while(q.size()) q.pop();
                    q.emplace(mkp(i,j));
                    while(q.size()){
                        x=q.front().F,y=q.front().S;q.pop();
                        REP(k,8){
                            xx=x+dx[k],yy=y+dy[k];
                            if(xx<0||xx>=n||yy<0||yy>=m||s[xx][yy]=='0'||s[xx][yy]=='#') continue;
                            q.emplace(mkp(xx,yy));s[xx][yy]='#';
                        }
                    }
                }
            }
        }
        cout<<cnt<<"\n";
    }
//    system("pause");
    return 0;
}


