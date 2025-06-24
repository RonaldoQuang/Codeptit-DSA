//Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K. 
//Hãy viết chương trình liệt kê tất cả các dãy con của dãy số A[] sao cho tổng các phần tử trong dãy con đó đúng bằng K. 
//Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các phần tử dãy A:
//Input
//5 50       
//5 10 15 20 25
//Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:
//Mỗi dòng ghi lại một dãy con. 
//Hai phần tử khác nhau của dãy con được viết cách nhau bởi một  khoảng trống.
//Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.
//Output
//10 15 25
//5 20 25
//5 10 15 20
//3
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], n, N, cnt=0;
void kq(){
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			cout << a[i] << " ";
		}
	}
	cout << endl;
}
void Try(int i, int sum){
	b[i]=1;
	for(int j=n;j>=i+1;j--){
		if(a[j]<N){
			b[j]=1;
			sum+=a[j];
			if(sum==N){
				kq();
				++cnt;
			}
			else if(sum<N){
			    Try(j,sum);
			}
			b[j]=0;
			sum-=a[j];
		}
	}
	b[i]=0;
}
int main(){
	cin >> n >> N;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(binary_search(a+1,a+n+1,N)){
		cout << N << endl;
		++cnt;
	}
	for(int i=1;i<=n;i++) b[i]=0;
	for(int i=n;i>=1;i--){
		    int sum=a[i];
		    Try(i,sum);
	}
	cout << cnt;
}