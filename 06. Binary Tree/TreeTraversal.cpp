#include <iostream>

using namespace std;

int number = 15;

// �ϳ��� ��� ������ ����
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// ���� ��ȸ ����
void preOrder(treePointer ptr){
	if(ptr){
		cout << ptr -> data << " ";
		preOrder(ptr -> leftChild);
		preOrder(ptr -> rightChild);
	}
} 

// ���� ��ȸ ���� 
void inOrder(treePointer ptr){
	if(ptr){
		inOrder(ptr -> leftChild);
		cout << ptr -> data << " ";
		inOrder(ptr -> rightChild);
	}
} 

// ���� ��ȸ 
void postOrder(treePointer ptr){
	if(ptr){
		postOrder(ptr -> leftChild);
		postOrder(ptr -> rightChild);
		cout << ptr -> data << " ";
	}
}

int main(void){
	node nodes[number + 1];
	
	for(int i = 1; i <= number; i ++){
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	
	for(int i = 1; i <= number; i ++){
		if(i % 2 == 0){
			nodes[i / 2].leftChild = &nodes[i];
		}
		else{
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	
	postOrder(&nodes[1]);
	
	return 0;
}
