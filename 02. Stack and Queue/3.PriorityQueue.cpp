#include <iostream>
#include <queue>
#include <functional>    // greater
using namespace std;
 
struct Student {
    int id;
    int math, eng;
    Student(int num, int m, int e) : id(num), math(m), eng(e) {}    // ������ ����

    // �׳� ������ ��� ���� �й����� �й��� �������� Top �� ���� �Ѵ�
    bool operator<(const Student s) const {
        return this->id < s.id;
    }
};
 
int main() {
    priority_queue<Student> pq;  
 
    pq.push(Student(3, 100, 50));
    pq.push(Student(1, 60, 50));
    pq.push(Student(2, 80, 50));
    pq.push(Student(4, 90, 50));
    pq.push(Student(5, 70, 40));
    
// �й��� �������� ���� ���� ���� ����� �ȴ� �� ������ ����ü ������ ������ �����ε��� �ִ�
    while (!pq.empty()) {
        Student ts = pq.top(); pq.pop();
        cout << "(�й�, ���� , ���� ) : " << ts.id << ' ' << ts.math << ' ' << ts.eng << '\n';
    }
 
    return 0;
}

