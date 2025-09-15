#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void displayList() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    int countAndDelete(int key) {
        int count = 0;
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == key) {
                count++;
            }
            current = current->next;
        }

        current = head;
        prev = nullptr;
        while (current != nullptr) {
            if (current->data == key) {
                if (prev == nullptr) {
                    head = current->next;
                    delete current;
                    current = head;
                } else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
        return count;
    }
};

int main() {
    LinkedList list;
    
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    int key = 1;

    std::cout << "Original Linked List: ";
    list.displayList();

    int count = list.countAndDelete(key);

    std::cout << "Key: " << key << std::endl;
    std::cout << "Count: " << count << std::endl;
    std::cout << "Updated Linked List: ";
    list.displayList();

    return 0;
}