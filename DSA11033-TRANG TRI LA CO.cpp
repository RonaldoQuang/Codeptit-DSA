//Cho một lá cờ có kích thước N x M. Mỗi hàng được trang trí một dải huy hiệu từ vị trí (i, U[i]) tới (i, V[i]).
//Cho Q truy vấn, mỗi truy vấn yêu cầu bạn cần xác định xem tại các vị trí cột C[1], C[2], …, C[Q] sẽ có bao nhiêu huy hiệu?
//Input:
//Dòng đầu tiên là số lượng hàng N.
//Dòng tiếp theo gồm N cặp số (U[i], V[i]) cho biết mô tả của một dải huy hiệu.
//Tiếp theo là số lượng truy vấn Q.
//Dòng cuối gồm Q (Q ≤ 105) số nguyên C[1], C[2], …, C[Q].
//Output: 
//In ra Q dòng, dòng thứ i cho biết số lượng huy hiệu có trên vị trí cột C[i].
//Giới hạn: 
//Subtask 1 (40%): N ≤ 1000, 1 ≤ U[i], V[i] ≤ 1000.
//Subtask 2 (40%): N ≤ 106, 1 ≤ U[i], V[i] ≤ 106.
//Subtask 3 (20%): N ≤ 106, 1 ≤ U[i], V[i] ≤ 109.
//Input
//3
//1 7
//3 8
//5 6
//3
//2 3 5
//Output
//1
//2
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	int a[n], b[n];
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	int q; cin >> q;
	while(q--){
		int x; cin >> x;
		int it=upper_bound(a,a+n,x)-a;
		int it1=upper_bound(b,b+n,x-1)-b;
		cout << it-it1 << endl;
	}
}