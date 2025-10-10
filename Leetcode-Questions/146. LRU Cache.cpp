class Node
{
public:
    Node *prev;
    int key;
    int val;
    Node *next;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache
{
    unordered_map<int, Node *> mpp;
    Node *head;
    Node *last;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        mpp.clear();
        head = new Node(-1, -1);
        last = new Node(-1, -1);
        head->next = last;
        last->prev = head;
    }

    int get(int key)
    {
        if (mpp.find(key) == mpp.end())
            return -1;

        Node *getNode = mpp[key];
        int res = getNode->val;
        mpp.erase(key);
        deleteNode(getNode);
        insertAtHead(getNode);
        mpp[key] = head->next;
        return res;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *existNode = mpp[key];
            mpp.erase(key);
            deleteNode(existNode);
        }
        else if (mpp.size() >= capacity)
        {
            mpp.erase(last->prev->key);
            deleteNode(last->prev);
        }
        insertAtHead(new Node(key, value));
        mpp[key] = head->next;
    }

    void insertAtHead(Node *node)
    {
        Node *headNext = head->next;
        head->next = node;
        node->next = headNext;
        node->prev = head;
        headNext->prev = node;
    }
    void deleteNode(Node *node)
    {
        Node *prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
        // delete (node);
    }
};
