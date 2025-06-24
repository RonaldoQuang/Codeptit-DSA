//Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng khoái. Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.
//Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:
//-Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
//-Không có hai chữ H nào liền nhau
//Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.
//Input
//Dòng đầu ghi số bộ test T (không quá 10)
//Mỗi bộ test ghi độ dài N (2 <= N < 16)
//Output
//Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, mỗi xâu viết trên một dòng.
//Input
//2
//2
//4
//Ouput
//HA
//HAAA
//HAHA
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
int check(int a[100], int n){
	int cnt=0;
	if(a[0]==1&&a[n-1]==0){
		for(int i=0;i<n-1;i++){
			if(a[i]==1&&a[i]==a[i+1]){
				++cnt;
				break;
			}
		}
		if(cnt==0) return 1;
		else return 0;
	}
	else return 0;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
	    int a[100];
	    int x=1;
	    kt(a,n);
	    while(x){
		    if(check(a,n)){
			    for(int i=0;i<n;i++){
			        if(a[i]==1) cout << "H";
			        else cout << "A";
		        }
		        cout << endl;
		    }
		    if(sinh(a,n)) x=1;
		    else x=0;
	    }
	}
}