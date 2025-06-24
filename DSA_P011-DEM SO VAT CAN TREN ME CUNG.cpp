//Một mê cung được mô tả dưới dạng ma trận ký tự trong đó dấu ‘.’ là mô tả ô trống, không có vật cản, dấu ‘#’ mô tả một vật cản. 
//Các vật cản sẽ ghép lại với nhau thành vật cản lớn hơn nếu nó liền kề theo hàng hoặc cột.
//Hãy đếm xem trong mê cung có bao nhiêu vật cản.
//Input
//Dong đầu ghi số hai số N, M (N, M <= 1000) là số hàng và số cột của mê cung.
//N dòng tiếp theo mô tả mê cung trong đó chỉ có các ký tự ‘.’ và ‘#’.
//Output
//Ghi ra số vật cản đếm được.
//Input
//5 6
//.#....
//..#...
//..#..#
//...##.
//.#....
//Output
//5
#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
void duyet(char a[100][100], int i, int j, int n, int m){
	a[i][j]='.';
	for(int k=0;k<4;k++){
		int i1=i+dx[k], j1=j+dy[k];
		if(i1>=0&&i1<n&&j1>=0&&j1<m&&a[i1][j1]=='#'){
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
			if(a[i][j]=='#'){
				++cnt;
				duyet(a,i,j,n,m);
			}
		}
	}
	cout << cnt << endl; 
}