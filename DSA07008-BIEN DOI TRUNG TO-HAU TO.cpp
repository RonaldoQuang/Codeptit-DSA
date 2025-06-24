//Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng trung tố về dạng hậu tố. 
//Input
//2
//(A+(B+C))
//((A*B)+C)
//Output
//ABC++
//AB*C+
#include <bits/stdc++.h>
using namespace std;
int price(char c){
	if(c=='^') return 3;
	if(c=='*'||c=='/') return 2;
	if(c=='+'||c=='-') return 1;
	return 0;
}
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<char> st;
		for(char x:s){
			if(x=='(') st.push(x);
			else if(x==')'){
				while(!st.empty()&&st.top()!='('){
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else if(x=='^'||x=='*'||x=='/'||x=='+'||x=='-'){
				while(!st.empty()&&price(st.top())>=price(x)){
					cout << st.top();
					st.pop();
				}
				st.push(x);
			}
			else cout << x;
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}