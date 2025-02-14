#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;

public:
    LinkedList(T *value) {
        this->length = 1;
        this->head = new Node<T>(value);
    }

    ~LinkedList() {
        Node<T>* temp = this->head;
        while(head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    Node<T>* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        while (temp->next!=NULL)
            temp = temp->next;
        delete temp;
        length--;
    }

    void deleteNode(int index) {
        //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index < 0 || index >= length) {
            cout << "Index is invalid" << endl;
            return;
        }

        if (index == 0) {
            delfirst();
        } else {
            Node<T>* temp = get(index - 1);
            Node<T>* deleteThis = temp->next;

            temp->next = temp->next->next;
            //temp = temp -> next;
            delete deleteThis;
        }

        length--;

    }

    void insert(int index, T* value) {
        if (index < 0 || index > length) {
            cout << "Index is invalid" << endl;
            return;
        }
        if (index == 0) {
            addHead(value);
        }
        if (index == length) {
            add(value);
        }
        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
        return;
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.

        Node<T>* prev = NULL;
        Node<T>* curr = NULL;
        Node<T>* after = NULL;

        curr = head;

        while (curr != NULL) {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }

        head = prev;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);

    student *s4 = new student("D", 23);
    student *s5 = new student("E", 24);

    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->delfirst();
    ll->print();
    /*
    ll->dellast();
    ll->deleteNode(1);
    ll->print();
    */
    ll->add(s4);
    ll->add(s5);
    ll->print();
    ll->deleteNode(2);
    ll->print(); // A B E

    ll->reverselist();
    ll->print(); // E B A

}