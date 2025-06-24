//Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:
//Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.
//Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].
//Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?
//Input
//2
//3 2
//4 8
//Output
//2
//4

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
		cout << cnt << endl;
	}
}