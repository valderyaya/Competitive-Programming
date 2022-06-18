#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

struct q{
    string name;
    int a=0,b=0,cnt=0,sum=0;
    char x,y;
}now,ans;
int n,s,ss=0;
int main(){
    oi;
    cin>>n;
    REP(i,n){
        s=0;
        cin>>now.name>>now.a>>now.b>>now.x>>now.y>>now.cnt;
        if(now.a>80&&now.cnt) s+=8000;
        if(now.a>85&&now.b>80) s+=4000;
        if(now.a>90) s+=2000;
        if(now.a>85&&now.y=='Y') s+=1000;
        if(now.b>80&&now.x=='Y') s+=850;
        ss+=s;
        if(s>ans.sum){
            ans.name=now.name,ans.sum=s;
        }
    }
    cout<<ans.name<<"\n"<<ans.sum<<"\n"<<ss;
//    system("pause");
    return 0;
}
