#include <iostream>
#include <string>
#include <iomanip>

// 1. Опис елемента структури даних: «Студент»
struct Student {
    std::string fullName;   // ПІБ
    int course;             // Курс
    std::string recordBook; // № залік.кн.
    double averageGrade;    // Середній бал
};

// 2. Опис АТД: «Черга» (векторне представлення)
class VectorQueue {
private:
    static const int MAX_SIZE = 100; // Максимальна місткість вектора
    Student data[MAX_SIZE];          // Вектор (масив) елементів черги
    int frontIndex;                  // Індекс початку черги
    int rearIndex;                   // Індекс кінця черги
    int count;                       // Поточна кількість елементів

public:
    // Ініціалізація структури даних (конструктор та метод init)
    VectorQueue() {
        init();
    }

    void init() {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == MAX_SIZE;
    }

    // Операція_1: Запис у кінець черги
    bool enqueue(const Student& student) {
        if (isFull()) {
            std::cout << "Помилка: черга переповнена!\n";
            return false;
        }
        rearIndex = (rearIndex + 1) % MAX_SIZE;
        data[rearIndex] = student;
        count++;
        return true;
    }

    // Операція_2: Читання з видаленням з початку черги
    bool dequeue(Student& outStudent) {
        if (isEmpty()) {
            std::cout << "Помилка: черга порожня!\n";
            return false;
        }
        outStudent = data[frontIndex];
        frontIndex = (frontIndex + 1) % MAX_SIZE;
        count--;
        return true;
    }

    void printAll() const {
        if (isEmpty()) {
            std::cout << "Черга порожня.\n";
            return;
        }
        std::cout << "Поточний стан черги (" << count << " елемент(ів)):\n";
        for (int i = 0; i < count; ++i) {
            int idx = (frontIndex + i) % MAX_SIZE;
            const Student& s = data[idx];
            std::cout << "  [" << i + 1 << "] " << s.fullName
                << " | Курс: " << s.course
                << " | Залік. кн.: " << s.recordBook
                << " | Сер. бал: " << std::fixed << std::setprecision(2) << s.averageGrade << "\n";
        }
    }
};

void printStudent(const std::string& label, const Student& s) {
    std::cout << label << ": " << s.fullName
        << " | Курс: " << s.course
        << " | Залік. кн.: " << s.recordBook
        << " | Сер. бал: " << std::fixed << std::setprecision(2) << s.averageGrade << "\n";
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // 3.1. Ініціалізація структури даних
    VectorQueue queue;
    queue.init();

    // 3.2. Запис до АТД декількох значень (Операція_1 — запис у кінець)
    std::cout << "--- Додавання студентів у кінець черги ---\n";
    queue.enqueue({ "Коваленко Олена Сергіївна", 2, "КБ-2041", 91.5 });
    queue.enqueue({ "Бондар Максим Андрійович", 1, "КБ-1018", 84.0 });
    queue.enqueue({ "Ткаченко Ірина Вікторівна", 3, "КБ-3009", 95.2 });
    queue.enqueue({ "Мельник Дмитро Олегович", 2, "КБ-2055", 78.8 });

    std::cout << "\n";
    queue.printAll();

    // 3.3. Читання з АТД декількох значень (Операція_2 — видалення з початку)
    std::cout << "\n--- Читання та видалення студентів з початку черги ---\n";
    Student removedStudent;
    for (int i = 0; i < 2; ++i) {
        if (queue.dequeue(removedStudent)) {
            printStudent("Прочитано та видалено з початку", removedStudent);
        }
    }

    std::cout << "\n--- Стан черги після видалення двох елементів ---\n";
    queue.printAll();

    return 0;
}