#include <iostream>
#include <string>
#include <vector>

class Base {
public:
    virtual void printData() const {  // ³�������� �������
        std::cout << "Base class data." << std::endl;
    }
    virtual ~Base() {}  // ³��������� ����������
};

class Derived1 : public Base {
public:
    void printData() const override {  // �������������� ��������� �������
        std::cout << "Derived1 class data." << std::endl;
    }
};

class Derived2 : public Base {
public:
    void printData() const override {  // �������������� ��������� �������
        std::cout << "Derived2 class data." << std::endl;
    }
};

// ���� � ���������� �����������
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
    // ��������� ����� � ������� ������ ��� �����������
    std::vector<Base*> objects;
    objects.push_back(new Derived1());
    objects.push_back(new Derived2());

    // ��������� �������� �������
    for (auto obj : objects) {
        obj->printData();
    }

    // ��������� ��'���� �������� �����
    ComplexClass complexObj1(1, "����");
    ComplexClass complexObj2(2, "���������");

    // �������� ��� ����� ��������
    complexObj1.printMember();
    complexObj2.printMember();

    // ������� ���'���
    for (auto obj : objects) {
        delete obj;
    }

    return 0;
}