#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int z=2e5+5;
int tr[z*30][2],ck,n,m,cnt,val[z*30];
string s;
void add(int x){
    int p=0;
    REP(i,s.size()){
        int c=s[i]-'0';
        if(!tr[p][c]) tr[p][c]=++cnt;
        p=tr[p][c];
        if(i==x-1)  val[p]=1;
    }
}
void qry(){
    int p=0; ck=0;
    for(auto &i:s){
        if(tr[p][i-'0']){
            p=tr[p][i-'0'];
            ck|=val[p];
        }else break;
    }
    puts(ck?"TRUE":"FALSE");
}
int main(){//oi
    scanf("%d%d",&n,&m);
    int a,b,c,d,e;
    while(n--){
        scanf("%d.%d.%d.%d/%d",&a,&b,&c,&d,&e);
        string A=bitset<8>(a).to_string();
        string B=bitset<8>(b).to_string();
        string C=bitset<8>(c).to_string();
        string D=bitset<8>(d).to_string();
        s=A+B+C+D; add(e);
    }
    while(m--){
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        string A=bitset<8>(a).to_string();
        string B=bitset<8>(b).to_string();
        string C=bitset<8>(c).to_string();
        string D=bitset<8>(d).to_string();
        s=A+B+C+D; qry();
    }
}
