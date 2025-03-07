#include <iostream>
#include <string>
using namespace std;

    
class Student
{
public:
    string name;
    int age;
    double height;
    
    Student* next;
    
};

void first_output(Student* &pNode, string name, int age, double height){
    Student* newNode = new Student;
    newNode->name = name;
    newNode->age = age;
    newNode->height = height;
    newNode->next = pNode;
    pNode = newNode;
}

void second_output(Student* &pNode, string name, int age, double height){
    Student* newNode = new Student;
    newNode->name = name;
    newNode->age = age;
    newNode->height = height;
    newNode->next = pNode;
    
    if (pNode == nullptr) {
        newNode ->next = nullptr;
        pNode = newNode;
    }
    else{
        Student* tmp = pNode;
        while (tmp->next != nullptr)
            tmp = tmp->next;
        newNode->next = nullptr;
        tmp->next = newNode;
    }
}

void third_output(Student* &pNode, string Node,string name, int age, double height){
    
    if (pNode == nullptr) {
        cout << "EMPTY";
        return;
    }
    Student* tmp = pNode;
    while (tmp->next != nullptr and tmp->name != Node)
        tmp = tmp->next;
    
    if (tmp->next == nullptr and tmp->name != Node){
        cout << "No_Elements\n";
        return;
    }
    
    Student* newNode = new Student;
    newNode->name = name;
    newNode->age = age;
    newNode->height = height;
    newNode->next = pNode->next;
    newNode->next = pNode;
}

void fourth_output(Student* pNode, string Node, string name, int age, double height) {
    if (pNode == nullptr) {
        cout << "This list is empty\n";
        return;
    }
    if (pNode->name == Node) {
        first_output(pNode, name, age, height);
        return;
    }
    Student *prev = pNode, *tmp = pNode->next;
    while (tmp->next != nullptr and tmp->name != Node) {
        tmp = tmp->next;
        prev = prev->next;
    }
    if (tmp->next == nullptr and tmp->name != Node) {
        cout << "No element in the list\n";
        return;
    }
    Student* newNode = new Student;
    newNode->name = name;
    newNode->age = age;
    newNode->height = height;
    newNode->next = tmp;
    prev->next = newNode;
}

void Del(Student* &pNode, string Node) {
    if(pNode == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Student *tmp = pNode;
    if(pNode->name == Node) {
        pNode = pNode->next;
        delete tmp;
        return;
    }
    if (pNode->next == nullptr) {
        cout << "No element in the list\n";
        return;
    }
    Student *prev=pNode;
    tmp = pNode->next;
    while (tmp->next != nullptr and tmp->name != Node) {
        tmp = tmp->next;
        prev = prev->next;

    }
    if(tmp->next == nullptr and tmp->name != Node) {
        cout << "No element in the list\n";
        return;
    }
    if(tmp->name == Node) {
        prev->next = tmp->next;
        delete tmp;
        return;
    }
}


void Showmen(Student *pNode) {
    if (pNode == nullptr) {
        cout << "This list is empty\n";
        return;
    }
    Student *tmp = pNode;
    while(tmp != nullptr) {
        cout<<"Name: " << tmp->name << "\nAge: " << tmp->age << "\nHeight: " << tmp->height << endl << endl;
        tmp = tmp->next;
    }
}


int main() {
    Student* list1 = nullptr;
    first_output(list1, "Petya", 15, 1.75);
    Showmen(list1);
    cout<<"-----------------------------------------------------------------------"<<endl << endl;
    first_output(list1, "Masha", 16, 1.55);
    Showmen(list1);
    cout<<"-----------------------------------------------------------------------"<<endl << endl;
    third_output(list1, "Petya", "Vanya", 17, 1.85);
    Showmen(list1);
    cout<<"-----------------------------------------------------------------------"<<endl << endl;
    fourth_output(list1, "Vanya", "Vasya", 18, 1.99);
    Showmen(list1);
    cout<<"-----------------------------------------------------------------------"<<endl << endl;
    Del(list1, "Masha");
    Showmen(list1);
    cout<<"-----------------------------------------------------------------------"<<endl << endl;
    second_output(list1, "Dasha", 19, 1.65);
    Showmen(list1);
    cout<<"-----------------------------------------------------------------------"<<endl << endl;

    return 0;
}

