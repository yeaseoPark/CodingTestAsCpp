#include <stdio.h>
#include <algorithm>

int temp;
int count[6];
int array[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
				 3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
				 3, 1, 4, 3, 5, 1, 2, 1, 1, 1};

int main(void){
	// 1. �迭 �ʱ� ȭ 
	for(int i = 0; i < 6; i ++){
		count[i] = 0;
	}
	
	// 2. array�� ���� ��ġ�ϴ� index �� ���� 1 �� �ø�(������ ����)
	for(int i = 0; i < 30; i ++){
		count[array[i]]++;
	}
	
	// 3. ������ �̷���� ����� ���
	for(int i = 0; i < 6; i ++){
		while(count[i] != 0) {
			printf("%d ", i);
			count[i] --;
		}
	} 
	return 0;
}
