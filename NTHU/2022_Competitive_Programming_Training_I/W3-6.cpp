//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

int n,m;
struct qwq{
    string s;
    ll pri,age;
    bool operator<(const qwq &x)const{
        if(pri!=x.pri) return pri < x.pri;
        if(pri == 5){
            if(age != x.age) return age < x.age;
            return s < x.s;
        }else{
            if(age != x.age) return age > x.age;
            return s < x.s;
        }
    }
}a[10005];
int main(){StarBurstStream
    string s;
    while(cin>>n>>m){
        REP(i,n){
            cin>>a[i].s>>s>>a[i].age;
            if(s[0]=='e') a[i].pri = 1;
            else if(s[0]=='n') a[i].pri = 2;
            else if(s[0]=='k') a[i].pri = 3;
            else if(s[0]=='w') a[i].pri = 4;
            else if(s[0]=='a') a[i].pri = 5;
            else if(s[0]=='m') a[i].pri = 6;
            else if(s[0]=='d') a[i].pri = 7;
            else a[i].pri = 8;
        }
        sort(a,a+n);
        REP(i,min(n,m)) cout<<a[i].s<<"\n";
    }
}
