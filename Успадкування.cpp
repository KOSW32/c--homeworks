#include <iostream>
using namespace std;

class Pet {
private:
    char name[30];
    int age;

public:
    Pet(const char* n = "Невідомо", int a = 0) {
        int i = 0;
        while (n[i] != '\0' && i < 29) {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
        age = a;
    }

    virtual ~Pet() {}

    const char* getName() const { return name; }
    int getAge() const { return age; }

    virtual void showInfo() const {
        cout << "Ім'я: " << name << ", Вік: " << age << " років" << endl;
    }
};

class Dog : public Pet {
private:
    char breed[30];

public:
    Dog(const char* n, int a, const char* b) : Pet(n, a) {
        int i = 0;
        while (b[i] != '\0' && i < 29) {
            breed[i] = b[i];
            i++;
        }
        breed[i] = '\0';
    }

    void showInfo() const override {
        cout << "Собака — Ім'я: " << getName()
            << ", Вік: " << getAge()
            << ", Порода: " << breed << endl;
    }
};

class Cat : public Pet {
private:
    char color[20];

public:
    Cat(const char* n, int a, const char* c) : Pet(n, a) {
        int i = 0;
        while (c[i] != '\0' && i < 19) {
            color[i] = c[i];
            i++;
        }
        color[i] = '\0';
    }

    void showInfo() const override {
        cout << "Кішка — Ім'я: " << getName()
            << ", Вік: " << getAge()
            << ", Колір: " << color << endl;
    }
};

class Parrot : public Pet {
private:
    char species[20];

public:
    Parrot(const char* n, int a, const char* s) : Pet(n, a) {
        int i = 0;
        while (s[i] != '\0' && i < 19) {
            species[i] = s[i];
            i++;
        }
        species[i] = '\0';
    }

    void showInfo() const override {
        cout << "Папуга — Ім'я: " << getName()
            << ", Вік: " << getAge()
            << ", Вид: " << species << endl;
    }
};

int main() {
    Dog d("Рекс", 5, "Вівчарка");
    Cat c("Мурка", 3, "Руда");
    Parrot p("Кеша", 2, "Ара");

    d.showInfo();
    c.showInfo();
    p.showInfo();

    return 0;
}
