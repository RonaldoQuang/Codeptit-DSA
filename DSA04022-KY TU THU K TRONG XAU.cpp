//Xâu ký tự S được tạo ra bằng cách bổ sung dần các ký tự chữ cái Tiếng Anh in hoa như sau.
//Bước 1: Chỉ có chữ cái A
//Bước 2: Thêm chữ cái B vào giữa 2 chữ A => S = "ABA"
//Bước 3: Thêm chữ cái C vào giữa 2 xâu đã có ở bước 2: S = "ABACABA"
//Cứ như vậy cho đến bước thứ N (0 < N < 26)
//Hãy xác định ký tự thứ K trong bước biến đổi thứ N là chữ cái gì?
//Input
//2
//3 2
//4 8
//Output
//B
//D
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    long long n, k; cin >> n >> k;
	    int cnt=1;
	    while(k%2==0){
	        ++cnt;
	        k/=2;
	    }
		cout << (char) (64+cnt) << endl;
	}
}