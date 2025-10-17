
#1

#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    void push(int value) {
        Node* n = new Node(value);
        n->next = topNode;
        topNode = n;
    }

    void pop() {
        if (empty()) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return topNode->value;
    }

    bool empty() {
        return topNode == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl; 
    s.pop();
    cout << s.top() << endl; 

    return 0;
}



#2

//#include <iostream>
//using namespace std;
//
//class Queue {
//private:
//    struct Node {
//        int value;
//        Node* next;
//        Node(int v) : value(v), next(nullptr) {}
//    };
//
//    Node* frontNode;
//    Node* backNode;
//
//public:
//    Queue() : frontNode(nullptr), backNode(nullptr) {}
//
//    ~Queue() {
//        while (!empty()) {
//            pop();
//        }
//    }
//
//    void push(int value) {
//        Node* n = new Node(value);
//        if (backNode) {
//            backNode->next = n;
//        }
//        backNode = n;
//        if (!frontNode) {
//            frontNode = n;
//        }
//    }
//
//    void pop() {
//        if (empty()) return;
//        Node* temp = frontNode;
//        frontNode = frontNode->next;
//        if (!frontNode) {
//            backNode = nullptr;
//        }
//        delete temp;
//    }
//
//    int front() {
//        if (empty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
//        }
//        return frontNode->value;
//    }
//
//    bool empty() {
//        return frontNode == nullptr;
//    }
//};
//
//int main() {
//    Queue q;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//
//    cout << q.front() << endl; 
//    q.pop();
//    cout << q.front() << endl; 
//
//    return 0;
//}
