// Luogu P3375
#include <bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int maxn=1e6+5;
int fail[maxn];
vector<int> v;
string a,b;

void build(){
	for(int i=1,j;i<b.size();++i){
		j = fail[i-1];
		while(j && b[i]!=b[j]) j=fail[j-1];
		if(b[i] == b[j]) ++j;
		fail[i]=j;
	}
}

void solve(){
	for(int i=0,j=0;i<a.size();++i){
		while(j && a[i]!=b[j]) j=fail[j-1];
		if(a[i]==b[j]) ++j;
		if(j==b.size()){
			v.emplace_back(i-j+1);
			j = fail[j-1];
		}
	}
}

int main(){valder
	cin>>a>>b;
	build();
	solve();
	for(auto &i:v)  cout<<i+1<<"\n";
	for(int i=0;i<b.size();++i) cout<<fail[i]<<" \n"[i==b.size()-1];		
	return 0;
}
