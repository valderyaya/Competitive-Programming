#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int a[10][10],b[10][10]; 
string s,m="*ROYGBIPLW";
map<char,int> n;
vector<pii> v;
inline void print(){
    REP(i,9){
         REP(j,9){
             if(a[i][j]==0) cout<<m[b[i][j]];
         }
         cout<<"\n";
    }
}
bool ck(){
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            int t[10]={};
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    if(b[k][l]==0) continue;
                    if(t[b[k][l]]==0) t[b[k][l]]=1;
                    else return 0;
                }
            }
        }
    }
    REP(i,9){
        int t[10]={};
        REP(j,9){
            if(b[i][j]==0) continue;
            if(t[b[i][j]]==0) t[b[i][j]]=1;
            else return 0;
        }
    }
    REP(i,9){
        int t[10]={};
        REP(j,9){
            if(b[j][i]==0) continue;
            if(t[b[j][i]]==0) t[b[j][i]]=1;
            else return 0;
        }
    }
    return 1;
}
void solve(int x){
    if(x==v.size()) print();
    else{
        REP1(i,1,9){
            b[v[x].F][v[x].S]=i;
            if(ck()) solve(x+1);
        }
        b[v[x].F][v[x].S]=0;
    }
}
int main(){
    oi;
    n['R']=1,n['O']=2,n['Y']=3,n['G']=4,n['B']=5,n['I']=6,n['P']=7,n['L']=8,n['W']=9;
    REP(i,9){
        cin>>s;
        REP(j,9){
            a[i][j]=n[s[j]];
            b[i][j]=a[i][j];
            if(a[i][j]==0) v.em(mkp(i,j));       
        }
    }
    solve(0);
//    system("pause");
    return 0;
}
