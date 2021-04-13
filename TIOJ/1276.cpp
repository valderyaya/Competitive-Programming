#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vl;
typedef vector< vl > vvl;
typedef pair< int, int > pii;
typedef vector< pii > vp;

const int MAXL = 1e7 + 2;

int len, sel;
int s[ MAXL * 2 ], se[ MAXL * 2 ];
int pal[ MAXL * 2 ];

int g[ MAXL ];

const int INF = 0x3f3f3f3f;

void genpal(){
    int i, j, r, t;
    sel = 2 * len + 1;
    for(i=0;i<sel;i++) se[i]=(i&1)?s[i>>1]:INF; pal[0]=0;
    j=r=0;
    for(i=1;i<sel;i++) {
        t=min(r>=i?pal[2*j-i]:0,r-i+1);
        for(;i-t>=0&&i+t<sel;t++) if(se[i-t]!=se[i+t]) break; pal[i]=--t;
        if(i+t>r) { r=i+t; j=i; }
    }
}

void init(){
    scanf( "%d", &len );
    for( int i = 0; i < len; ++i )
        scanf( "%d", s + i );
    genpal();
    int maxv = 0;
    for( int i = 1; i < sel; ++i )
        maxv = max( maxv, pal[ i ] );
    printf( "%d\n", maxv - 1 );
}

void solve(){

}

signed main(){
    ios::sync_with_stdio( false );
    init();
    solve();
    return 0;
}
