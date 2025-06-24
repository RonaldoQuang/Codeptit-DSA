//Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một. 
//Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính chất tăng dần.
//Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu.
//Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê theo thứ tự từ điển.
//Input
//Dòng đầu ghi số n (không quá 20)
//Dòng thứ 2 ghi n số của dãy a[]. Các số khác nhau từng đôi một và có giá trị không quá 100.
//Output
//Ghi ra lần lượt các dãy con tăng dần theo thứ tự từ điển.
//Input
//4
//6 3 7 11
//Output
//3 11
//3 7
//3 7 11
//6 11
//6 7
//6 7 11
//7 11
#include <bits/stdc++.h>
using namespace std;
void kq(string a[], int b[], int n){
	for(int i=1;i<=n;i++){
		if(b[i]==1) cout << a[i] << " ";
	}
	cout << endl;
}
void Try(map<string,int> mp, string a[], string d[], int b[], int i, int n){
	b[mp[d[i]]]=1;
	for(int j=1;j<=n;j++){
		if(d[j].size()>d[i].size()&&mp[d[j]]>mp[d[i]]){
			b[mp[d[j]]]=1;
			kq(a,b,n);
			Try(mp,a,d,b,j,n);
			b[mp[d[j]]]=0;
		}
		if(d[j].size()==d[i].size()&&mp[d[j]]>mp[d[i]]&&d[j]>d[i]){
			b[mp[d[j]]]=1;
			kq(a,b,n);
			Try(mp,a,d,b,j,n);
			b[mp[d[j]]]=0;
		}
	}
	b[mp[d[i]]]=0;
}
int main(){
    int n; cin >> n;
    int c[n+1], b[n+1];
    memset(b,0,sizeof(b));
	string a[n+1], d[n+1];
	map<string,int> mp;
    for(int i=1;i<=n;i++){
    	cin >> c[i];
    	a[i]=to_string(c[i]);
    	d[i]=a[i];
    	mp[d[i]]=i;
	}
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++){
		Try(mp,a,d,b,i,n);
	}
}