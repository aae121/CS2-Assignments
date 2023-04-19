struct Node {
    int Value;
    int Counter;
    Node* Next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    void addNode(int value, int count) {
        Node* NodeNew = new Node{ value, count, nullptr };
        if (head == nullptr) {
            head = NodeNew;
        }
        else {
            Node* current = head;
            while (current->Next != nullptr) {
                current = current->Next;
            }
            current->Next = NodeNew;
        }
    }
    void NodeDelete(int value) {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr && current->Value != value) {
            previous = current;
            current = current->Next;
        }
        if (current == nullptr) {
            return;
        }
        if (previous == nullptr) {
            head = current->Next;
        }
        else {
            previous->Next = current->Next;
        }
        delete current;
    }
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->Value << "(" << current->Counter << ")" << "->";
            current = current->Next;
        }
        cout << "null" << endl;
    }
    int sumNodes() {
        int sum = 0;
        Node* current = head;
        while (current != nullptr) {
            sum += current->Value * current->Counter;
            current = current->Next;
        }
        return sum;
    }
private:
    Node* head;
};