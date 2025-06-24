//Cho mảng A[] gồm n phần tử. 
//Hãy đưa ra các phần tử nhỏ hơn tiếp theo của phần tử lớn hơn đầu tiên phần tử hiện tại. 
//Nếu phần tử hiện tại không có phần tử lớn hơn tiếp theo ta xem là -1. 
//Nếu phần tử không có phần tử nhỏ hơn tiếp theo ta cũng xem là -1. Ví dụ với mảng A[] = {5, 1, 9, 2, 5, 1, 7} ta có kết quả là ans = {2, 2, -1, 1, -1, -1, -1} vì:
//Next Greater         Right Smaller
//5->9                 9->2
//1->9                 9->2
//9->-1                -1->-1
//2->5                 5->1
//5->7                 7->-1
//1->7                 7->-1
//7->-1                7->-1
//Input
//2
//7
//5 1 9 2 5 1 7
//8
//4 8 2 1 9 5 6 3
//Output
//2 2 -1 1 -1 -1 -1
//2 5 5 5 -1 3 -1 -1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n], b[n], c[n];
		stack<int> st, st1;
		for(int &x:a) cin >> x;
		for(int i=0;i<n;i++){
			if(st.empty()) st.push(i);
			else{
				while(!st.empty()&&a[st.top()]<a[i]){
					b[st.top()]=i;
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			b[st.top()]=-1;
			st.pop();
		}
		for(int i=0;i<n;i++){
			if(st1.empty()) st1.push(i);
			else{
				while(!st1.empty()&&a[st1.top()]>a[i]){
					c[st1.top()]=a[i];
					st1.pop();
				}
				st1.push(i);
			}
		}
		while(!st1.empty()){
			c[st1.top()]=-1;
			st1.pop();
		}
		for(int i=0;i<n;i++){
			if(b[i]!=-1) cout << c[b[i]] << " ";
			else cout << -1 << " ";
		}
		cout << endl;
	}
}