#include <iostream>
#include <algorithm>

using namespace std;

class Student{
public:
	string name;
	int score;
	
	Student(string name, int score){
		this -> name = name;
		this -> score = score;
	}
	// ���� ���� = ������ ���� ����
	bool operator < (Student &student){
		return this -> score < student.score;
	}
	
	void printInfo(){
		cout << name << ", " << score <<endl;
	}
};

int main(void){
	
	Student students[] = {
		Student("������", 90),
		Student("�ڿ���", 80),
		Student("�Ӹ��", 96),
		Student("�ڼ���", 100),
		Student("�ڰ�ȫ", 30)
	};
	sort(students, students + 5);
	for(int i = 0; i < 5; i ++) students[i].printInfo();
	return 0;
}
