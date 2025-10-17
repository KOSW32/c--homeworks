#include <iostream>
using namespace std;

class Student {
    char name[50];
    int age;
    int grade;
public:
    Student() { name[0] = '\0'; age = 0; grade = 0; }
    Student(const char* n, int a, int g) {
        int i = 0;
        while (n[i] != '\0' && i < 49) { name[i] = n[i]; i++; }
        name[i] = '\0';
        age = a;
        grade = g;
    }
    void set(const char* n, int a, int g) {
        int i = 0;
        while (n[i] != '\0' && i < 49) { name[i] = n[i]; i++; }
        name[i] = '\0';
        age = a;
        grade = g;
    }
    void show() const { cout << "Ім'я: " << name << ", Вік: " << age << ", Бал: " << grade << endl; }
    const char* getName() const { return name; }
};

class Group {
    char groupName[50];
    Student* students;
    int count;
public:
    Group() { groupName[0] = '\0'; students = nullptr; count = 0; }
    void setGroupName(const char* n) {
        int i = 0;
        while (n[i] != '\0' && i < 49) { groupName[i] = n[i]; i++; }
        groupName[i] = '\0';
    }
    const char* getGroupName() const { return groupName; }
    ~Group() { delete[] students; }

    void addStudent(const Student& st) {
        Student* newArr = new Student[count + 1];
        for (int i = 0; i < count; i++) newArr[i] = students[i];
        newArr[count] = st;
        delete[] students;
        students = newArr;
        count++;
    }

    void removeStudent(const char* name) {
        if (count == 0) { cout << "Група порожня.\n"; return; }
        int index = -1;
        for (int i = 0; i < count; i++) {
            const char* n = students[i].getName();
            int j = 0;
            bool equal = true;
            while (n[j] != '\0' || name[j] != '\0') {
                if (n[j] != name[j]) { equal = false; break; }
                j++;
            }
            if (equal) { index = i; break; }
        }

        if (index == -1) { cout << "Студента не знайдено.\n"; return; }

        Student* newArr = new Student[count - 1];
        int j = 0;
        for (int i = 0; i < count; i++) {
            if (i != index) {
                newArr[j] = students[i];
                j++;
            }
        }

        delete[] students;
        students = newArr;
        count--;
        cout << "Студента видалено.\n";
    }

    void showStudents() const {
        cout << "\nГрупа: " << groupName << endl;
        if (count == 0) { cout << "Немає студентів.\n"; return; }
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            students[i].show();
        }
    }
};

int main() {
    Group group;
    int choice;
    bool created = false;

    while (true) {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Створити нову групу\n";
        cout << "2. Додати студента\n";
        cout << "3. Видалити студента\n";
        cout << "4. Показати всіх студентів\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            char name[50];
            cout << "Введіть назву групи: ";
            cin >> name;
            group.setGroupName(name);
            created = true;
            cout << "Групу створено!\n";
        }
        else if (choice == 2) {
            if (!created) { cout << "Спершу створіть групу!\n"; }
            else {
                char name[50];
                int age, grade;
                cout << "Ім'я студента: ";
                cin >> name;
                cout << "Вік: ";
                cin >> age;
                cout << "Бали: ";
                cin >> grade;
                group.addStudent(Student(name, age, grade));
            }
        }
        else if (choice == 3) {
            if (!created) { cout << "Спершу створіть групу!\n"; }
            else {
                char name[50];
                cout << "Введіть ім'я студента для видалення: ";
                cin >> name;
                group.removeStudent(name);
            }
        }
        else if (choice == 4) {
            if (!created) { cout << "Спершу створіть групу!\n"; }
            else { group.showStudents(); }
        }
        else cout << "Невірний вибір!\n";
    }

    cout << "Програму завершено.\n";
    return 0;
}
