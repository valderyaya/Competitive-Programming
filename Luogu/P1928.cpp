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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair
#define ull unsigned long long


string dfs(){
    int n;
    string ret="";
    char c;
    while(cin >> c){
        if(c == '['){
            cin >> n;
            string s = dfs();
            while(n--)
                ret += s;
        }else if(c != ']')
            ret += c;
        else
            return ret;
    }
    return ret; 
}
int main(){StarBurstStream
    cout << dfs();
    return 0;
}
