#ifndef LISTS_H
#define LISTS_H

#include <iostream>

// Вузол двоспрямованого (1-го) списку
struct DoublyNode {
    char data;
    DoublyNode* prev;
    DoublyNode* next;
};

// Вузол односпрямованого (2-го) списку
struct SinglyNode {
    char data;
    SinglyNode* next;
};

// Inline-функція перевірки на рівність нулю вказівника на наступний елемент
inline bool isNextNull(const DoublyNode* node) {
    return node == nullptr || node->next == nullptr;
}

inline bool isNextNull(const SinglyNode* node) {
    return node == nullptr || node->next == nullptr;
}

// Оголошення підпрограм
void appendDoubly(DoublyNode*& head, DoublyNode*& tail, char value);
void convertToSingly(const DoublyNode* dHead, SinglyNode*& sHead, SinglyNode*& sTail);

// Допоміжні функції для виведення та очищення пам'яті
void printDoubly(const DoublyNode* head);
void printSingly(const SinglyNode* head);
void freeDoubly(DoublyNode*& head);
void freeSingly(SinglyNode*& head);

#endif // LISTS_H