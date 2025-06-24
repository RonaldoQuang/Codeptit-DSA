//Cho dãy số a[] có n phần tử, đánh số từ 1 đến n. 
//Hãy sắp xếp các phần tử ở vị trí lẻ theo thứ tự tăng dần, các phần tử ở vị trí chẵn theo thứ tự giảm dần.
//Input
//4
//1 2 3 4
//Output
//1 4 3 2
#include <bits/stdc++.h>
using namespace std;
int main(){ 
	int n; cin >> n;
	int a[n+1], b[n], c[n], cnt=1, dem=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i%2==1){
			b[cnt]=a[i];
			++cnt;
		}
		else{
			c[dem]=a[i];
			++dem;
		}
	}
	sort(b+1,b+cnt);
	sort(c+1,c+dem);
	int t=n/2;
	for(int i=1;i<=t;i++){
		cout << b[i] << " ";
		cout << c[t+1-i] << " ";
	}
	if(n%2==1) cout << b[t+1];
	cout << endl;
}