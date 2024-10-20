#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Dodaj element na początek listy
    void addFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // Gdy lista jest pusta
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Dodaj element na koniec listy
    void addBack(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) { // Gdy lista jest pusta
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Usuń element z początku listy
    void removeFront() {
        if (head == nullptr) {
            std::cout << "Lista jest pusta, nie można usunąć elementu.\n";
            return;
        }
        Node* temp = head;
        if (head == tail) { // Gdy w liście jest tylko jeden element
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    // Usuń element z końca listy
    void removeBack() {
        if (tail == nullptr) {
            std::cout << "Lista jest pusta, nie można usunąć elementu.\n";
            return;
        }
        Node* temp = tail;
        if (head == tail) { // Gdy w liście jest tylko jeden element
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    // Wyświetl listę od początku
    void display() {
        Node* current = head;
        if (current == nullptr) {
            std::cout << "Lista jest pusta.\n";
            return;
        }
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Wyświetl listę w odwrotnej kolejności
    void displayReverse() {
        Node* current = tail;
        if (current == nullptr) {
            std::cout << "Lista jest pusta.\n";
            return;
        }
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << "\n";
    }

    // Czyszczenie całej listy
    void clear() {
        while (head != nullptr) {
            removeFront();
        }
    }

    // Destruktor, aby zwolnić pamięć
    ~DoublyLinkedList() {
        clear();
    }
};

// Testowanie klasy w funkcji main
int main() {
    DoublyLinkedList list;

    list.addFront(10);
    list.addFront(20);
    list.addBack(30);
    list.display();         // Powinno wyświetlić: 20 10 30

    list.removeFront();
    list.display();         // Powinno wyświetlić: 10 30

    list.removeBack();
    list.display();         // Powinno wyświetlić: 10

    list.clear();
    list.display();         // Powinno wyświetlić: Lista jest pusta.

    return 0;
}
