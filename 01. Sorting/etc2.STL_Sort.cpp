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
	// 정렬 기준 = 점수가 작은 순서
	bool operator < (Student &student){
		return this -> score < student.score;
	}
	
	void printInfo(){
		cout << name << ", " << score <<endl;
	}
};

int main(void){
	
	Student students[] = {
		Student("나동빈", 90),
		Student("박예서", 80),
		Student("임명옥", 96),
		Student("박수명", 100),
		Student("박관홍", 30)
	};
	sort(students, students + 5);
	for(int i = 0; i < 5; i ++) students[i].printInfo();
	return 0;
}
