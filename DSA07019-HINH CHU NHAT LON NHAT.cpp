//Cho N cột, mỗi cột có chiều cao bằng H[i]. 
//Bạn hãy tìm hình chữ nhật lớn nhất bị che phủ bởi các cột?
//Input
//2
//7
//6 2 5 4 5 1 6
//3
//2 2 2
//Output
//12
//6
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long a[n];
		long long max1=-1e9;
		for(long long &x:a) cin >> x;
		stack<int> st;
		for(int i=0;i<n;i++){
			if(st.empty()||a[i]>=a[st.top()]) st.push(i);
			else if(a[i]<a[st.top()]){
				while(!st.empty()&&a[i]<a[st.top()]){
					int x=st.top();
					st.pop();
					if(!st.empty()) max1=max(max1,(long long) (i-st.top()-1)*a[x]);
					else max1=max(max1,(long long) i*a[x]);
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			int x=st.top();
			st.pop();
			if(!st.empty()) max1=max(max1,(long long) (n-st.top()-1)*a[x]);
			else max1=max((long long) max1,n*a[x]);
		}
		cout << max1 << endl;
	}
}