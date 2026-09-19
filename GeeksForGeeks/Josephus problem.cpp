// APPROACH 1: USING ARRAY
// TC: O(N . N)
// SC: O(N)
class Solution {
public:
    int josephus(int n, int k) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        int i = 0;
        while (arr.size() > 1) {
            int idx = (i + k - 1) % arr.size();
            arr.erase(arr.begin() + idx);
            i = idx;
        }

        return arr[0];
    }
};

// APPROACH 2: USING CIRCULAR DOUBLY LINKED LIST
// TC: O(N . K)
// SC: O(N)
class Node {
  public:
    int val;
    Node* prev;
    Node* next;
    Node(): val(0), prev(nullptr), next(nullptr) {}
    Node(int x): val(x), prev(nullptr), next(nullptr) {}
};

class List {
  public:
    Node *head;
    Node *last;
    int size;
    List(): head(nullptr), last(nullptr), size(0) {}
    void add(int x) {
        size++;
        Node *newNode = new Node(x);
        if (head == nullptr) {
            head = last = newNode;
        } else {
            last->next = newNode;
            newNode->next = head;
            newNode->prev = last;
            head->prev = newNode;
            last = newNode;
        }
    }
    void deleteNode(Node *node) {
        size--;
        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;
        if (node == last) {
            last = node->prev;
        }
        if (node == head) {
            head = node->next;
        }
        delete node;
    }
};

class Solution {
  private:
    void solve(int n, int k, List &l, Node *node) {
        if (l.size == 1) return;
        for (int i = 1; i < k; i++)
            node = node->next;
            
        Node *nextNode = node->next;
        l.deleteNode(node);
        solve(n, k, l, nextNode);
    }
  public:
    int josephus(int n, int k) {
        List l;
        for (int i = 1; i <= n; i++) {
            l.add(i);
        }
        
        solve(n, k, l, l.head);
        return l.head->val;
    }
};

// APPROACH 3: USING QUEUE
// TC: O(N . K)
// SC: O(N)
class Solution {
public:
    int josephus(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);

        while (q.size() > 1) {
            for (int i = 1; i <= k - 1; i++) {
                int x = q.front();
                q.pop();
                q.push(x);
            }

            q.pop();
        }

        return q.front();
    }
};
