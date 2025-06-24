//Yêu cầu bạn xây dựng một stack với các truy vấn sau đây:
//“PUSH x”: Thêm phần tử x vào stack (0 ≤ x ≤ 1000).
//“PRINT”: In ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.
//“POP”: Xóa phần tử đầu tiên của stack. Nếu stack rỗng, không làm gì cả.
//Input
//9
//PUSH 1
//PUSH 2
//POP
//PRINT
//PUSH 3
//PRINT
//POP
//POP
//PRINT
//Output
//1
//3
//NONE
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
    stack<int> st;
    while(t--){
    	string s; cin >> s;
    	if(s=="PUSH"){
    		int x; cin >> x;
    		st.push(x);
		}
		else if(s=="PRINT"){
			if(st.empty()) cout << "NONE" << endl;
			else{
				cout << st.top() << endl;
			}
		}
		else if(s=="POP"){
			if(!st.empty()) st.pop();
		}
	}
}