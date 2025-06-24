//Cho mảng A[] gồm n phần tử và số X. 
//Hãy đưa sắp xếp các phần tử của mảng theo trị tuyệt đối của |X - A[i] |. 
//Ví dụ với A[] = {10, 5, 3, 9, 2} và X = 7 ta đưa ra mảng được sắp xếp theo nguyên tắc kể trên: A[] = {5, 9, 10, 3, 2} vì |7-10|=3, |7-5|=2, |7-3|=4, |7-9|=2, |7-2|=5. 
//Trong trường hợp có nhiều phần tử có giá trị tuyệt đối như nhau, ưu tiên theo thứ tự số xuất hiện trước trong mảng ban đầu.
//Input
//2
//5 7
//10 5 3 9 2
//5 6
//1 2 3 4 5
//Output
//5 9 10 3 2
//5 4 3 2 1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n,X; cin >> n >> X;
		int a[n];
		multimap<int,int> mp;
		for(int i=0;i<n;i++){
			cin >> a[i];
			mp.insert({abs(X-a[i]),a[i]});
		}
		for(auto x:mp){
			cout << x.second << " ";
		}
		cout << endl;
	}
}