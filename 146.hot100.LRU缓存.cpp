class LRUCache {
public:

    typedef struct ListNode {
        int key;
        int value;
        struct ListNode* next;
        struct ListNode* prev;
    } ListNode;

    typedef struct List {
        int cap;
        int maxCap;
        ListNode* first;
        ListNode* last;
    } List;

    List list;
    unordered_map<int, ListNode*> m;

    LRUCache(int capacity) {
        list.maxCap = capacity;
        list.cap = 0;

        ListNode* dummy_h = (ListNode *)malloc(sizeof(ListNode));
        ListNode* dummy_t = (ListNode *)malloc(sizeof(ListNode));
        dummy_h->key = dummy_t->key = -1;
        dummy_h->value = dummy_t->value = -1;

        dummy_h->next = dummy_t->next = NULL;
        dummy_h->prev = dummy_t->prev = NULL;

        dummy_h->next = dummy_t;
        dummy_t->prev = dummy_h;

        list.first = dummy_h;
        list.last = dummy_t;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        printf("get %d\n", key);
        ListNode *cur = m[key];

        remove_node(cur);

        insert_head(cur);

        // show();
        return cur->value;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->value = value;
            remove_node(m[key]);
            insert_head(m[key]);
        } else {
            ListNode *cur = (ListNode *)malloc(sizeof(ListNode));
            cur->next = NULL;
            cur->prev = NULL;
            cur->key = key;
            cur->value = value;

            insert_head(cur);
            m[key] = cur;
            // show();
            if (list.cap > list.maxCap) {
                int del_k = list.last->prev->key;
                remove_node(list.last->prev);
                m.erase(del_k);
            }
            // show();
        }
        // show();
    }

private:
    void insert_head(ListNode *cur) {
        cur->next = list.first->next;
        list.first->next->prev = cur;
        list.first->next = cur;
        cur->prev = list.first;
        
        list.cap++;
    }

    void remove_node(ListNode *node) {
        // printf("del %d  prev  = %d next = %d\n", node->value, node->prev->value, node->next->value);
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // node->next = node->prev = NULL;

        list.cap--;
    }

    void show() {
        ListNode* p = list.first->next;
        int cnt = 0;

        while (p->value != -1) {
            printf("p[%d] %d : %d\n", cnt++, p->key, p->value);
            p = p->next;
        }
        printf("--\n");
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
