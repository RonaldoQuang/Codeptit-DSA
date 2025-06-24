//Hãy viết chương trình nhận vào một chuỗi (có thể khá dài) các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký tự số đó (với ý nghĩa là hoán vị có giá trị lớn hơn tiếp theo nếu ta coi chuỗi đó là một giá trị số nguyên). 
//Chú ý: Các ký tự số trong dãy có thể trùng nhau.
//Ví dụ:               123 -> 132
//279134399742 -> 279134423799  
//Cũng có trường hợp sẽ không thể có hoán vị kế tiếp. 
//Ví dụ như khi đầu vào là chuỗi 987.
//Dữ liệu vào: Dòng đầu tiên ghi số nguyên  t là số bộ test (1 ≤ t ≤ 1000).  
//Mỗi bộ test có một dòng, đầu tiên là số thứ tự bộ test, một dấu cách, sau đó là chuỗi các ký tự số, tối đa 80 phần tử.  
//Kết quả: Với mỗi bộ test hãy đưa ra một dòng gồm thứ tự bộ test, một dấu cách, tiếp theo đó là hoán vị kế tiếp hoặc chuỗi “BIGGEST” nếu không có hoán vị kế tiếp. 
//Input
//3
//1 123
//2 279134399742
//3 987
//Output
//1 132
//2 279134423799
//3 BIGGEST
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int m; cin >> m;
    	string s; cin >> s;
		int n=s.size();
		int a[n+1];
		for(int i=1;i<=n;i++){
			a[i]=s[i-1]-'0';
		}
		int i=n-1;
		while(i>=1){
			if(a[i]<a[i+1]){
				int min=1e9;
				for(int j=i+1;j<=n;j++){
					if(a[j]<min&&a[j]>a[i]) min=j;
				}
				swap(a[i],a[min]);
				sort(a+i+1,a+n+1);
				break;
			}
			else{
				i--;
			}
		}
		if(i>=1){
			cout << m << " ";
			for(int j=1;j<=n;j++){
				cout << a[j];
			}
			cout << endl;
		}
		else{
			cout << m << " BIGGEST" << endl;
		}
	}
}