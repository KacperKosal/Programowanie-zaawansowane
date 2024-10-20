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
    // Dodaj element pod wskazany indeks
void addAtIndex(int index, int value) {
    if (index == 0) {
        addAtHead(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    for (int i = 0; i < index - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        addAtTail(value);
    }
    else {
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
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
    // Usuń element pod wskazanym indeksem
void removeAtIndex(int index) {
    if (index == 0) {
        removeFromHead();
        return;
    }

    Node* temp = head;
    for (int i = 0; i < index && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp == tail) {
        removeFromTail();
    }
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
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
    // Wyświetl następny element (od danego węzła)
void displayNext(Node* node) {
    if (node != nullptr && node->next != nullptr) {
        cout << "Następny element: " << node->next->data << endl;
    }
    else {
        cout << "Brak następnego elementu." << endl;
    }
}

// Wyświetl poprzedni element (od danego węzła)
void displayPrev(Node* node) {
    if (node != nullptr && node->prev != nullptr) {
        cout << "Poprzedni element: " << node->prev->data << endl;
    }
    else {
        cout << "Brak poprzedniego elementu." << endl;
    }
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

    // Dodawanie elementów
    list.addFront(10);
    list.addFront(20);
    list.addBack(30);
    list.display();         // Powinno wyświetlić: 20 10 30

    // Wyświetlanie listy
    list.removeFront();
    list.display();         // Powinno wyświetlić: 10 30

    list.removeBack();
    list.display();         // Powinno wyświetlić: 10

    list.clear();
    list.display();         // Powinno wyświetlić: Lista jest pusta.

    return 0;
}
