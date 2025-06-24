//Cho dãy số nguyên A[] có N phần tử.
//Gọi f(i,j) = |ai| + |ai+1| + … + |aj|
//Gọi g(i,j) = ai + ai+1 + … + aj
//Với tất cả các cặp 1 ≤ i ≤ j ≤ N.
//Hãy tính giá trị lớn nhất của f(i,j) + g(i,j).
//Input
//5
//-3 5 -10 8 -2
//Output
//26
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	long long a[n];
	long long sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]>0) sum+=a[i]*2;
	}
	cout << sum;
}