//Một xâu kí tự S = (s1, s2, .., sn) được gọi là xâu AB độ dài n nếu với mọi siÎS thì si hoặc là kí tự A hoặc si là kí tự B . 
//Ví dụ xâu S = “ABABABAB” là một xâu AB độ dài 8. 
//Cho số tự nhiên N và số tự nhiên K (1£K<N£15 được nhập từ bàn phím), hãy viết chương trình liệt kê tất cả các xâu AB có độ dài N chứa duy nhất một dãy K kí tự A liên tiếp.
//Dữ liệu vào chỉ có một dòng ghi hai số N và K.
//Kết quả ghi ra màn hình theo khuôn dạng:
//Dòng đầu tiên ghi lại số các xâu AB thỏa mãn yêu cầu bài toán;
//Những dòng kế tiếp, mỗi dòng ghi lại một xâu AB thỏa mãn. Các xâu được ghi ra theo thứ tự từ điển.
//Input
//5 3
//Output
//5
//AAABA
//AAABB
//ABAAA
//BAAAB
//BBAAA
#include <bits/stdc++.h>
using namespace std;
void kt(int a[100], int n){
	for(int i=0;i<n;i++){
		a[i]=0;
	}
}
int sinh(int a[100], int n){
	int i=n-1;
	while(i>=0&&a[i]==1){
		a[i]=0;
		--i;
	}
	if(i==-1) return 0;
	else{
		a[i]=1;
		return 1;
	}
}
int check(int a[100], int n, int k){
	string s1="", s2="";
	for(int i=0;i<n;i++){
		s1+=a[i]+'0';
	}
	for(int i=1;i<=k;i++){
		s2+="0";
	}
	int cnt=0;
	for(int i=0;i<=n-k;i++){
		if(s1.substr(i,s2.size())==s2) ++cnt;
	}
	if(cnt==1) return 1;
	else return 0;
}
int main(){
	int n, k; cin >> n >> k;
	vector<string> v;
	int a[100];
	int x=1;
	kt(a,n);
	while(x){
		if(check(a,n,k)){
			string s="";
		    for(int i=0;i<n;i++){
			    if(a[i]==0) s+="A";
			    else s+="B";
		    }
		    v.push_back(s);
		}
		if(sinh(a,n)) x=1;
		else x=0;
	}
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++){
		cout << v[i] << endl;
	}
}