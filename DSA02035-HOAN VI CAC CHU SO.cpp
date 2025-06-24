//Độ chênh lệch của một dãy số nguyên dương được định nghĩa là hiệu của số lớn nhất trừ đi số nhỏ nhất trong dãy.
//Cho hai số nguyên dương n và k, với 1 <= n, k <= 8.
//Với n xâu ký tự số có độ dài k, có thể có chữ số 0 ở đầu. 
//Hãy tìm cách duyệt tất cả hoán vị các chữ số của từng số trong danh sách sao cho độ chênh lệch của dãy số tạo được là bé nhất có thể.
//Input
//Dòng đầu ghi hai số n và k.
//Tiếp theo là n dòng, mỗi dòng ghi một xâu ký tự đúng k chữ số.
//Output
//Ghi ra độ chênh lệch bé nhất có thể.
//Input
//6 4
//5237
//2753
//7523
//5723
//5327
//2537
//Output
//2700
#include <bits/stdc++.h>
using namespace std;
int n, k, min1=1e9;
int a[10], b[10];
string s1[10], s2[10];
void kq(){
	for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            s2[i][j]=s1[i][a[j]];
        }
    }
    sort(s2,s2+n);
    min1=min(min1,stoi(s2[n-1])-stoi(s2[0]));
}
void Try(int i) {
    for(int j=0;j<k;j++) {
        if(b[j]) {
            a[i]=j;
            b[j]=0;
            if(i==k-1) kq();
            else Try(i+1);
            b[j]=1;
        }
    }
}

int main(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> s1[i];
		s2[i]=s1[i];
	}
	for(int i=0;i<k;i++) b[i]=1;
	Try(0);
	cout << min1;
}