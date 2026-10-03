
class LRUCache {
private:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    std::unordered_map<int, Node*> m;
    Node* head;
    Node* tail;

    void addNode(Node* newNode) {
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* resNode = m[key];
        int ans = resNode->val;
        
        deleteNode(resNode);
        addNode(resNode);
        m[key] = head->next;
        
        return ans;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* curr = m[key];
            curr->val = value;
            deleteNode(curr);
            addNode(curr);
            m[key] = head->next;
            return;
        }
        
        if (m.size() == capacity) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            deleteNode(lru);
            delete lru;
        }
        
        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = head->next;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */