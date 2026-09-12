class Node {
  public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(): key(0), value(0), next(nullptr), prev(nullptr) {};
    Node(int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {};
};

class List {
  public:
    Node* head;
    Node* last;
    int size;
    List(): size(0), head(nullptr), last(nullptr) {}
    
    void insertHead(int key, int value) {
        Node* node = new Node(key, value);
        if (head == nullptr) {
            head = last = node;
            size++;
            return;
        }
        
        node->next = head;
        head->prev = node;
        head = node;
        size++;
    }
    void insertLast(int key, int value) {
        Node* node = new Node(key, value);
        if (last == nullptr) {
            head = last = node;
            return;
        }
        
        last->next = node;
        node->prev = last;
        last = node;
        size++;
    }
    void deleteNode(Node* node) {
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        if (node == head) head = node->next;
        if (node == last) last = node->prev;
        size--;
    }
};


class LRUCache {
    unordered_map<int, Node*> mpp;
    List l;
    int size;
  public:
    LRUCache(int cap) {
        size = cap;
    }

    // TC: O(1)
    int get(int key) {
        if (mpp.count(key)) {
            int v = mpp[key]->value;
            put(key, v);
            return v;
        }
        return -1;
    }

    // TC: O(1)
    void put(int key, int value) {
        if (mpp.count(key)) {
            l.deleteNode(mpp[key]);
            mpp.erase(key);
        }
        l.insertHead(key, value);
        mpp[key] = l.head;
        if (l.size > size) {
            mpp.erase(l.last->key);
            l.deleteNode(l.last);
        }
    }
};
