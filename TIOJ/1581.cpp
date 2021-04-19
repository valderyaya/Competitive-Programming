#include<stdio.h>
#include<vector>
#include <utility>
using namespace std;
#define pii pair<int,int> 
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)

vector<pii> v;
bool no;
int cnt,a[5][5],ans[5][5];
bool ck(){
    REP1(i,1,4){
        int c[5]={};
        REP1(j,1,4)
            if(a[i][j]&&c[a[i][j]]) return 0;
            else c[a[i][j]]=1;
    }
    REP1(i,1,4){
        int c[5]={};
        REP1(j,1,4)
            if(a[j][i]&&c[a[j][i]]) return 0;
            else c[a[j][i]]=1;
    }
    for(int i=1;i<=4;i+=2) for(int j=1;j<=4;j+=2){
        int c[5]={};
        for(int k=i;k<i+2;++k) for(int l=j;l<j+2;++l)
            if(a[k][l]&&c[a[k][l]]) return 0;
            else c[a[k][l]]=1;
    }
    return 1;
}
void pp(){
    REP1(i,1,4) REP1(j,1,4) ans[i][j]=a[i][j];
}
void gmx(){
    REP1(i,1,4) REP1(j,1,4){
        if(ans[i][j]<a[i][j]) return;
        if(ans[i][j]>a[i][j]){pp();return;}
    }
}
void dfs(int id){
    if(id==v.size()){
        ++cnt;
        gmx();
        return;
    }
    int x=v[id].F,y=v[id].S;
    REP1(i,1,4){
        a[x][y]=i;
        if(ck()) dfs(id+1);
        a[x][y]=0;
    }
}
signed main(){
    REP1(i,1,4) REP1(j,1,4){
		ans[i][j]=5;
        scanf("%d",&a[i][j]);
        if(a[i][j]==0) v.push_back({i,j});
        if(a[i][j]>4||a[i][j]<0){no=1; break;}
    }
    if(no) return puts("I can not solve!!"),0;
    if(v.empty()){
        if(ck()){
            REP1(i,1,4){
                REP1(j,1,4) printf("%d",a[i][j]);
                puts("");
            }
			printf("\nWe have 1 way(s) to solve it!!\n");
        }else puts("I can not solve!!");
        return 0;
    }
    dfs(0);
    if(cnt==0) return puts("I can not solve!!"),0;
    else{
        REP1(i,1,4){
            REP1(j,1,4) printf("%d",ans[i][j]);
            puts("");
        }
        printf("\nWe have %d way(s) to solve it!!\n",cnt);
    }
    return 0;
}
