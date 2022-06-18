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


int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    if(s[0]=='-'){
        string a=s.substr(1,s.size()-1);
        reverse(a.begin(),a.end());
        cout<<'-'<<stoi(a);
    }else{
        reverse(s.begin(),s.end());
        cout<<stoi(s);
    }
//    system("pause");
    return 0;
}
