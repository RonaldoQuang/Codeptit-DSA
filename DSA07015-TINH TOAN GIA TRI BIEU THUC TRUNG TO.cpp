//Cho biểu thức trung tố S với các toán tử +, -, *, / và dấu ngoặc (). 
//Các toán hạng là các số có giá trị không vượt quá 100. Hãy tính giá trị biểu thức S. 
//Phép chia thực hiện với số nguyên, input đảm bảo số bị chia luôn khác 0, đáp số biểu thức có không quá 10 chữ số.
//Input
//4
//6*3+2-(6-4/2)
//100+99*22
//6*((4*3)+5)
//1-2
//Output
//16
//2278
//102
//-1
#include <bits/stdc++.h>
using namespace std;
int price(char c){
	if(c=='*'||c=='/') return 2;
	if(c=='+'||c=='-') return 1;
	return 0;
}
long long tinh(long long a, long long b, char c){
	if(c=='+') return a+b;
	if(c=='-') return a-b;
	if(c=='*') return a*b;
	if(c=='/') return a/b;
}
long long kq(string s){
	stack<long long> st;
	int i=0;
	while(i<s.size()){
		if(s[i]<='9'&&s[i]>='0'){
			long long a=0;
			while(s[i]<='9'&&s[i]>='0'){
				a=a*10+s[i]-'0';
				++i;
			}
			st.push(a);
			i-=1;
		}
		if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
			long long b=st.top(); st.pop();
			long long a=st.top(); st.pop();
			st.push(tinh(a,b,s[i]));
		}
		++i;
	}
	return st.top();
}
int main(){
	int t; cin >> t;
	while(t--){
		string s, w=""; cin >> s;
		stack<char> st;
		int i=0;
		while(i<s.size()){
			if(s[i]=='(') st.push(s[i]);
			else if(s[i]==')'){
				while(!st.empty()&&st.top()!='('){
					w+=st.top();
					st.pop();
				}
				st.pop();
			}
			else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'){
				while(!st.empty()&&price(st.top())>=price(s[i])){
					w+=st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else{
				while(s[i]<='9'&&s[i]>='0'){
					w+=s[i];
					++i;
				}
				i-=1;
				w+=" ";
			}
			++i;
		}
		while(!st.empty()){
			if(st.top()!='(') w+=st.top();
			st.pop();
		}
		cout << kq(w) << endl;
	}
}