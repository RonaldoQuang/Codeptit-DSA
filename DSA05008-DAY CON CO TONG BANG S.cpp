//Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. 
//Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.
//Input
//2
//5 6
//1 2 4 3 5
//10 15
//2 2 2 2 2 2 2 2 2 2
//Output
//YES
//NO
#include <bits/stdc++.h>
using namespace std;
void Try() {
    int n, s;
    cin >> n >> s;
    int a[n], f[s+1]={};
    f[0]=1;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        for(int j=s;j>=1;j--) {
            if(j>=a[i]&&f[j]==0&&f[j-a[i]]==1) {
                f[j]=1;
            }
        }
    }
    if(f[s]==1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		Try();
	}
}