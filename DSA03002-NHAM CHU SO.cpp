//Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. 
//Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. 
//Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.  
//Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.
//Input
//16796 58786
//Output
//74580 85582
#include <bits/stdc++.h>
using namespace std;
long long min(string a, string b){
	for(int i=0;i<a.size();i++){
		if(a[i]=='6') a[i]='5';
	}
	for(int i=0;i<b.size();i++){
		if(b[i]=='6') b[i]='5';
	}
	return stoll(a)+stoll(b);
}
long long max(string a, string b){
	for(int i=0;i<a.size();i++){
		if(a[i]=='5') a[i]='6';
	}
	for(int i=0;i<b.size();i++){
		if(b[i]=='5') b[i]='6';
	}
	return stoll(a)+stoll(b);
} 
int main(){
    string a, b; cin >> a >> b;
    cout << min(a,b) << " " << max(a,b);
}