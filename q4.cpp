#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << "->";
            }
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next_node = nullptr;

        while (current != nullptr) {
            next_node = current->next; // Store the next node
            current->next = prev;      // Reverse the current node's pointer
            prev = current;            // Move 'prev' to 'current'
            current = next_node;       // Move 'current' to 'next_node'
        }
        head = prev; // Update the head of the list to the last node (which is now the first)
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    std::cout << "Original List: ";
    list.display();

    list.reverse();

    std::cout << "Reversed List: ";
    list.display();

    return 0;
}