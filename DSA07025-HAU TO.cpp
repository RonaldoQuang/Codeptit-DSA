//Biểu thức dưới dạng hậu tố là phép biểu diễn biểu thức trong đó phép toán được đặt sau hai toán hạng. 
//Ví dụ AB+CD-* (tương ứng với biểu thức trung tố (A+B)*(C-D).
//Hãy viết chương trình tính toán giá trị của biểu thức hậu tố.
//Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
//Mỗi test bắt đầu bởi số nguyên N (N ≤ 1000), là số lượng toán tử và toán hạng.
//Dòng tiếp theo là biểu thức hậu tố với N toán tử và toán hạng. 
//Các toán hạng và toán tử cách nhau bởi một dấu cách.
//Các toán hạng có thể có nhiều chữ số, có thể là số âm. 
//Phép chia thực hiện trên số nguyên. 
//Input đảm bảo kết quả phép toán có giá trị tuyệt đối không vượt quá 10^18.
//Input
//3
//7
//2 3 1 * + 9 –
//7
//8 7 5 * + 9 –
//3
//-10 -4 +
//Output
//-4
//34
//-14
#include <bits/stdc++.h>
using namespace std;
long long tinh(long long x, long long y, string z){
	if(z=="+") return x+y;
	if(z=="-") return x-y;
	if(z=="*") return x*y;
	if(z=="/") return x/y;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		stack<long long> st;
		for(int i=0;i<n;i++){
			if(a[i]!="+"&&a[i]!="-"&&a[i]!="*"&&a[i]!="/") st.push(stoll(a[i]));
			else{
				long long y=st.top(); st.pop();
				long long x=st.top(); st.pop();
				st.push(tinh(x,y,a[i]));
			}
		}
		cout << st.top() << endl;
	}
}