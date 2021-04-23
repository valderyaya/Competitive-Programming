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

map<char,int> ma;
inline int ex(string s){
    int x=0;
    REP(i,s.size()){
        if(i+1<s.size()&&ma.find(s[i])->S<ma.find(s[i+1])->S){
            x+=ma.find(s[i+1])->S-ma.find(s[i])->S;
            i++;
        }else{
            x+=ma.find(s[i])->S;
        }
    }
    return x;
}
void e(int x){
    string M[]={"","M","MM","MMM"},C[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string X[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},I[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    if(x==0){ cout<<"ZERO\n";return;}
    cout<<M[x/1000]+C[(x%1000)/100]+X[(x%100)/10]+I[x%10]<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ma['I']=1,ma['V']=5,ma['X']=10,ma['L']=50,ma['C']=100,ma['D']=500,ma['M']=1000;
    string a,b;
    //int x,y;
    while(cin>>a,a!="#"){
        cin>>b;
        //x=ex(a),y=ex(b);
        e(abs(ex(a)-ex(b)));
    }
//    system("pause");
    return 0;
    
}
