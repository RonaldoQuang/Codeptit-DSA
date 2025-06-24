//Cho một mảng S gồm 2×N ký tự, trong đó có N ký tự ‘[’ và N ký tự ‘]’. 
//Xâu S được gọi là viết đúng nếu S có dạng S2[S1] trong đó S, S2 là các xâu viết đúng. 
//Nhiệm vụ của bạn là tìm số các phép đổi chỗ ít nhất các ký tự kề nhau của xâu S viết sai để  S trở thành viết đúng. 
//Ví dụ với xâu S =”[]][][” ta có số phép đổi chỗ kề nhau ít nhất là 2.
//Input
//2
//[]][][
//[][][]
//Output
//2
//0
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<int> st;
		int sum=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='['){
				st.push(i);
			}
			else{
				if(!st.empty()) st.pop();
				else{
					int j=i;
					while(s[j]==']') ++j;
					swap(s[i],s[j]);
					sum+=j-i;
					st.push(i);
				}
			}
		}
		cout << sum << endl;
	}
}