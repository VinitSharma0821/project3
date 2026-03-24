#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // 1. Append (Insert at End)
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void delete_node(int key) {
        if (head == NULL) return;

        // If head needs to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found!" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Original List: ";
    list.display();

    list.insert_at_beginning(5);
    cout << "After Insert at Beginning: ";
    list.display();

    int key = 20;
    if (list.search(key))
        cout << key << " found in list" << endl;
    else
        cout << key << " not found" << endl;

    list.delete_node(20);
    cout << "After Deletion: ";
    list.display();

    list.reverse();
    cout << "After Reversing: ";
    list.display();

    return 0;
}