//Cho mảng A[] gồm N node là biểu diễn phép duyệt theo thứ tự trước (Preorder) của cây nhị phân tìm kiếm. 
//Nhiệm vụ của bạn là đưa ra phép duyệt theo thứ tự sau của cây nhị phân tìm kiếm.
//Input
//2
//5
//40 30 35 80 100
//8
//40 30 32 35 80 90 100 120
//Output
//35 30 100 80 40
//35 32 30 120 100 90 80 40
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};
typedef struct Node* node;
void Insert(node &a, int x){
	if(a==NULL) a=new Node(x);
	else{
		if(x<a->data) Insert(a->left,x);
		else Insert(a->right,x);
	}
}
void in(node a){
	if(a==NULL) return;
	if(a->left!=NULL) in(a->left);
	if(a->right!=NULL) in(a->right);
	cout << a->data << " ";
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node a=NULL;
		while(n--){
			int x; cin >> x;
			Insert(a,x);
		}
		in(a);
		cout << endl;
	}
}