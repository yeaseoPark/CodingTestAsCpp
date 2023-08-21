#include <iostream>
#include <string>

using namespace std;

typedef struct Node * TreePointer;
typedef struct Node {
	int data;
	TreePointer left, right;
	
} Node;

void addNode(TreePointer root, TreePointer p){
	if(root -> data > p -> data){
		if(root -> left){
			addNode(root -> left, p);
		}
		else root -> left = p;
	}
	else{
		if(root -> right){
			addNode(root -> right, p);
		}
		else root -> right = p;
	}
}

void postOrder(TreePointer ptr){
	if(ptr){
		postOrder(ptr -> left);
		postOrder(ptr -> right);
		cout << ptr -> data << endl;
	}
}

int main(void){
	Node nodes[10000];
	
	int data;
	int node_index = 0;
	while(1){
		if(cin >> data){
			nodes[node_index].data = data;
			nodes[node_index].left = NULL;
			nodes[node_index].right = NULL;
			node_index ++;
		}
		else break;
	}
	
	for(int idx = 1; idx < node_index; idx ++){
		addNode(&nodes[0], &nodes[idx]);		
	}
	
	postOrder(&nodes[0]);
	
	return 0;
}
