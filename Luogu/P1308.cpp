#include<bits/stdc++.h>
using namespace std;

string a,b;
int f[1000001], cnt=0, frt = -1, n;
int main(){
    getline(cin,a);
    getline(cin,b);
    //cin >> a >> b;
    for(int i=0;i<a.size();++i) a[i]=tolower(a[i]);
    for(int i=0;i<b.size();++i) b[i]=tolower(b[i]);
    a = ' '+a+' ';
    b = ' '+b+' ';
    n = a.size();
    for(int i = 1; i < n; ++i){
        int j = f[i-1];
        while(j > 0 && a[i] != a[j]) j = f[j-1];
        if(a[i]==a[j]) ++j;
        f[i] = j;
    }
    for(int i = 0, j = 0; j < b.size(); ++j){
        while(i > 0 && a[i] != b[j]) i = f[i-1];
        if(a[i]==b[j]) ++i;
        if(i==n){
            //cout<<j<<endl;
            ++cnt;
            if(frt==-1) frt=j-i+1;
            i=f[i-1];
        }
    }
    if(!~frt) cout<<"-1\n";
    else cout<<cnt << ' ' << frt <<"\n";
}
