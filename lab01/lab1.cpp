#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double height;
    Student* next;

    Student(string n, int a, double h, Student* nxt = nullptr) {
        name = n;
        age = a;
        height = h;
        next = nxt;
    }

    ~Student() {
        cout << "delete: " << name << endl;
        delete next;
    }
};

void first_output(Student* &pNode, string name, int age, double height) {
    pNode = new Student(name, age, height, pNode);
}

void second_output(Student* &pNode, string name, int age, double height) {
    Student* newNode = new Student(name, age, height);
    if (pNode == nullptr) {
        pNode = newNode;
        return;
    }
    Student* tmp = pNode;
    while (tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = newNode;
}

void showmen(Student *pNode) {
    if (pNode == nullptr) {
        cout << "Список пуст\n";
        return;
    }
    Student *tmp = pNode;
    while (tmp != nullptr) {
        cout << "Имя: " << tmp->name << "\nВозраст: " << tmp->age << "\nРост: " << tmp->height << endl << endl;
        tmp = tmp->next;
    }
}

int main() {
    Student* list1 = nullptr;
    first_output(list1, "Петя", 15, 1.75);
    first_output(list1, "Маша", 16, 1.55);
    showmen(list1);
    
    delete list1;

    return 0;
}
