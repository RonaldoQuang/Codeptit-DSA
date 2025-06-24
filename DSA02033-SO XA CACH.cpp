//Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn:
//K không chứa chữ số 0
//Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần
//Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1. 
//Hãy liệt kê tất cả các số thỏa mãn theo thứ tự tăng dần.
//Input
//Dòng đầu ghi số bộ test (không quá 10)
//Mỗi bộ test là 1 số nguyên dương N (2 < N < 10)
//Output
//Liệt kê tất cả các số thỏa mãn, mỗi số trên một dòng.
//Sau mỗi test in ra một khoảng trống.
//Input
//2
//3
//4
//Output
//2413
//3142
#include <bits/stdc++.h>
using namespace std;
int check(int a[100], int n){
	int cnt=0;
	for(int i=1;i<=n-1;i++){
		if(abs(a[i]-a[i+1])==1){
			++cnt;
			break;
		}
	}
	if(cnt==0) return 1;
	else return 0;
}
void kq(int a[100], int n){
	for(int i=1;i<=n;i++){
		cout << a[i];
	}
	cout << endl;
}
void Try(int a[100], int b[100], int i, int n){
	for(int j=1;j<=n;j++){
		if(b[j]==1){
			a[i]=j;
			b[j]=0;
			if(i==n){
				if(check(a,n)) kq(a,n);
			}
			else Try(a,b,i+1,n);
			b[j]=1;
		}
	}
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[100], b[100];
    	for(int i=1;i<=n;i++) b[i]=1;
    	Try(a,b,1,n);
	}
}