//Cho dãy số A[] gồm N phần tử. 
//Với mỗi A[i], bạn cần tìm phần tử bên phải đầu tiên lớn hơn nó. 
//Nếu không tồn tại, in ra -1.
//Input
//3
//4
//4 5 2 25
//3
//2 2 2
//4
//4 4 5 5
//Output
//5 25 25 -1
//-1 -1 -1
//5 5 -1 -1
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[n], b[n];
    	for(int &x:a) cin >> x;
    	stack<int> st;
    	for(int i=0;i<n;i++){
    		if(st.empty()){
    			st.push(i);
			}
			else{
				while(!st.empty()&&a[st.top()]<a[i]){
					b[st.top()]=a[i];
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			b[st.top()]=-1;
			st.pop();
		}
		for(int &x:b) cout << x << " ";
		cout << endl;
	}	
}