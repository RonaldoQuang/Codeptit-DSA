//Cho biểu thức đúng P chỉ bao gồm các phép toán +, -, các toán hạng cùng với các ký tự ‘(’, ‘)’. 
//Hãy bỏ tất cả các ký tự ‘(’, ‘)’ trong P để nhận được biểu thức tương đương. 
//Ví dụ với P = a – (b + c) ta có kết quả P = a – b – c .
//Input
//2
//a–(b+c)
//a-(b-c-(d+e))-f
//Output
//a-b-c
//a-b+c+d+e-f
#include <bits/stdc++.h>
using namespace std;
char chuyen(char a){
	if(a=='+') return '-';
	else if(a=='-') return '+';
}
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<char> st;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]!='('){
				st.push(s[i]);
			}
			else{
				string a="";
				while(st.top()!=')'){
					a+=st.top();
					st.pop();
				}
				st.pop();
				if(s[i-1]=='-'){
					for(int j=a.size()-1;j>=0;j--){
						if(a[j]=='+'||a[j]=='-') st.push(chuyen(a[j]));
						else st.push(a[j]);
					}
				}
				else{
					for(int j=a.size()-1;j>=0;j--){
						st.push(a[j]);
					}
				}
			}			
		}
		while(!st.empty()){
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}
