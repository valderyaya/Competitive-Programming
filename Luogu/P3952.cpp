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
#define wait system("pause");

const int inf=1e5;
int test,n,err,p,st[105],top,cnt,ans,tag,x,y,a[105];
string str;
bitset<26> in;
char ch;
int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='n') return -1;
        c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
    return x;
}
int main(){//Rosario
    test=read();
    while(test--){
        in.reset();
        REP1(i,1,100) a[i]=0;
        n=read();
        if(read()!=-1) p=0;
        else p=read();
        err=top=cnt=ans=0;tag=inf;
        while(n--){
            if(err) {getline(cin,str);continue;}
            cin>>ch;
            if(ch=='F'){
                cin>>ch;
                x=read(),y=read();
                if(in[ch-'a']){
                    err=1;
                    continue;
                }else in[ch-'a']=1;
                st[++top]=ch-'a';
                if(top<tag)  tag=inf;
                else continue;
                if(x==-1){
                    if(y!=-1) tag=top;
                }else if(y==-1){
                    if(x!=-1) cnt++,ans=max(ans,cnt),a[top]=1;
                }else if(x>y) tag=top;
            }else{
                in[st[top]]=0;cnt-=a[top];a[top--]=0;
                if(top<tag) tag=inf;
                if(top<0) err=1;
            }
        }
        if(err||top) puts("ERR");
        else if(ans==p) puts("Yes");
        else puts("No");
    }
//    system("pause");
    return 0;
}
