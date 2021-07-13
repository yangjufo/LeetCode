class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(n * 2, 0);
        for (int i = n, j = 0; i < 2 * n; i++, j++) {
            tree[i] = nums[j];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val;
        while (index > 0) {
            int left = index, right = index;
            if ((index & 0x1) == 0) {
                right = index + 1;
            } else {
                left = index - 1;
            }
            tree[index / 2] = tree[left] + tree[right];
            index >>= 1;
        }
    }
    
    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while (left <= right) {
            if ((left & 0x1) == 1) {
                sum += tree[left];
                left++;
            }
            if ((right & 0x1) == 0) {
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class Node {
public:
    int val, start, end;
    Node *left, *right;
    Node() {
        Node(0, 0, 0);
    }
    Node(int _val, int _start, int _end) {
        val = _val;
        start = _start;
        end = _end;
        left = right = NULL;
    }
};

class NumArray {
public:
    Node* root;
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    Node* buildTree(vector<int>& nums, int start, int end) {        
        if (start > end) return NULL;
        Node* node = new Node(0, start, end);
        if (start == end) {
            node->val = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            node->left = buildTree(nums, start, mid);
            node->right = buildTree(nums, mid + 1, end);
            node->val = (node->left ? node->left->val : 0) + (node->right ? node->right->val : 0);
        }
        return node;
    }
     
    void update(int index, int val) {
        update(index, val, root);
        
    }
    
    void update(int index, int val, Node* node) {
        if (node == NULL) return;
        if (node->start == node->end && node->start == index) {
            node->val = val;
        } else {
            int mid = node->start + (node->end - node->start) / 2;
            if (index <= mid) {
                update(index, val, node->left);
            } else {
                update(index, val, node->right);
            }
            node->val = node->left->val + node->right->val;
        }
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, root);
    }
    
    int sumRange(int start, int end, Node* node) {        
        if (node == NULL) return 0;
        if (node->start == start && node->end == end) {
            return node->val;
        }
        int mid = node->start + (node->end - node->start) / 2;
        if (end <= mid) {
            return sumRange(start, end, node->left);
        } else if (start >= mid + 1) {
            return sumRange(start, end, node->right);
        }
        return sumRange(start, mid, node->left) + sumRange(mid + 1, end, node->right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */