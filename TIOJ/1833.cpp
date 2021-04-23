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


int p[100001];
int fin(int a){return p[a]==a?a:p[a]=fin(p[a]);}
void un(int a,int b){
	int x=fin(a),y=fin(b);
	if(x!=y) p[y]=x;
}
void init(int n){
	REP1(i,1,n) p[i]=i;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a,b;
	string s;
	while(cin>>n>>m){
		init(n);
		while(m--){
			cin>>s;
			if(s=="Masuta"){
				cin>>a>>b;
				un(a,b);
			}else if(s=="Kuiin"){
				cin>>a;
				cout<<fin(a)<<"\n";
			}
		}
	}
//    system("pause");
	return 0;
}
