#include <iostream>
#include <string>
#include <vector>

class Base {
public:
    virtual void printData() const {  // Віртуальна функція
        std::cout << "Base class data." << std::endl;
    }
    virtual ~Base() {}  // Віртуальний деструктор
};

class Derived1 : public Base {
public:
    void printData() const override {  // Перевизначення віртуальної функції
        std::cout << "Derived1 class data." << std::endl;
    }
};

class Derived2 : public Base {
public:
    void printData() const override {  // Перевизначення віртуальної функції
        std::cout << "Derived2 class data." << std::endl;
    }
};

// Клас з вкладеними структурами
class ComplexClass {
public:
    struct Member {
        int id;
        std::string name;
    };

    ComplexClass(int id, std::string name) {
        member.id = id;
        member.name = name;
    }

    void printMember() const {
        std::cout << "ID: " << member.id << ", Name: " << member.name << std::endl;
    }

private:
    Member member;
};

int main() {
    // Створюємо масив з базовим класом для поліморфізму
    std::vector<Base*> objects;
    objects.push_back(new Derived1());
    objects.push_back(new Derived2());

    // Викликаємо віртуальні функції
    for (auto obj : objects) {
        obj->printData();
    }

    // Створюємо об'єкти складних класів
    ComplexClass complexObj1(1, "Аліса");
    ComplexClass complexObj2(2, "Володимир");

    // Виводимо дані членів структур
    complexObj1.printMember();
    complexObj2.printMember();

    // Очищаємо пам'ять
    for (auto obj : objects) {
        delete obj;
    }

    return 0;
}