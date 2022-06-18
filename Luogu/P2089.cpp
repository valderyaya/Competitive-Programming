#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair

int an[100000][10],ans=0;
void dfs(int a[],int n,int cnt){
    if(cnt==10){
        if(n==0){
        REP(i,10) an[ans][i]=a[i];
        ans++;}
    }else{
        if(n>0){REP1(i,1,3){a[cnt]=i;dfs(a,n-i,cnt+1);};}
    }
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,a[11]={};
    cin>>n;
    if(n>9&&n<31){
    dfs(a,n,0);
    cout<<ans<<"\n";
    REP(i,ans){
        REP(j,10) cout<<an[i][j]<<' ';
        cout<<"\n";
    }}else{
        cout<<0;
    }
//    system("pause");
    return 0;
}
