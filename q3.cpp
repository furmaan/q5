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
        if (!head) {
            head = new Node(val);
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(val);
        }
    }

    int findMiddle() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    std::cout << "Input Linked List: 1->2->3->4->5" << std::endl;
    int middle = list.findMiddle();
    std::cout << "Output: " << middle << std::endl;

    // Example with an even number of nodes
    std::cout << "\nExample with even nodes: 1->2->3->4->5->6" << std::endl;
    LinkedList evenList;
    evenList.insert(1);
    evenList.insert(2);
    evenList.insert(3);
    evenList.insert(4);
    evenList.insert(5);
    evenList.insert(6);
    int evenMiddle = evenList.findMiddle();
    std::cout << "Output: " << evenMiddle << std::endl;

    return 0;
}