/**
 * @file doubly_linked_list.cpp
 * @brief Implementacja listy dwukierunkowej w języku C++.
 */

#include <iostream>

using namespace std;

/**
 * @class Node
 * @brief Klasa reprezentująca pojedynczy węzeł w liście dwukierunkowej.
 */
class Node {
public:
    int data; ///< Przechowywana wartość w węźle.
    Node* next; ///< Wskaźnik na następny element listy.
    Node* prev; ///< Wskaźnik na poprzedni element listy.

    /**
     * @brief Konstruktor tworzący nowy węzeł z podaną wartością.
     * @param value Wartość do zapisania w węźle.
     */
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

/**
 * @class DoublyLinkedList
 * @brief Klasa reprezentująca listę dwukierunkową.
 */
class DoublyLinkedList {
private:
    Node* head; ///< Wskaźnik na pierwszy element listy.
    Node* tail; ///< Wskaźnik na ostatni element listy.

public:
    /**
     * @brief Konstruktor domyślny. Tworzy pustą listę.
     */
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /**
     * @brief Dodaje element na początek listy.
     * @param value Wartość do dodania.
     */
    void addAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    /**
     * @brief Dodaje element na koniec listy.
     * @param value Wartość do dodania.
     */
    void addAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    /**
     * @brief Dodaje element pod wskazany indeks.
     * @param index Indeks, pod który element ma zostać dodany.
     * @param value Wartość do dodania.
     */
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

    /**
     * @brief Usuwa element z początku listy.
     */
    void removeFromHead() {
        if (head == nullptr) return;

        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    /**
     * @brief Usuwa element z końca listy.
     */
    void removeFromTail() {
        if (tail == nullptr) return;

        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    /**
     * @brief Usuwa element pod wskazanym indeksem.
     * @param index Indeks, z którego element ma zostać usunięty.
     */
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

    /**
     * @brief Wyświetla wszystkie elementy listy.
     */
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    /**
     * @brief Wyświetla elementy listy w odwrotnej kolejności.
     */
    void displayReverse() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    /**
     * @brief Wyświetla następny element od danego węzła.
     * @param node Wskaźnik na bieżący węzeł.
     */
    void displayNext(Node* node) {
        if (node != nullptr && node->next != nullptr) {
            cout << "Następny element: " << node->next->data << endl;
        }
        else {
            cout << "Brak następnego elementu." << endl;
        }
    }

    /**
     * @brief Wyświetla poprzedni element od danego węzła.
     * @param node Wskaźnik na bieżący węzeł.
     */
    void displayPrev(Node* node) {
        if (node != nullptr && node->prev != nullptr) {
            cout << "Poprzedni element: " << node->prev->data << endl;
        }
        else {
            cout << "Brak poprzedniego elementu." << endl;
        }
    }

    /**
     * @brief Znajduje element na podstawie indeksu.
     * @param index Indeks elementu, który chcemy pobrać.
     * @return Wskaźnik na węzeł na danym indeksie.
     */
    Node* getNodeAtIndex(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }
        return temp;
    }

    /**
     * @brief Wyczyść całą listę, usuwając wszystkie elementy.
     */
    void clearList() {
        while (head != nullptr) {
            removeFromHead();
        }
    }
};

/**
 * @brief Funkcja główna programu testująca funkcjonalność listy dwukierunkowej.
 * @return 0 w przypadku powodzenia.
 */
int main() {
    DoublyLinkedList list;

    // Dodawanie elementów
    list.addAtHead(10);
    list.addAtHead(20);
    list.addAtTail(30);
    list.addAtIndex(1, 25);

    // Wyświetlanie listy
    cout << "Lista: ";
    list.displayList();

    // Wyświetlanie listy w odwrotnej kolejności
    cout << "Lista w odwrotnej kolejności: ";
    list.displayReverse();

    // Usunięcie elementu z początku
    list.removeFromHead();
    cout << "Po usunięciu elementu z początku: ";
    list.displayList();

    // Usunięcie elementu z końca
    list.removeFromTail();
    cout << "Po usunięciu elementu z końca: ";
    list.displayList();

    // Usunięcie elementu z indeksu
    list.removeAtIndex(1);
    cout << "Po usunięciu elementu z indeksu 1: ";
    list.displayList();

    // Wyświetlenie następnego i poprzedniego elementu od węzła
    Node* node = list.getNodeAtIndex(0);  // Pobieramy element na pozycji 0
    list.displayNext(node);
    list.displayPrev(node);

    // Wyczyść listę
    list.clearList();
    cout << "Po wyczyszczeniu listy: ";
    list.displayList();

    return 0;
}