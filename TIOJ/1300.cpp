#include<stdio.h>
#include <utility>
#define int short
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define pii std::pair<int,int>
#define F first
#define S second

const int inf=0;
int dx[]={2,1,-1,-2,-2,-1,1,2,1,0,0,-1},dy[]={1,2,2,1,-1,-2,-2,-1,0,1,-1,0};
int ux[]={1,0,0,-1,-1,0,0,1},uy[]={0,1,1,0,0,-1,-1,0};
char s[10][10];
int cnt[10][10],l=0,r=0;
pii q[73];
inline bool out(int x,int y){return (x<0||x>=10||y<0||y>=9);}
void write(int x){
    if(!x) return;
    write(x/10);
    putchar_unlocked(x%10+48);
}
main(){
    while(scanf("%s",s[0])!=EOF){l=r=inf;
        for(register int i=1;i<10;++i) scanf("%s",s[i]);
        register int sx,sy,ex,ey;
        REP(i,10) REP(j,9){
            if(s[i][j]=='E') ex=i,ey=j;
            else if(s[i][j]=='P') sx=i,sy=j;
            cnt[i][j]=inf;
        }
        q[r++]={sx,sy}; cnt[sx][sy]=1;
        while(l<r){
            register pii nw=q[l++];
            if(nw.F==ex&&nw.S==ey) break;
            REP(i,12){
                int x=nw.F+dx[i],y=nw.S+dy[i];
                if(i<8){
                    if(out(x,y)||cnt[x][y]||s[x][y]=='S'||(!out(nw.F+ux[i],nw.S+uy[i])&&s[nw.F+ux[i]][nw.S+uy[i]]=='S')) continue;
                    cnt[x][y]=cnt[nw.F][nw.S]+1;
                    q[r++]={x,y};
                }else{
                    if(out(x,y)||cnt[x][y]||s[x][y]=='S') continue;
                    cnt[x][y]=cnt[nw.F][nw.S]+1;
                    q[r++]={x,y};
                }
            }
        }
        if(cnt[ex][ey]) write(cnt[ex][ey]-1);
        else putchar_unlocked('0');
        puts("");
    }
    return 0;
}
