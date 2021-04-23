#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
//#define ios::sync_with_stdio(false),cin.tie(0);


int main(){
      string s;
      vector<int> ve[26];
      while(cin>>s){
        REP(i,s.length()){
          ve[s[i]-'A'].pb(i+1);
        }
        REP(i,26){
          if(!ve[i].empty()){
            cout<<char(i+'A')<<":"<<ve[i][0]<<','<<ve[i][ve[i].size()-1]<<endl;
          }
        }
      }

//    system("pause");
    return 0;
}
