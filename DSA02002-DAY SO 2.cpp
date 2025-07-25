//Cho dãy số A[] gồm n số nguyên dương. 
//Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ n là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i+1 (1≤i≤n-1). 
//Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:
//[48]
//[20, 28]
//[8, 12, 16]     
//[3, 5, 7, 9 ]
//[1, 2, 3, 4, 5 ]
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N số của mảng A[].
//T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10;
//Output:
//Đưa ra kết quả mỗi test theo từng dòng. Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].
//Input
//1
//5
//1 2 3 4 5
//Output
//[48] [20 28] [8 12 16] [3 5 7 9 ] [1 2 3 4 5 ]
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[11];
        vector<int> v;
        for(int i=1;i<=n;i++){
        	cin >> a[i];
        	v.push_back(a[i]);
		}
		int k=n;
		while(k>=2){
			for(int i=1;i<=k-1;i++){
				a[i]+=a[i+1];
				v.push_back(a[i]);
			}
			k--;
		}
		cout << "[" << v[v.size()-1] << "] ";
		int m=v.size()-3;
		for(int i=2;i<=n;i++){
			cout << "[";
			for(int j=m;j<=m+i-2;j++){
				cout << v[j] << " ";
			}
			cout << v[m+i-1] << "]";
			m-=i+1;
			cout << " ";
		}
		cout << endl;
    }
}