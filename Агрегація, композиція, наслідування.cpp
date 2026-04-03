#include <iostream>
using namespace std;

// ================== АГРЕГАЦИЯ ==================
class EngineA {
public:
    void Start() {
        cout << "EngineA started\n";
    }
};

class CarA {
private:
    EngineA* engine;

public:
    CarA(EngineA* eng) {
        engine = eng;
    }

    void Drive() {
        engine->Start();
        cout << "CarA is driving\n";
    }
};

// ================== КОМПОЗИЦИЯ ==================
class EngineB {
public:
    void Start() {
        cout << "EngineB started\n";
    }
};

class CarB {
private:
    EngineB engine;

public:
    void Drive() {
        engine.Start();
        cout << "CarB is driving\n";
    }
};

// ================== СПАДКУВАННЯ ==================
class Animal {
public:
    void Eat() {
        cout << "Animal eats\n";
    }
};

class Dog : public Animal {
public:
    void Bark() {
        cout << "Dog barks\n";
    }
};

// ================== ВВЫВОД ==================
int main() {

    cout << "=== Aggregation ===\n";
    EngineA engA;
    CarA carA(&engA);
    carA.Drive();

    cout << "\n=== Composition ===\n";
    CarB carB;
    carB.Drive();

    cout << "\n=== Inheritance ===\n";
    Dog dog;
    dog.Eat();
    dog.Bark();

    return 0;
}