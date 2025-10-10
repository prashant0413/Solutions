class Node
{
public:
    Node *prev;
    int key;
    int val;
    int cnt;
    Node *next;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        cnt = 1;
        prev = next = nullptr;
    }
};

class List
{
public:
    int size;
    Node *head;
    Node *last;

    List()
    {
        this->size = 0;
        head = new Node(-1, -1);
        last = new Node(-1, -1);
        head->next = last;
        last->prev = head;
    }

    void addFront(Node *node)
    {
        Node *headNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
        size++;
    }

    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};

class LFUCache
{
    unordered_map<int, Node *> keyNode;
    unordered_map<int, List *> freqList;
    int capacity;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = curSize = 0;
    }

    void freqUpdateListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqList[node->cnt]->deleteNode(node);

        if (node->cnt == minFreq && freqList[node->cnt]->size == 0)
        {
            minFreq++;
        }

        List *nextHighFreqList = new List();
        if (freqList.find(node->cnt + 1) != freqList.end())
        {
            nextHighFreqList = freqList[node->cnt + 1];
        }

        node->cnt += 1;
        nextHighFreqList->addFront(node);
        freqList[node->cnt] = nextHighFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->val;
            freqUpdateListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->val = value;
            freqUpdateListMap(node);
        }
        else
        {
            if (curSize >= capacity)
            {
                List *list = freqList[minFreq];
                keyNode.erase(list->last->prev->key);
                list->deleteNode(list->last->prev);
            }

            curSize++;
            minFreq = 1;
            List *list = new List();
            if (freqList.find(minFreq) != freqList.end())
            {
                list = freqList[minFreq];
            }
            Node *node = new Node(key, value);
            list->addFront(node);
            freqList[minFreq] = list;
            keyNode[key] = node;
        }
    }
};
