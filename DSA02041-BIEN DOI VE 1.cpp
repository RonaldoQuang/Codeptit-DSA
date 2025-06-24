//Biểu thức dưới dạng hậu tố là phép biểu diễn biểu thức trong đó phép toán được đặt sau hai toán hạng. 
//Ví dụ AB+CD-* (tương ứng với biểu thức trung tố (A+B)*(C-D).
//Hãy viết chương trình tính toán giá trị của biểu thức hậu tố.
//Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//Mỗi test bắt đầu bởi số nguyên N (N ≤ 1000), là số lượng toán tử và toán hạng.
//Dòng tiếp theo là biểu thức hậu tố với N toán tử và toán hạng. 
//Cho số nguyên dương N. 
//Hãy đếm số bước ít nhất để đưa N về 1 bằng cách thực hiện ba thao tác dưới đây:
//Nếu N chia hết cho 2 bạn có thể giảm N = N/2.
//Nếu N chia hết cho 3 bạn có thể giảm N = N/3.
//Giảm N đi 1.
//Input:
///Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được viết trên một dòng.
//T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100000.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//2
//10
//6
//Output
//3
//2
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		queue<pair<int,int>> q;
		q.push({n,0});
		while(1){
			pair<int,int> x=q.front();
			q.pop();
			if(x.first==1){
				cout << x.second << endl;
				break;
			}
			if(x.first%3==0){
				q.push({x.first/3,x.second+1});
			}
			if(x.first%2==0){
				q.push({x.first/2,x.second+1});
			}
			q.push({x.first-1,x.second+1});
		}
	}
}