//Cho một xâu chỉ gồm các kí tự ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’. Một dãy ngoặc đúng được định nghĩa như sau:
//-Xâu rỗng là 1 dãy ngoặc đúng.
//-Nếu A là 1 dãy ngoặc đúng thì (A), [A], {A} là 1 dãy ngoặc đúng.
//-Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.
//Cho một xâu S. Nhiệm vụ của bạn là xác định xâu S có là dãy ngoặc đúng hay không?
//Input
//2
//[()]{}{[()()]()}
//[(])
//Output
//YES
//NO
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	stack<char> st;
    	int i=0, cnt=0;
    	while(i<s.size()){
    		if(s[i]=='['||s[i]=='('||s[i]=='{'){
    			st.push(s[i]);
			}
			else{
				if(s[i]==']'){
					if(!st.empty()&&st.top()=='['){
						st.pop();
					}
					else{
						++cnt;
						break;
					}
				}
				if(s[i]==')'){
					if(!st.empty()&&st.top()=='('){
						st.pop();
					}
					else{
						++cnt;
						break;
					}
				}
				if(s[i]=='}'){
					if(!st.empty()&&st.top()=='{'){
						st.pop();
					}
					else{
						++cnt;
						break;
					}
				}
			}
			++i;
		}
		if(cnt==0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
}