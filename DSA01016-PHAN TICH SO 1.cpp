//Cho số nguyên dương N. 
//Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. 
//Phép hoán vị vủa một cách được xem là giống nhau. 
//Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
//T, n thỏa mãn ràng buộc: 1≤T, N≤10.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//2
//4
//5
//Output
//(4) (3 1) (2 2) (2 1 1) (1 1 1 1)
//(5) (4 1)  (3 2)  (3 1 1) (2 2 1)  (2 1 1 1)  (1 1 1 1 1)
#include <bits/stdc++.h>
using namespace std;
int n, sum=0;
vector<int> v;
void kq(){
	cout << "(";
	for(int i=0;i<v.size();i++){
		if(i<v.size()-1) cout << v[i] << " ";
		else cout << v[i] << ")";
	}
	cout << " ";
}
void Try(int i){
	for(int j=i;j>=1;j--){
		sum+=j;
		v.push_back(j);
		if(sum==n) kq();
		else if(sum<n) Try(j);
		sum-=j;
		v.pop_back();
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
	    Try(n);
	    cout << endl;
	}
}
