//Cho một mảng A[] gồm N phần tử. 
//Nhiệm vụ của bạn là đưa ra 1 nếu mảng A[] biểu diễn phép duyệt inorder của cây nhị phân tìm kiếm, ngược lại đưa ra 0.
//Input
//3
//5
//10 20 30 40 50
//6
//90 80 100 70 40 30
//3
//1 1 2
//Output
//1
//0
//1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		int ok=1;
		for(int i=1;i<n;i++){
			if(a[i]<a[i-1]){
				ok=0;
				break;
			}
		}
		cout << ok << endl;
	}
}