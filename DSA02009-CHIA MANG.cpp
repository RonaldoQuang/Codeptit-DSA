//Cho mảng các số nguyên A[] gồm N phần tử. 
//Hãy chia mảng số nguyên A[] thành K tập con khác rỗng sao cho tổng các phần tử của mỗi tập con đều bằng nhau. 
//Mỗi phần tử thuộc tập con xuất hiện duy nhất một lần trong tất cả các tập con. 
//Ví dụ với A[] = {2, 1, 4, 5, 6}, K =3 ta có kết quả {2, 4}, {1, 5}, {6}.
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. 
//Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và K; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
//T, N, K, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N, K≤20, 0≤A[i]≤100.
//Output:
//Đưa ra 1 nếu có thể chia tập con thành K tập thỏa mãn yêu cầu bài toán, ngược lại đưa ra 0.
//Input
//2
//5 3
//2 1 4 5 6
//5 3
//2 1 5 5 6
//Ouput
//1
//0
#include <bits/stdc++.h>
using namespace std;
int n, k;
void Try(int a[], int N, int sum, int cnt, int &ok){
	if(ok) return;
	if(cnt==k){
		ok=1;
		return;
	}
	for(int i=0;i<n;i++){
		if(sum==N){
			Try(a,N,0,cnt+1,ok);
		}
		else if(sum<N) Try(a,N,sum+a[i],cnt+1,ok);
		else return;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		int a[n], s=0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			s+=a[i];
		}
		if(s%k!=0) cout << 0 << endl;
		else{
			int N=s/k, ok=0;
			Try(a,N,0,0,ok);
			cout << ok << endl;
		}
	}
}