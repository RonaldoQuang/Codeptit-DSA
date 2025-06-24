//Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:
//-Xâu rỗng là 1 dãy ngoặc đúng.
//-Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.
//-Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.
//Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.
//Input
//3
//((()
//)()())
//()(()))))
//Output
//2
//4
//6
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	string s; cin >> s;
    	stack<int> st;
    	st.push(-1);
		int max1=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='(') st.push(i);
			else{
				st.pop();
				if(st.size()>0) max1=max(max1,i-st.top());
				if(st.empty()) st.push(i);
			}
		}
		cout << max1 << endl;
	}	
}