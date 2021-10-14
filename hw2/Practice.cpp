#include <iostream>
using namespace std;
/*
* forword declaration
*/
class Student;
class Teacher;
class Lecture;

class Student{
private:
	int* m_pId;
	string m_name;
	Lecture* m_lName;

public:
	Student();
	Student(int, string);
	string GetName();
	void SetID(int id);
};

Student::Student() {
	m_pId = new int(0);
	m_name = "Alice";
}
Student::Student(int id, string name) {
	m_pId = new int(id);
	m_name = name;
}
string Student::GetName() {
	return m_name;
}
void Student::SetID(int id) {
	*(this-> m_pId) = id;
}

class Teacher {
private:
	int* m_pId;
	string m_name;
	Lecture* m_lecture;
public:
	Teacher();
	Teacher(int, string);
	string GetName();
	void SetID(int id);
};

Teacher::Teacher() {
	m_pId = new int(0);
	m_name = "Alice";
}
Teacher::Teacher(int id, string name) {
	m_pId = new int(id);
	m_name = name;
}
string Teacher::GetName() {
	return m_name;
}
void Teacher::SetID(int id) {
	*(this->m_pId) = id;
}


class Lecture {
private:
	int* m_pId;
	string m_name;
	Student* s_group; //A list of students
	Teacher* m_pTeacher; //새로 사용
public:
	Lecture();
	Lecture(int, string);
	Lecture(int, string, Teacher*);
	string GetName();
	string GetTeacherName(); // 새로 사용
	void SetID(int id);
};

Lecture::Lecture() {
	m_pId = new int(0);
	m_name = "Alice";
}
Lecture::Lecture(int id, string name) {
	m_pId = new int(id);
	m_name = name;
}
Lecture::Lecture(int id, string name, Teacher* p_teacher) {
	m_pId = new int(id);
	m_name = name;
	this->m_pTeacher = p_teacher;
}
string Lecture::GetName() {
	return m_name;
}
void Lecture::SetID(int id) {
	*(this->m_pId) = id;
}//새로운 함수
string Lecture::GetTeacherName() { 
	return this->m_pTeacher->GetName();
}



int main() {
	Student s1(201911999, "Alice");
	Teacher t1(111111111, "Tom");
	Lecture l1(222222222, "OOP");
	
	// 새로 만든 함수
	Lecture l2(333333, "OOP2", &t1);
	cout << s1.GetName() << endl;
	cout << t1.GetName() << endl;
	cout << l1.GetName() << endl;
	
	cout << l2.GetName() << "\t" << l2.GetTeacherName() << endl;
	return 0;
}