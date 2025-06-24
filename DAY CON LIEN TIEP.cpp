//Cho dãy số A[] có N phần tử, N không quá 105, các số trong dãy đều nguyên dương và không quá 9 chữ số. 
//Hãy tính độ dài của dãy con liên tiếp có trung bình cộng lớn nhất trong dãy.
//Trong trường hợp có nhiều dãy con liên tiếp đều có trung bình cộng lớn nhất thì dãy nào dài hơn sẽ được chọn.
//Input
//5
//5 1 6 7 2
//Output
//1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	int a[n], max1=1, m=-1e9;
	for(int i=0;i<n;i++){
		cin >> a[i];
		m=max(m,a[i]);
	}
	int i=0;
	while(i<n){
		if(a[i]==m){
			int cnt=0;
			while(a[i]==m){
				++cnt;
				++i;
			}
			max1=max(max1,cnt);
		}
		else ++i;
	}
	cout << max1;
}