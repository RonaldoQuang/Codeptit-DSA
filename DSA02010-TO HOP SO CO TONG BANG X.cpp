//Cho mảng A[] gồm N số nguyên dương phân biệt và số X. 
//Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. 
//Các số trong mảng A[] có thể được sử dụng nhiều lần. 
//Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. 
//Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:
//[2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8].
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. 
//Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
//T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng. Mỗi đường tổ hợp được bao bởi cặp ký tự [, ]. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.
//Input
//1
//4 8
//2 4 6 8
//Output
//[2 2 2 2] [2 2 4] [2 6] [4 4] [8]
#include <bits/stdc++.h>
using namespace std;
void kq(vector<int> v){
	cout << "[";
	for(int i=0;i<v.size();i++){
		if(i<v.size()-1) cout << v[i] << " ";
		else cout << v[i] << "]";
	}
}
void Try(vector<int> v, int a[], int n, int x, int i, int sum,int &cnt){
	for(int j=i;j<=n;j++){
		if(sum+a[j]==x){
			++cnt;
			v.push_back(a[j]);
			kq(v);
		}
		else if(sum+a[j]<x){
			sum+=a[j];
			v.push_back(a[j]);
			Try(v,a,n,x,j,sum,cnt);
			sum-=a[j];
		}
		if(sum+a[j]<=x){
			v.pop_back();
		}
	}
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n, x, cnt=0; cin >> n >> x;
    	int a[n+1];
    	for(int i=1;i<=n;i++){
    		cin >> a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int sum=a[i];
			vector<int> v;
			v.push_back(a[i]);
			Try(v,a,n,x,i,sum,cnt);
		}
		if(binary_search(a+1,a+n+1,x)){
			++cnt;
			cout << "[" << x << "]";
		}
		if(cnt==0) cout << "-1";
		cout << endl;	
	}	
}