//Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo xoắn ốc (spiral-order). 
//Input
//2
//2
//1 2 R 1 3 L
//4
//10 20 L 10 30 R 20 40 L 20 60 R
//Output
//1 3 2
//10 20 30 60 40
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
void makeNode(node a, int x, int y, char z){
    if(z=='L'){
    	a->left=new Node(y);
	}	
	else a->right=new Node(y);
}
void Insert(node &a, int x, int y, char z){
	if(a==NULL) return;
	if(a->data==x) makeNode(a,x,y,z);
	else{
		Insert(a->left,x,y,z);
		Insert(a->right,x,y,z);
	}
}
void in(node a){
	stack<node> st;
	stack<node> st1;
	st.push(a);
	while(!st.empty()||!st1.empty()){
		if(!st.empty()){
			while(!st.empty()){
				node x=st.top(); st.pop();
				cout << x->data << " ";
				if(x->right!=NULL) st1.push(x->right);
				if(x->left!=NULL) st1.push(x->left);
			}
		}
		if(!st1.empty()){
			while(!st1.empty()){
				node x=st1.top(); st1.pop();
				cout << x->data << " ";
				if(x->left!=NULL) st.push(x->left);
				if(x->right!=NULL) st.push(x->right);
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node a=NULL;
		while(n--){
			int x, y; char z;
			cin >> x >> y >> z;
			if(a==NULL){
				a=new Node(x);
			}
			Insert(a,x,y,z);
		}
		in(a);
		cout << endl;
	}
}