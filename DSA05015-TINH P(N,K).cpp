//P(n, k) là số phép biểu diễn các tập con có thứ tự gồm k phần tử của tập gồm n phần tử. 
//Số P(n, k) được định nghĩa theo công thức sau: P(n,k)=n!/(n-k)! (k<n)
//Cho số hai số n, k. Hãy tìm P(n,k) theo modulo 109+7.
//Input
//2
//5 2
//4 2
//Output
//20
//12
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long a[1001][1001];
void Pnk(){
	for(int i=1;i<=1000;i++) a[i][1]=i;
	for(int i=2;i<=1000;i++){
		for(int j=2;j<=i;j++){
			a[i][j]=i*a[i-1][j-1];
			a[i][j]%=mod;
		}
	}
}
int main(){
	Pnk();
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		cout << a[n][k] << endl;
	}
}
