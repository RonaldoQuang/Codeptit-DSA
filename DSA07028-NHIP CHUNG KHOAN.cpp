//Bạn là một nhà đầu tư chứng khoán nổi tiếng. 
//Nhiệm vụ hàng ngày của bạn là tính nhịp tăng giảm của phiên chứng khoán trong N ngày để có thể bắt kịp thị trường. 
//Nhịp chứng khoán của ngày thứ i được định nghĩa là số ngày liên tiếp từ ngày thứ i trở về mà giá chứng khoán bé hơn hoặc bằng với giá chứng khoán của ngày i.
//Input
//1
//7
//100 80 60 70 60 75 85
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		for(int i=1;i<=n;i++) cin >> a[i];
		stack<int> st;
		for(int i=1;i<=n;i++){
			while(!st.empty()&&a[i]>=a[st.top()]){
				st.pop();
			}
			if(st.empty()) cout << i << " ";
			else cout << i-st.top() << " ";
			st.push(i);
		}
		cout << endl;
	}
}