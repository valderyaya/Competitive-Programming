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

int cnt=0,k,n,a[21];
bool is(int x){
    if(x==1||x==0)return false;
    else if(x==2)return true;
    for(int i=2;i*i<=x;i+=(i==2?1:2)){
        if(x%i==0)return false;
    }
    return true;
}
void dfs(int i,int sum,int re){
    if(re==0){
        if(is(sum)){
            cnt++;return;
        }
    }
    if(i>=n||n-i+1<re) return;
    dfs(i+1,sum,re);
    dfs(i+1,sum+a[i],re-1);
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    REP(i,n)cin>>a[i];
    dfs(0,0,k);
    cout<<cnt;
//    system("pause");
    return 0;
}
