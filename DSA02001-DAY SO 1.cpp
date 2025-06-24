//Cho dãy số A[] gồm n số nguyên dương. 
//Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ 1 là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i-1 (2≤i≤n). 
//Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:
//[1, 2, 3, 4, 5 ]
//[3, 5, 7, 9 ]
//[8, 12, 16]
//[20, 28]
//[48]
// Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N số của mảng A[].
//T, N, A[i] thỏa mãn ràng buộc: 1 ≤ T ≤ 100; 1 ≤ N ≤ 10, 0 ≤ A[i] ≤ 10;
//Output:
//Đưa ra tam giác tổng của mỗi test theo từng dòng. Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].
//Input
//1
//5
//1 2 3 4 5
//Output
//[1 2 3 4 5]
//[3 5 7 9]
//[8 12 16]
//[20 28]
//[48]
#include <bits/stdc++.h>
using namespace std;
void kq(int a[11], int k){
	cout << "[";
	for(int i=1;i<=k-1;i++){
		cout << a[i] << " ";
	}
	cout << a[k] << "]" << endl;
}
void Try(int a[11], int i, int k){
	a[i]+=a[i+1];
	if(i==k){
		kq(a,k);
	}
	else{
		Try(a,i+1,k);
	}
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[11];
        for(int i=1;i<=n;i++){
        	cin >> a[i];
		}
		cout << "[";
		for(int i=1;i<=n-1;i++){
			cout << a[i] << " ";
		}
		cout << a[n] << "]" << endl;
		for(int k=n-1;k>=1;k--){
			Try(a,1,k);
		}
    }
}