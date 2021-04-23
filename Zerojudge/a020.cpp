#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
//#define pb push_back
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair

map<char,int> ma;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ma['A']=10;ma['B']=11;ma['C']=12;ma['D']=13;ma['E']=14;ma['F']=15;ma['G']=16;ma['H']=17;
    ma['I']=34;ma['J']=18;ma['K']=19;ma['L']=20;ma['M']=21;ma['N']=22;ma['O']=35;ma['P']=23;
    ma['Q']=24;ma['R']=25;ma['S']=26;ma['T']=27;ma['U']=28;ma['V']=29;ma['W']=32;ma['X']=30;
    ma['Y']=31;ma['Z']=33;
    string s;
    while(getline(cin,s)){
        int sum=(ma[s[0]])/10+9*((ma[s[0]])%10);
        for(int i=1,j=8;i<s.size();i++,j--){
            sum+=(s[i]-'0')*j;
        }
        cout<<((sum+s[9]-'0')%10?"fake\n":"real\n");
    }
 //   system("pause");
    return 0;
}
