//Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không biết chọn các cái tên như thế nào cho các đội. 
//Yêu cầu phải đảm bảo tên không có khoảng trống và không được trùng nhau. Sau khi thảo luận, có N cái tên được đề xuất (có thể bị trùng nhau). 
//Với K<15 và 4 < N < 30.
//Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được tạo ra theo thứ tự từ điển.
//Input
//Dòng đầu ghi 2 số N và K.
//Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15 và cách nhau một khoảng trống. Tất cả đều là ký tự in hoa.
//Output
//Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.
//Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ hợp cũng được liệt kê theo thứ tự từ điển.
//Input
//6 2
//DONG TAY NAM BAC TAY BAC
//Output
//BAC DONG
//BAC TAY
//BAC NAM
//DONG NAM
//DONG TAY
//NAM TAY
#include <bits/stdc++.h>
using namespace std;
int c[100], n, k;
string a[100], b[100];
void kq(){
	for(int i=1;i<=k;i++){
		cout << b[c[i]] << " ";
	}
	cout << endl;
}
void Try(int i){
	for(int j=c[i-1]+1;j<=n-k+i;j++){
		c[i]=j;
		if(i==k){
			kq();
		}
		else Try(i+1);
	}
}
int main(){
    cin >> n >> k;
    set<string> se;
    for(int i=1;i<=n;i++){
    	cin >> a[i];
    	se.insert(a[i]);
	}
	int cnt=1;
	for(auto x:se){
		b[cnt]=x;
		++cnt;
	}
	n=se.size();
	sort(b+1,b+cnt);	
	Try(1);
}