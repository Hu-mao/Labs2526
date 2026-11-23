#include "list.h"

// Підпрограма_1: формування елемента 1-го списку (включення в кінець двоспрямованого списку)
void appendDoubly(DoublyNode*& head, DoublyNode*& tail, char value) {
    DoublyNode* newNode = new DoublyNode{ value, tail, nullptr };

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Допоміжна функція додавання в кінець односпрямованого списку
void appendSingly(SinglyNode*& head, SinglyNode*& tail, char value) {
    SinglyNode* newNode = new SinglyNode{ value, nullptr };

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Підпрограма_2: перетворення двоспрямованого списку в односпрямований (включення в кінець)
void convertToSingly(const DoublyNode* dHead, SinglyNode*& sHead, SinglyNode*& sTail) {
    if (dHead == nullptr) return;

    const DoublyNode* current = dHead;
    while (true) {
        appendSingly(sHead, sTail, current->data);

        // Використання inline-функції для перевірки вказівника на наступний елемент
        if (isNextNull(current)) {
            break;
        }
        current = current->next;
    }
}

void printDoubly(const DoublyNode* head) {
    const DoublyNode* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (!isNextNull(current)) {
            std::cout << " <-> ";
        }
        current = current->next;
    }
    std::cout << " -> nullptr\n";
}

void printSingly(const SinglyNode* head) {
    const SinglyNode* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (!isNextNull(current)) {
            std::cout << " -> ";
        }
        current = current->next;
    }
    std::cout << " -> nullptr\n";
}

void freeDoubly(DoublyNode*& head) {
    while (head != nullptr) {
        DoublyNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void freeSingly(SinglyNode*& head) {
    while (head != nullptr) {
        SinglyNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    const int N = 9; // Кількість елементів за варіантом
    DoublyNode* dHead = nullptr;
    DoublyNode* dTail = nullptr;

    std::cout << "Vvedit " << N << " symvoliv dlya 1-go (dvospryamovanoho) spysku:\n";
    for (int i = 0; i < N; ++i) {
        char ch;
        std::cout << "Element [" << i + 1 << "]: ";
        std::cin >> ch;
        appendDoubly(dHead, dTail, ch); // Виклик підпрограми_1
    }

    std::cout << "\n1-y spysok (dvospryamovanyy):\n";
    printDoubly(dHead);

    SinglyNode* sHead = nullptr;
    SinglyNode* sTail = nullptr;

    // Виклик підпрограми_2
    convertToSingly(dHead, sHead, sTail);

    std::cout << "\n2-y spysok (odnospryamovanyy):\n";
    printSingly(sHead);

    // Звільнення динамічної пам'яті
    freeDoubly(dHead);
    freeSingly(sHead);

    return 0;
}