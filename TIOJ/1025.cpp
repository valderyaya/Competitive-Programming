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

int a[10][10],cnt=0;
vector<pii> v;
inline void print(){
    REP(i,9){
         REP(j,9){
             cout<<a[i][j]<<' ';
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
                    if(a[k][l]==0) continue;
                    if(t[a[k][l]]==0) t[a[k][l]]=1;
                    else return 0;
                }
            }
        }
    }
    REP(i,9){
        int t[10]={};
        REP(j,9){
            if(a[i][j]==0) continue;
            if(t[a[i][j]]==0) t[a[i][j]]=1;
            else return 0;
        }
    }
    REP(i,9){
        int t[10]={};
        REP(j,9){
            if(a[j][i]==0) continue;
            if(t[a[j][i]]==0) t[a[j][i]]=1;
            else return 0;
        }
    }
    return 1;
}
void solve(int x){
    if(x==v.size()){
        cnt++; print();
        cout<<"\n";    
    }
    else{
        REP1(i,1,9){
            a[v[x].F][v[x].S]=i;
            if(ck()) solve(x+1);
        }
        a[v[x].F][v[x].S]=0;
    }
}
int main(){
    oi;
    REP(i,9){
        REP(j,9){
            cin>>a[i][j];
            if(a[i][j]==0) v.em(mkp(i,j));       
        }
    }
    solve(0);
    cout<<"there are a total of "<<cnt<<" solution(s).\n";
//    system("pause");
    return 0;
}
