//Cho dãy số A[] có N phần tử. 
//Hãy liệt kê tất cả các tổ hợp chập K của tập các phần tử khác nhau trong A[]. 
//Các tổ hợp cần liệt kê theo thứ tự từ điển (tức là trong mỗi tổ hợp thì giá trị từ nhỏ đến lớn, và tổ hợp sau lớn hơn tổ hợp trước).
//Input
//Dòng đầu ghi hai số N và K.
//Dòng thứ 2 ghi N số của mảng A[]. Các giá trị không quá 1000.
//Dữ liệu đảm bảo số phần tử khác nhau của A[] không quá 20 và K không quá 10.
//Output
//Ghi ra lần lượt các tổ hợp tìm được, mỗi tổ hợp trên một dòng.
//Input
//8 3
//2 4 4 3 5 1 3 4
//Output
//1 2 3
//1 2 4
//1 2 5
//1 3 4
//1 3 5
//1 4 5
//2 3 4
//2 3 5
//2 4 5
//3 4 5
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], c[100], n, k, m, cnt=1;
void kq(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(b[i]==1){
			++cnt;
		    if(cnt!=k) cout << c[i] << " ";
		    else cout << c[i] << endl;
		}
	}
}
void Try(int i){
	b[i]=1;
	for(int j=i+1;j<=m;j++){
		++cnt;
		if(cnt%k==0){
			b[j]=1;
			kq();
		}
		else{
			Try(j);
		}
		b[j]=0;
		cnt-=1;
	}
	b[i]=0;
}
int main(){
	cin >> n >> k;
	memset(b,0,sizeof(b));
	set<int> s;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s.insert(a[i]);
	}
	int dem=1;
	for(auto x:s){
		c[dem]=x;
		++dem;
	}
	m=dem-1;
	for(int i=1;i<=m-k+1;i++){
		Try(i);
	}
}