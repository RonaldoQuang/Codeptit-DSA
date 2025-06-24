//Cho số nguyên dương N. 
//Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N theo thứ tự ngược. 
//Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
//T, n thỏa mãn ràng buộc: 1≤T, N≤10.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//2
//2
//3
//Output
//21 12
//321 312 231 23 132 123
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100];
void kq(int n){
	for(int i=1;i<=n;i++){
		cout << a[i];
	}
	cout << " ";
}
void Try(int i, int n){
	for(int j=n;j>=1;j--){
		if(b[j]==1){
			a[i]=j;
			b[j]=0;
			if(i==n){
				kq(n);
			}
			else Try(i+1,n);
			b[j]=1;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=1;i<=n;i++) b[i]=1;
		Try(1,n);
		cout << endl;
	}
}