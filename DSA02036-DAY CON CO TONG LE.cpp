//Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.
//Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con (đúng thứ tự trước sau) của A[] có tổng các phần tử là số lẻ.
//Các dãy con được liệt kê theo thứ tự từ điển tăng dần.
//Input
//Dòng đầu ghi số bộ test, mỗi test có 2 dòng:
//Dòng đầu ghi số N (2 < N <15)
//Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
//Output
//Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số lẻ theo thứ tự từ điển tăng dần, mỗi dãy con trên một
//Input
//1
//4
//2 3 4 5
//Output
//3
//3 2
//4 3
//4 3 2
//5
//5 2
//5 4
//5 4 2
#include <bits/stdc++.h>
using namespace std;
void kq(int a[100], int b[100], int n){
	for(int i=n;i>=1;i--){
		if(b[i]==1){
			cout << a[i] << " ";
		}
	}
	cout << endl;
}
void Try(int a[100], int b[100], int i, int n, int sum){
	b[i]=1;
	for(int j=1;j<=i-1;j++){
		b[j]=1;
		sum+=a[j];
		if(sum%2==1){
			kq(a,b,n);
		}
		Try(a,b,j,n,sum);
		b[j]=0;
		sum-=a[j];
	}
	b[i]=0;
}
int main(){
	int t; cin >> t;
	while(t--){
		int a[100], b[100], n; cin >> n;
	    for(int i=1;i<=n;i++){
		    cin >> a[i];
		    b[i]=0;
	    }
	    sort(a+1,a+n+1);
	    for(int i=1;i<=n;i++){
		    int sum=a[i];
		    if(sum%2==1) cout << sum << endl;
		    Try(a,b,i,n,sum);
	    }
	}
}