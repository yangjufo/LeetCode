/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> randNodeMap;
        Node *dummy = new Node(0), *prev = dummy, *node = head;        
        
        while (node != NULL) {
            Node *clone = new Node(node->val);
            prev->next = clone;
            prev = clone;
            randNodeMap[node] = clone;
            node = node->next;
        }
        Node* cloneHead = dummy->next;    
        while (head != NULL) {
            cloneHead->random = randNodeMap[head->random];
            head = head->next;
            cloneHead = cloneHead->next;
        }
        
        cloneHead = dummy->next;
        delete dummy;
        
        return cloneHead;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        Node *node = head;
        while (node != NULL) {
            Node* clone = new Node(node->val);
            clone->next = node->next;
            node->next = clone;            
            node = clone->next;
        }       
        
        node = head;
        
        while (node != NULL) {
            node->next->random = (node->random == NULL) ? NULL : node->random->next;
            node = node->next->next;
        }
        
        Node *oldNode = head, *cloneNode = head->next, *cloneHead = head->next;
        while (oldNode != NULL) {
            oldNode->next = oldNode->next->next;
            cloneNode->next = (cloneNode->next == NULL) ? NULL : cloneNode->next->next;
            oldNode = oldNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        Node* node = head;
        while (node != NULL) {
            Node* clone = new Node(node->val);
            clone->next = node->next;
            node->next = clone;
            node = clone->next;
        }
                     
        node = head;
        Node* cloneHead = node->next, *clone = cloneHead;
        while (node != NULL) {            
            clone->random = node->random == NULL ? NULL : node->random->next;            
            node = node->next == NULL ? NULL : node->next->next;            
            clone = clone->next == NULL ? NULL : clone->next->next;
        }
        
        node = head;
        clone = cloneHead;
        while (node != NULL) {
            node->next = clone->next;
            node = node->next;
            clone->next = node == NULL ? NULL : node->next;
            clone = clone->next;
        }
        
        return cloneHead;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        
        Node* node = head;
        while (node != NULL) {
            Node* clone = new Node(node->val);
            clone->next = node->next;
            node->next = clone;
            node = clone->next;
        }
                     
        node = head;
        Node* cloneHead = node->next, *clone = cloneHead;
        while (node != NULL) {            
            clone->random = node->random == NULL ? NULL : node->random->next;            
            node = node->next == NULL ? NULL : node->next->next;            
            clone = clone->next == NULL ? NULL : clone->next->next;
        }
        
        node = head;
        clone = cloneHead;
        while (node != NULL) {
            node->next = clone->next;
            node = node->next;
            clone->next = node == NULL ? NULL : node->next;
            clone = clone->next;
        }
        
        return cloneHead;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        Node* curr = head;
        while (curr != NULL) {            
            if (nodeMap.find(curr) == nodeMap.end()) {
                nodeMap[curr] = new Node(curr->val);
            }
            curr = curr->next;
        }
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                nodeMap[curr]->random = nodeMap[curr->random];
            }
            if (curr->next != NULL) {
                nodeMap[curr]->next = nodeMap[curr->next];
            }
            curr = curr->next;
        }
        return nodeMap[head];
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* cloneHead = NULL, *curr = head;
        // clone nodes, put the new node right after the original node
        while (curr != NULL) {
            Node* next = curr->next, *clone = new Node(curr->val);
            if (cloneHead == NULL) {
                cloneHead = clone;
            }
            curr->next = clone;
            clone->next = next;
            curr = next;
        }        
        
        // let the clone node point to the random node
        curr = head;
        while (curr != NULL) {   
            Node* clone = curr->next, *next = clone->next;            
            if (curr->random != NULL) {
                clone->random = curr->random->next;
            }                        
            curr = next;
        }
        
        // split two lists
        curr = head;
        Node* prev = NULL; // pointer for the clone list
        while (curr != NULL) {
            Node* clone = curr->next, *next = clone->next;
            curr->next = next;
            if (prev != NULL) {
                prev->next = clone;
            }
            prev = clone;
            curr = next;
        }
        return cloneHead;
    }
};