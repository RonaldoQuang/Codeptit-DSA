//Sau khi thi trượt môn Cấu trúc dữ liệu và giải thuật, một số sinh viên D19 CNTT - PTIT quyết định bỏ học, đầu tư thuê đất để trồng rau. 
//Mảnh đất thuê là một hình chữ nhật N x M (1≤ N≤ 100; 1≤ M≤ 100) ô đất hình vuông. 
//Nhưng chỉ sau đó vài ngày, trận lụt khủng khiếp đã diễn ra làm một số ô đất bị ngập. 
//Mảnh đất bỗng biến thành các cái ao. 
//Và sinh viên D19 lại dự định chuyển sang nuôi cá. 
//Các bạn ấy muốn biết mảnh đất được chia thành bao nhiêu cái ao để có thể tính toán nuôi cá cho hợp lý. 
//Hãy giúp các bạn ấy nhé. 
//Chú ý: Ao là gồm một số ô đất bị ngập có chung đỉnh. 
//Dễ nhận thấy là một ô đất có thể có tối đa 8 ô chung đỉnh.
//Dữ liệu vào: Dòng1: 2 số nguyên cách nhau bởi dấu cách: N và M. 
//Dòng 2..N+1: M kí tự liên tiếp nhau mỗi dòng đại diện cho 1 hàng các ô đất.  
//Mỗi kí tự là 'W' hoặc '.' tương ứng với ô đất đã bị ngập và ô đất vẫn còn nguyên.
//Input
//10 12
//W........WW.
//.WWW.....WWW
//....WW...WW.
//.........WW.
//.........W..
//..W......W..
//.W.W.....WW.
//W.W.W.....W.
//.W.W......W.
//..W.......W.
//Output
//3
#include <bits/stdc++.h>
using namespace std;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
void duyet(char a[100][100], int i, int j, int n, int m){
	a[i][j]='.';
	for(int k=0;k<8;k++){
		int i1=i+dx[k], j1=j+dy[k];
		if(i1>=0&&i1<n&&j1>=0&&j1<m&&a[i1][j1]=='W'){
			duyet(a,i1,j1,n,m);
		}
	}
}
int main(){
	int n, m; cin >> n >> m;
	char a[100][100];
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='W'){
				++cnt;
				duyet(a,i,j,n,m);
			}
		}
	}
	cout << cnt << endl; 
}
