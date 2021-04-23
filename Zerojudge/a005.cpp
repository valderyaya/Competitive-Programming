#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int n,a[4];
	cin >> n;
	while (n--){
		for (int i = 0; i < 4; i++)
			cin >> a[i];
		if (a[2] - a[1] == a[1] - a[0]){
			for (int i = 0; i < 4; i++)
				cout << a[i] << " ";
			cout << a[3] + a[1] - a[0] << endl;
		}
		else {
			for (int i = 0; i < 4; i++)
				cout << a[i] << " ";
			cout << a[3] * (a[1] / a[0]) << endl;
		}
	}
}
