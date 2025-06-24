//Cho ma trận vuông Ci,j cấp N (1<= i, j <= N<10) gồm N2 số tự nhiên và số tự nhiên K (các số trong ma trận không nhất thiết phải khác nhau và đều không quá 100, K không quá 104). 
//Hãy viết chương trình lấy mỗi hàng, mỗi cột duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.
//Dữ liệu vào: Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C. 
//Kết quả: dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách theo vị trí của số đó trong lần lượt từng hàng của ma trận. Xem ví dụ để hiểu rõ hơn. 
//Input
//3 10
//2 4 3
//1 3 6
//4 2 4
//Output
//2
//1 3 2
//3 2 1
#include <bits/stdc++.h>
using namespace std;
void kq(vector<int> &v, int a[100][100], int b[100][100], int n, int K, int &cnt){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==0) sum+=a[i][j];
		}
	}
	if(sum==K){
		++cnt;
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
			    if(b[i][j]==0) v.push_back(j);
		    }
	    }
	}
}
void Try(vector<int> &v, int a[100][100], int b[100][100], int n, int K, int i, int &cnt){
	for(int j=1;j<=n;j++){
		if(b[i][j]==0){
			for(int k=1;k<=n;k++){
				if(k!=j&&b[i][k]==0) b[i][k]=i;
			}
			for(int k=1;k<=n;k++){
				if(k!=i&&b[k][j]==0) b[k][j]=i;
			}
			if(i==n){
				kq(v,a,b,n,K,cnt);
			}
			else Try(v,a,b,n,K,i+1,cnt);
			for(int k=1;k<=n;k++){
				if(k!=j&&b[i][k]==i) b[i][k]=0;
			}
			for(int k=1;k<=n;k++){
				if(k!=i&&b[k][j]==i) b[k][j]=0;
			}
		}
	}
}
int main(){
	int n, k; cin >> n >> k;
	int a[100][100], b[100][100];
	vector<int> v;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			b[i][j]=0;
		}
	}
	Try(v,a,b,n,k,1,cnt);
	cout << cnt << endl;
	for(int i=0;i<v.size();i++){
		if(i%n==n-1) cout << v[i] << endl;
		else cout << v[i] << " ";
	}
}