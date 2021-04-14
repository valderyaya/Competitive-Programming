//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

struct qq{
    string str;
    int idx,cnt;
};
set<string> s;
string t;
queue<qq> q;
bitset<10> up,dw,l,r;
void init(){
    q.emplace(qq{"123456780",8,0});
    int c,id;
    while(!q.empty()){
        t=q.front().str,id=q.front().idx,c=q.front().cnt;q.pop();
        if(c>20) continue;
        s.insert(t);
        if(up[id]){
            swap(t[id],t[id-3]);
            if(s.find(t)==s.end()) q.emplace(qq{t,id-3,c+1});
            swap(t[id],t[id-3]);
        }
        if(l[id]){
            swap(t[id],t[id-1]);
            if(s.find(t)==s.end()) q.emplace(qq{t,id-1,c+1});
            swap(t[id],t[id-1]);
        }
        if(r[id]){
            swap(t[id],t[id+1]);
            if(s.find(t)==s.end()) q.emplace(qq{t,id+1,c+1});
            swap(t[id],t[id+1]);
        }
        if(dw[id]){
            swap(t[id],t[id+3]);
            if(s.find(t)==s.end()) q.emplace(qq{t,id+3,c+1});
            swap(t[id],t[id+3]);
        }
    }
}
int main(){Rosario
    r[0]=r[1]=r[3]=r[4]=r[6]=r[7]=1;
    up[3]=up[4]=up[5]=up[6]=up[7]=up[8]=1;
    l[1]=l[2]=l[4]=l[5]=l[7]=l[8]=1;
    dw[0]=dw[1]=dw[2]=dw[3]=dw[4]=dw[5]=1;
    init();
    int n;
    char ch;
    cin>>n;
    while(n--){
        t="";
        REP(i,9) cin>>ch,t.push_back(ch);
        cout<<(s.find(t)==s.end()?"Hard":"Easy")<<'\n';
    }
//    system("pause");
    return 0;
}
