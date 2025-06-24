//Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).
//Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. 
//Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.
//Xem ví dụ để hiểu thêm yêu cầu đề bài.
//Input
//Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.
//Output
//Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.
//Input
//D 2
//Output
//AA
//AB
//AC
//AD
//BB
//BC
//BD
//CC
//CD
//DD
#include <bits/stdc++.h>
using namespace std;
int a[100], n, k;
char x;
void kq(){
	for(int i=1;i<=k;i++){
		cout << (char) (a[i]+64);
	}
	cout << endl;
}
void Try(int i){
	for(int j=a[i-1];j<=n;j++){
		a[i]=j;
		if(i==k){
			kq();
		}
		else Try(i+1);
	}
}
int main(){
    cin >> x >> k;
    a[0]=1;
    n=x-64;
    Try(1);
}