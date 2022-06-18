#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
typedef long long ll;
using namespace std;

int main(){
	string n[] = { "1/1" ,"5/6","2/3","1/2","1/3","1/6"};
	int a, b;
	cin >> a >> b;
	cout << n[max(a, b) - 1];
	return 0;
}
