#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    double height;
    
    Student* next;
};



class People {
public:
    void add_forward(Student* &pNode, string name, int age, double height){
        Student* newNode = new Student{name, age, height, pNode};
        pNode = newNode;
    }

    
    
    void add_end(Student* &pNode, string name, int age, double height){
        Student* newNode = new Student{name, age, height, nullptr};
        if (!pNode) {
            pNode = newNode;
        } else {
            Student* tmp = pNode;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = newNode;
        }
    }

    
    void add_after(Student* &pNode, string Node, string name, int age, double height){
        if (!pNode) {
            cout << "EMPTY\n";
            return;
        }
        Student* tmp = pNode;
        while (tmp && tmp->name != Node)
            tmp = tmp->next;
        if (!tmp) {
            cout << "No_Elements\n";
            return;
        }
        Student* newNode = new Student{name, age, height, tmp->next};
        tmp->next = newNode;
    }

    
    void add_before(Student* &pNode, string Node, string name, int age, double height) {
        if (!pNode) {
            cout << "empty\n";
            return;
        }
        if (pNode->name == Node) {
            add_forward(pNode, name, age, height);
            return;
        }
        Student* tmp = pNode;
        while (tmp && tmp->name != Node)
            tmp = tmp->next;
        if (!tmp) {
            cout << "No_Element\n";
            return;
        }
        Student* newNode = new Student{name, age, height, tmp->next};
        tmp->next = newNode;
    }

    
    void del(Student* &pNode, string Node) {
        if (!pNode) {
            cout << "empty\n";
            return;
        }
        if (pNode->name == Node) {
            Student* tmp = pNode;
            pNode = pNode->next;
            delete tmp;
            return;
        }
        Student* prev = nullptr;
        Student* tmp = pNode;
        while (tmp && tmp->name != Node) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (!tmp) {
            cout << "No_Element\n";
            return;
        }
        prev->next = tmp->next;
        delete tmp;
    }

    
    void show(Student* pNode) {
        if (!pNode) {
            cout << "empty\n";
            return;
        }
        Student* tmp = pNode;
        while (tmp) {
            cout << "Name: " << tmp->name << "\nAge: " << tmp->age << "\nHeight: " << tmp->height << "\n\n";
            tmp = tmp->next;
        }
    }
};

int main() {
    Student* list1 = nullptr;
    People studentList;
    
    studentList.add_forward(list1, "Petya", 15, 1.75);
    studentList.show(list1);
    cout << "-----------------------------------------------------------------------\n\n";
    
    studentList.add_forward(list1, "Masha", 16, 1.55);
    studentList.show(list1);
    cout << "-----------------------------------------------------------------------\n\n";
    
    studentList.add_after(list1, "Petya", "Vanya", 17, 1.85);
    studentList.show(list1);
    cout << "-----------------------------------------------------------------------\n\n";
    
    studentList.add_before(list1, "Vanya", "Vasya", 18, 1.99);
    studentList.show(list1);
    cout << "-----------------------------------------------------------------------\n\n";
    
    studentList.del(list1, "Masha");
    studentList.show(list1);
    cout << "-----------------------------------------------------------------------\n\n";
    
    studentList.add_end(list1, "Dasha", 19, 1.65);
    studentList.show(list1);
    cout << "-----------------------------------------------------------------------\n\n";

    return 0;
}
