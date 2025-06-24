//Trong giấc mơ, Tí thấy mình bị lạc trên hòn đảo với cư dân xa lạ. 
//Không biết làm việc gì, Tí đành phải hái dừa đem bán. 
//Tí muốn làm một tấm biến cho quán hàng cửa mình. Lục tung khắp nơi, Tí kiếm được N miếng gỗ hình chữ nhật, mỗi miếng có chiều dài bằng A[i] và chiều rộng bằng 1. 
//Tí đã ghép N miếng gỗ thành một tấm ván lớn, rồi thực hiện cắt các miếng gỗ để thu được tấm biển.
//Tí muốn tấm biển quảng cáo của mình thật đặc biệt, nên Tí đã chọn nhất định nó sẽ là hình vuông. 
//Không có eke, thước, dây, … nên Tí phải dựa vào các miếng gỗ ban đầu để căn nhát cưa. 
//Việc cưa theo chiều dọc rất dễ dàng, nhưng theo chiều ngang, Tí chỉ có thể cưa theo một đường thẳng trùng với một cạnh của miếng gỗ nào đó.
//Các bạn hãy giúp Tí tính thử xem tấm biển quảng cáo của Tí có kích thước lớn nhất bằng bao nhiêu (kích thước ở đây là độ dài cạnh hình vuông).
//Input
//4
//5 2 4 3 3 1 4
//3
//2 2 2
//2
//6 6
//6
//5 5 5 5 3 1
//Output
//3
//2
//0
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		int max1=0;
		for(int &x:a) cin >> x;
		stack<int> st;
		for(int i=0;i<n;i++){
			if(st.empty()||a[i]>=a[st.top()]) st.push(i);
			else{
				while(!st.empty()&&a[i]<a[st.top()]){
					int x=st.top();
					st.pop();
					if(!st.empty()){
						if(a[x]<=i-st.top()-1) max1=max(max1,a[x]);
					}   
					else{
						if(a[x]<=i) max1=max(max1,a[x]);
					}
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			int x=st.top();
			st.pop();
			if(!st.empty()){
			    if(a[x]<=n-st.top()-1) max1=max(max1,a[x]);
			}
			else{
				if(a[x]<=n) max1=max(max1,a[x]);
			}
		}
		cout << max1 << endl;
	}
}