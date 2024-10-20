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
