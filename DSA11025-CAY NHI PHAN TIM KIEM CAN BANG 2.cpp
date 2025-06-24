//Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. 
//Đưa ra phép duyệt theo thứ tự trước (preorder) của cây tìm kiếm cân bằng.  
//Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với node gốc là 33 : 33, 25, 20, 15, 23, 28, 30, 40, 38, 35, 45.
//Input
//2
//11
//40  28  45 38  33  15  25  20  23  35  30
//10
//1  2  3  4  5  6  7  8  9  10
//Output
//30 23 15 20 25 28 38 33 35 40 45
//5 2 1 3 4 8 6 7 9 10
#include <bits/stdc++.h>
using namespace std;
void in(int a[], int l, int r){
	if(l>=r) return;
	int m=(l+r-1)/2;
	cout << a[m] << " ";
	in(a,l,m);
	in(a,m+1,r);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int &x:a) cin >> x;
		sort(a,a+n);
		in(a,0,n);
		cout << endl;
	}
}