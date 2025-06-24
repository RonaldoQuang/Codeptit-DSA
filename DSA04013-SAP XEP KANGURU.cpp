//Có N con kanguru trong vườn thú, con thứ i có chiều cao bằng A[i]. 
//Con kanguru có chiều cao X có thể chứa được một con có chiều cao bằng Y trong túi của nó nếu như X >= 2*Y.
//Một con đã chứa một con kanguru rồi, thì không thể nhảy vào túi một con kanguru khác.
//Bầy Kanguru rất thích chơi trốn tìm, vì vậy chúng thường xuyên nhảy vào túi của nhau. 
//Các bạn hãy tính toán xem trong trường hợp tối ưu, số con kanguru nhìn thấy trong vườn thú ít nhất bằng bao nhiêu?
//Input
//2
//8
//2 5 7 6 9 8 4 2
//8
//9 1 6 2 6 5 8 3
//Output
//5
//5
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[n];
    	int max=-1e9;
    	for(int i=0;i<n;i++){
    		cin >> a[i];
		}
    	sort(a,a+n);
		int l=n/2-1, r=n-1;
		while(l>=0){
			if(a[l]*2<=a[r]){
				--n;
				--l;
				--r;
			}
			else --l;
		}
		cout << n << endl;
	}
}