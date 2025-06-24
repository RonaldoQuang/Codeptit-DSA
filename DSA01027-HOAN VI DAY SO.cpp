//Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. 
//Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là hoán vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng giảm dần từ trái qua phải.
//Input
//Dòng đầu ghi số N (1 < N < 9)
//Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)
//Output
//Ghi mỗi hoán vị của dãy số trên một dòng
//Input
//3
//88 77 99
//Output
//77 88 99
//77 99 88
//88 77 99
//88 99 77
//99 77 88
//99 88 77
#include <bits/stdc++.h>
using namespace std;
int n, a[100], b[100], c[100];
void kq(){
	for(int i=1;i<=n;i++){
		cout << a[c[i]] << " ";
	}
	cout << endl;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(b[j]==1){
			c[i]=j;
			b[j]=0;
			if(i==n){
				kq();
			}
			else Try(i+1);
			b[j]=1;
		}
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=1;
	}
	sort(a+1,a+n+1);
	Try(1);
}