// IMPLEMENTING DOUBLY LINKED LIST
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node(): val(0), next(nullptr), prev(nullptr) {}
    Node(int x): val(x), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
    Node* head;
    Node* last;
    int size;
public:
    MyLinkedList(): head(nullptr), last(nullptr), size(0) {}
    
    int get(int index) {
        if (index == size) return -1;
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            if (i == index) return temp->val;
            temp = temp->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        if (last == nullptr) last = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        newNode->prev = last;
        if (last) last->next = newNode;
        last = newNode;
        if (head == nullptr) head = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        Node* temp = head;
        if (index == size - 1) {
            Node *del = last;
            last = last->prev;
            if (last == nullptr) head = nullptr;
            else last->next = nullptr;
            delete del;
        } else if (index == 0) {
            Node* del = head;
            head = head->next;
            if (head == nullptr) last = nullptr;
            else head->prev = nullptr;
            delete del;
        } else {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }

            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            temp->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }
        size--;
    }
};
