// APPROACH 1: USING DOUBLY LINKED LIST
// TC: O(N)
// SC: O(N)
class Node {
public:
    int key;
    int data;
    Node *next;
    Node *prev;
    Node(): data(0), next(nullptr), prev(nullptr) {}
    Node(int k, int d): key(k), data(d), next(nullptr), prev(nullptr) {}
};

class DLL {
    Node* head;
    Node* last;
public:
    DLL(): head(nullptr), last(nullptr) {}

    void add(int key, int data) {
        Node* newNode = new Node(key, data);
        if (head == nullptr) {
            head = last = newNode;
        } else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }

    void deleteNode(Node* node) {
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        if (node == head)
            head = head->next;
        if (node == last)
            last = node->prev;
    }

    Node* isPresent(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->key == key) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

class MyHashMap {
    DLL l;
public:
    MyHashMap() {}
    
    void put(int key, int value) {
        if (l.isPresent(key)) {
            remove(key);
        }
        l.add(key, value);
    }
    
    int get(int key) {
        Node* t = l.isPresent(key);
        return t ? t->data : -1;
    }
    
    void remove(int key) {
        Node* temp = l.isPresent(key);
        if (temp) l.deleteNode(temp);
        return;
    }
};
