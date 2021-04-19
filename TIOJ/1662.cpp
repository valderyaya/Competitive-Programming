#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
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
#define lb(x) (x&-x)

string s;
int main(){
    oi;
    while(getline(cin,s)){
        vector<char> v;
        REP(i,s.size()){
            if(s[i]>='a'&&s[i]<='z') v.em('A'+s[i]-'a');
            else if(s[i]>='A'&&s[i]<='Z') v.em('a'+s[i]-'A');
            else v.em(' ');
        }
        for(char i:v) cout<<i;
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
