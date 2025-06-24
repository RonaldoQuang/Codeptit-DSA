//Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’, còn lại là phụ âm.
//Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <= c <= ‘H’) 
//Sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm.
//Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.
//Input
//Chỉ có một dòng ghi chữ cái c (đảm bảo từ ‘D’ đến ‘H’).
//Output
//Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.
//Input
//D
//Output
//ABCD
//ABDC
//ACBD
//ACDB
//ADBC
//ADCB
//BCDA
//BDCA
//CBDA
//CDBA
//DBCA
//DCBA
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], n;
char c;
int check(){
	int cnt=0;
	for(int i=2;i<=n-1;i++){
		if(a[i]==1){
			if(a[i-1]!=5&&a[i+1]!=5){
				++cnt;
				break;
			}
		}
		else if(a[i]==5){
			if(a[i-1]!=1&&a[i+1]!=1){
				++cnt;
				break;
			}
		}
	}
	if(cnt==0) return 1;
	else return 0;
}
void kq(){
	for(int i=1;i<=n;i++){
		cout << (char) (a[i]+64);
	}
	cout << endl;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(b[j]==1){
			a[i]=j;
			b[j]=0;
			if(i==n){
				if(check()) kq();
			}
			else Try(i+1);
			b[j]=1;
		}
	}
}
int main(){
	cin >> c;
	n=c-64;
	for(int i=1;i<=n;i++) b[i]=1;
	Try(1);
}