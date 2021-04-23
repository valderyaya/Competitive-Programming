#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
typedef long long ll;
using namespace std;
int main(){
	int a, b,arr[100][100];
	while (cin >> a >> b) {
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++)
				cin >> arr[i][j];
		}
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < a; j++)
				cout << arr[j][i] << ' ';
			cout << endl;
		}
	}
	return 0;
}
