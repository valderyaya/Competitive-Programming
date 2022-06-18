#include <iostream>
#include <memory.h>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAXN = 3e5 + 50;
struct { int keys[2]; int index; } bucket[2][MAXN];
int SA[MAXN], RA[MAXN], sum[MAXN]; string s;

void radix_sort(int C) {
    int i, j;
    for(j = 1;j >= 0;j--) {
        memset(sum, 0, sizeof(sum));
        for(i = 0;i < s.size();i++) sum[bucket[0][i].keys[j]] += 1;
        for(i = 1;i <= C;i++) sum[i] += sum[i - 1];
        for(i = s.size() - 1;i >= 0;i--) {
            int &index = sum[bucket[0][i].keys[j]];
            index -= 1;
            bucket[1][index] = bucket[0][i];
        }
        swap(bucket[0], bucket[1]);
    }
    for(j = i = 0;i < s.size();i++) {
        RA[bucket[0][i].index] = j;
        if(i + 1 != s.size()) j += (bucket[0][i].keys[0] == bucket[0][i + 1].keys[0] && bucket[0][i].keys[1] == bucket[0][i + 1].keys[1] ? 0 : 1);
    }
}

void debug() {
    int i;
    for(i = 0;i < s.size();i++) SA[RA[i]] = i;
    for(i = 0;i < s.size();i++) cout << i << " " << RA[i] << endl;
    for(i = 0;i < s.size();i++) {
        for(int j = SA[i];j < s.size();j++) cout << s[j];
        cout << endl;
    }
    cout << endl;
}

int main() {
    getline(cin, s); s += s;
    int i, L;
    for(i = 0;i < s.size();i++) {
        bucket[0][i].keys[0] = s[i];
        bucket[0][i].keys[1] = 0;
        bucket[0][i].index = i;
    }
    radix_sort(300);

    for(L = 1;L < s.size();L <<= 1) {
        for(i = 0;i < s.size();i++) {
            bucket[0][i].keys[0] = RA[i];
            bucket[0][i].keys[1] = (i + L < s.size() ? RA[i + L] + 1 : 0);
            bucket[0][i].index = i;
        }
        radix_sort(s.size());
    }
    for(i = 0;i < s.size();i++) SA[RA[i]] = i;
    for(i = 0;i < s.size();i++) if(SA[i] < s.size() / 2) cout << s[SA[i] + s.size() / 2 - 1];
    cout << endl;
}
/*
qwer
*/
