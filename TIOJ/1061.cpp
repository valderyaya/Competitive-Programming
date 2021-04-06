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


char m[3][3];
bool ck(char c){
    if(m[0][0]==m[0][1]&&m[0][1]==m[0][2]&&m[0][0]==c) return 1;
    if(m[1][0]==m[1][1]&&m[1][1]==m[1][2]&&m[1][0]==c) return 1;
    if(m[2][0]==m[2][1]&&m[2][1]==m[2][2]&&m[2][0]==c) return 1;
    if(m[0][0]==m[1][0]&&m[1][0]==m[2][0]&&m[0][0]==c) return 1;
    if(m[0][1]==m[1][1]&&m[1][1]==m[2][1]&&m[0][1]==c) return 1;
    if(m[0][2]==m[1][2]&&m[1][2]==m[2][2]&&m[0][2]==c) return 1;
    if(m[0][0]==m[1][1]&&m[1][1]==m[2][2]&&m[0][0]==c) return 1;
    if(m[0][2]==m[1][1]&&m[1][1]==m[2][0]&&m[0][2]==c) return 1;
    return 0;
}
set<string> c1,c2,c3;
void print(){
    REP(i,3) {
        REP(j,3) cout<<m[i][j];
        cout<<endl;
    }
    cout<<"-------------------\n";
}
void dfs(int pre,string cc){
    if(ck('O')) return c1.insert(cc),void();
    if(ck('X')) return c2.insert(cc),void();
    bool ck=1; int x=0;
    REP(i,3) REP(j,3){
        if(m[i][j]=='-'){ck=0;
            if(pre) m[i][j]='X',cc[x]='X',dfs(0,cc),m[i][j]='-',cc[x]='-';
            else  m[i][j]='O',cc[x]='O',dfs(1,cc),m[i][j]='-',cc[x]='-';
        }
        x++;
    }
    if(ck) c3.insert(cc);
}
int main(){//Rosario
    int a=0,b=0;
    string cc;
    REP(i,3) REP(j,3) {
        m[i][j]=getchar();
        if(m[i][j]=='O') ++a;
        else if(m[i][j]=='X') ++b; 
        cc.push_back(m[i][j]);
    }
    if(a>b) dfs(1,cc);
    else dfs(0,cc);
    cout<<c1.size()+c2.size()+c3.size()<<' '<<c1.size()<<' '<<c2.size()<<' '<<c3.size()<<"\n";
    return 0;
}
//OOXXXO--O
