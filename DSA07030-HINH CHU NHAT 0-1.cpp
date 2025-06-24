//Cho một bảng kích thước NxM, được chia thành lưới ô vuông đơn vị N dòng M cột. 
//Trên các ô của bảng ghi số 0 hoặc 1. 
//Các dòng của bảng được đánh số 1, 2... N theo thứ tự từ trên xuống dưới và các cột của bảng được đánh số 1, 2..., M theo thứ tự từ trái qua phải
//Yêu cầu: Hãy tìm một hình chữ nhật gồm các ô của bảng thoả mãn các điều kiện sau:
//1 - Hình chữ nhật đó chỉ gồm các số 1
//2 - Cạnh hình chữ nhật song song với cạnh bảng
//3 - Diện tích hình chữ nhật là lớn nhất có thể
//Input
//1
//11 13
//0 0 0 0 0 1 0 0 0 0 0 0 0
//0 0 0 0 1 1 1 0 0 0 0 0 0
//0 0 1 1 1 1 1 1 1 0 0 0 0
//0 0 1 1 1 1 1 1 1 0 0 0 0
//0 1 1 1 1 1 1 1 1 1 0 0 0
//1 1 1 1 1 1 1 1 1 1 1 0 0
//0 1 1 1 1 1 1 1 1 1 0 0 0
//0 0 1 1 1 1 1 1 1 0 0 0 0
//0 0 1 1 1 1 1 1 1 0 0 0 0
//0 0 0 0 1 1 1 0 0 0 0 1 1
//0 0 0 0 0 1 0 0 0 0 0 1 1
//Output
//49
#include <bits/stdc++.h>
using namespace std;
int tinh(int a[], int n){
	int max1=0;
	stack<int> st;
	for(int i=0;i<n;i++){
		if(st.empty()||a[i]>=a[st.top()]) st.push(i);
		else if(a[i]<a[st.top()]){
			while(!st.empty()&&a[i]<a[st.top()]){
				int x=st.top();
				st.pop();
				if(!st.empty()) max1=max(max1,(i-st.top()-1)*a[x]);
				else max1=max(max1,i*a[x]);
			}
			st.push(i);
		}
	}
	while(!st.empty()){
		int x=st.top();
		st.pop();
		if(!st.empty()) max1=max(max1,(n-st.top()-1)*a[x]);
		else max1=max(max1,n*a[x]);
	}
	return max1;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		int a[n][m], b[n][m]={};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> a[i][j];
			}
		}
		for(int j=0;j<m;j++){
			b[0][j]=a[0][j];
		}
		for(int i=1;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1){
					b[i][j]=b[i-1][j]+1;
				}
			}
		}
		int max1=0;
		for(int i=0;i<n;i++){
			int c[m];
			for(int j=0;j<m;j++){
				c[j]=b[i][j];
			}
			max1=max(max1,tinh(c,m));
		}
		cout << max1 << endl;
	}
}