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
        if (head == NULL) {
            return NULL;
        }
        Node* node = head;
        while (node != NULL) {
            Node* clone = new Node(node->val);
            clone->next = node->next;
            node->next = clone;
            node = clone->next;
        }

        node = head;
        while (node != NULL) {
            node->next->random = node->random == NULL ? NULL : node->random->next;
            node = node->next->next;
        }
        Node* cloneHead = head->next;
        Node* oldNode = head, *cloneNode = head->next;
        while (oldNode != NULL) {
            oldNode->next = oldNode->next->next;
            cloneNode->next = cloneNode->next == NULL ? NULL : cloneNode->next->next;
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
        unordered_map<Node*, Node*> copy;
        Node* dummy = new Node(0), *prev = dummy;
        while (head != NULL) {
            Node *curr = NULL;
            if (copy.find(head) != copy.end()) {
                curr = copy[head];
            } else {
                curr = new Node(head->val);
                copy[head] = curr;
            }
            Node* random = NULL;
            if (head->random != NULL) {
                if (copy.find(head->random) != copy.end()) {
                    random = copy[head->random];
                } else {
                    random = new Node(head->random->val);
                    copy[head->random] = random;
                }
            }
            curr->random = random;
            prev->next = curr;
            prev = curr;
            head = head->next;
        }
        return dummy->next;
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
        if (head == NULL) {
            return NULL;
        }
        Node* node = head;
        while (node != NULL) {
            Node* clone = new Node(node->val);
            clone->next = node->next;
            node->next = clone;
            node = clone->next;
        }
        node = head;
        while (node != NULL) {
            node->next->random = node->random == NULL ? NULL : node->random->next;
            node = node->next->next;
        }
        Node* cloneHead = head->next;
        Node* oldNode = head, *cloneNode = head->next;
        while (cloneNode != NULL) {
            oldNode->next = oldNode->next->next;
            cloneNode->next = cloneNode->next == NULL ? NULL : cloneNode->next->next;
            oldNode = oldNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};