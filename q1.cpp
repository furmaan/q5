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

    // (a) Insertion at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        std::cout << val << " inserted at the beginning." << std::endl;
    }

    // (b) Insertion at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            std::cout << val << " inserted at the end." << std::endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        std::cout << val << " inserted at the end." << std::endl;
    }

    // (c) Insertion in between
    void insertInBetween(int newVal, int specificVal, bool after) {
        Node* current = head;
        while (current != nullptr && current->data != specificVal) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Node with value " << specificVal << " not found." << std::endl;
            return;
        }

        Node* newNode = new Node(newVal);
        if (after) {
            newNode->next = current->next;
            current->next = newNode;
            std::cout << newVal << " inserted after " << specificVal << "." << std::endl;
        } else { // Before
            if (current == head) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* prev = head;
                while (prev->next != current) {
                    prev = prev->next;
                }
                newNode->next = current;
                prev->next = newNode;
            }
            std::cout << newVal << " inserted before " << specificVal << "." << std::endl;
        }
    }

    // (d) Deletion from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        std::cout << temp->data << " deleted from the beginning." << std::endl;
        delete temp;
    }

    // (e) Deletion from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }
        if (head->next == nullptr) {
            std::cout << head->data << " deleted from the end." << std::endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        std::cout << current->next->data << " deleted from the end." << std::endl;
        delete current->next;
        current->next = nullptr;
    }

    // (f) Deletion of a specific node
    void deleteSpecificNode(int val) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            std::cout << val << " deleted from the list." << std::endl;
            delete temp;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }
        if (current->next == nullptr) {
            std::cout << "Node with value " << val << " not found." << std::endl;
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        std::cout << val << " deleted from the list." << std::endl;
        delete temp;
    }

    // (g) Search for a node and display its position
    void searchNode(int val) {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* current = head;
        int position = 1;
        while (current != nullptr && current->data != val) {
            current = current->next;
            position++;
        }
        if (current == nullptr) {
            std::cout << "Node with value " << val << " not found." << std::endl;
        } else {
            std::cout << "Node with value " << val << " found at position " << position << "." << std::endl;
        }
    }

    // (h) Display all the node values
    void displayList() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* current = head;
        std::cout << "Current list: ";
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }
};

void displayMenu() {
    std::cout << "\n--- Singly Linked List Operations ---" << std::endl;
    std::cout << "1. Insert at the beginning" << std::endl;
    std::cout << "2. Insert at the end" << std::endl;
    std::cout << "3. Insert in between (before/after specific value)" << std::endl;
    std::cout << "4. Delete from the beginning" << std::endl;
    std::cout << "5. Delete from the end" << std::endl;
    std::cout << "6. Delete a specific node" << std::endl;
    std::cout << "7. Search for a node" << std::endl;
    std::cout << "8. Display all nodes" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    LinkedList list;
    int choice, value, specificValue;
    bool after;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                std::cout << "Enter the value of the node to insert before/after: ";
                std::cin >> specificValue;
                std::cout << "Insert (1) after or (0) before? ";
                std::cin >> after;
                list.insertInBetween(value, specificValue, after);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                std::cout << "Enter value of node to delete: ";
                std::cin >> value;
                list.deleteSpecificNode(value);
                break;
            case 7:
                std::cout << "Enter value of node to search: ";
                std::cin >> value;
                list.searchNode(value);
                break;
            case 8:
                list.displayList();
                break;
            case 9:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}