//Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:
//“PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue (0 ≤ x ≤ 1000).
//“PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”.
//“POPFRONT”: Xóa phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả.
//“PUSHBACK x”: Thêm phần tử x vào cuối của dequeue (0 ≤ x ≤ 1000).
//“PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”.
//“POPBACK”: Xóa phần tử cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.
//Input
//10
//PUSHBACK 1
//PUSHFRONT 2
//PUSHBACK 3
//PRINTFRONT
//POPFRONT
//PRINTFRONT
//POPFRONT
//PRINTBACK
//POPFRONT
//PRINTBACK
//Output
//2
//1
//3
//NONE
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	string s;
	int n;
	deque<int> q;
	while(t--){
		cin >> s;
		if(s=="PUSHBACK"){
			cin >> n;
			q.push_back(n);
		}
		else if(s=="PUSHFRONT"){
			cin >> n;
			q.push_front(n);
		}
		else if(s=="POPBACK"){
			if(!q.empty()) q.pop_back();
		}
		else if(s=="POPFRONT"){
			if(!q.empty()) q.pop_front();
		}
		else if(s=="PRINTBACK"){
			if(q.empty()) cout << "NONE" << endl;
			else cout << q.back() << endl;
		}
		else if(s=="PRINTFRONT"){
			if(q.empty()) cout << "NONE" << endl;
			else cout << q.front() << endl;
		}
	}
}