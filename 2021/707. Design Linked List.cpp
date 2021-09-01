class LinkedNode {
public:
    int val;
    LinkedNode *prev, *next;
    
    LinkedNode(int _val) {
        val = _val;
        prev = next = NULL;
    }
};

class MyLinkedList {
public:    
    LinkedNode *head, *tail;  
    int size = 0;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new LinkedNode(0);
        tail = new LinkedNode(0);  
        head->next = tail;
        tail->prev = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) return -1;
        LinkedNode* node = head->next;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;     
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        node->next = tail;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        LinkedNode* node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }        
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = node->next;
        node->next->prev = newNode;
        newNode->prev = node;
        node->next = newNode;            
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;
        LinkedNode* node = head->next;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        size--;
    }
    
    void print() {
        LinkedNode* node = head->next;
        while (node != tail) {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */