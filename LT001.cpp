//Cho hai số nguyên A và B. 
//Bạn có thể thực hiện một chuỗi các phép tính: trong phép tính đầu tiên, chọn một số và tăng nó lên 1; trong phép tính thứ hai, chọn một số và tăng nó lên 2, v.v. 
//Bạn được phép tự chọn số lượng các phép tính này.
//Ví dụ, nếu A = 1 và B = 3, bạn có thể thực hiện chuỗi ba phép tính sau:
//1. Cộng 1 vào A, khi đó A = 2 và B = 3
//2. Cộng 2 vào B, khi đó A = 2 và B = 5
//3. Cộng 3 vào A, khi đó A = 5 và B = 5
//Hãy tính số phép tính tối thiểu cần thiết để làm cho A và B bằng nhau.
//Input:
//Dòng đầu tiên chứa số lượng bộ test T (T ≤ 100).
//Mỗi test gồm hai số nguyên A và B (1 ≤ A, B ≤ 109).
//Output:
//Với mỗi test, hãy in ra một số nguyên là số lượng phép tính tối thiểu để biến đổi cho A và B bằng nhau.
//Input
//3
//1 3
//11 11
//30 20
//Output
//3
//0
//4
//Giải thích test ví dụ:
//Test 1 được giới thiệu ở đề bài.
//Test 2: hai số A và B bằng nhau nên không cần biến đổi
//Test 3: cộng từ 1 đến 4 vào B (B trở thành 20+1+2+3+4 = 30)
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int a, b; cin >> a >> b;
		int q=max(a,b)-min(a,b), k=ceil(sqrt(2*(float)q+1/4)-0.5);
		for(int i=k;;i++){
			int x=i*(i+1)/2;
			if((x+q)%2==0){
				cout << i;
				break;
			}
		}
		cout << endl;
	}
}