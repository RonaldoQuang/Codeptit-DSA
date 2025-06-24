//Giả sử bạn là một người nghèo trong địa phương của bạn. 
//Địa phương của bạn có duy nhất một cửa hàng bán lương thực. 
//Cửa hàng của bạn mở cửa tất cả các ngày trong tuần ngoại trừ chủ nhật. 
//Cho bộ ba số N, S, M thỏa mãn ràng buộc sau:
//N : số đơn vị lương thực nhiều nhất bạn có thể mua trong ngày.
//S : số lượng ngày bạn cần được sử dụng lương thực để tồn tại.
//M : số đơn vị lương thực cần có mỗi ngày để bạn tồn tại.
//Giả sử bạn đang ở ngày thứ 2 trong tuần và cần tồn tại trong S ngày tới. 
//Hãy cho biết số lượng ngày ít nhất bạn cần phải mua lương thực từ của hàng để tồn tại hoặc bạn sẽ bị chết đói trong S ngày tới.
//Input
//2
//16 10 2
//20 10 30
//Output
//2
//-1
#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n, s, m;
        cin >> n >> s >> m;
        if(n<m||6*(n-m)<m) cout << -1;
        else cout << ceil((float) m*s/n);
		cout << endl; 
	} 
}