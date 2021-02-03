class ProductOfNumbers {
public:
    vector<int> products;
    int lastZeroIndex;
    
    ProductOfNumbers() {        
        lastZeroIndex = -1;
    }
    
    void add(int num) {    
        if (num == 0 || products.empty() || products.back() == 0) {
            lastZeroIndex = (num == 0) ? products.size() : lastZeroIndex;
            products.push_back(num);
        } else {
            products.push_back(num * products.back());        
        }
    }
    
    int getProduct(int k) {                 
        int size = products.size();
        if ((size - k) <= lastZeroIndex) {
            return 0;
        }       
        if (k >= size) {
            return products.back();
        }        
        return products[size - k - 1] == 0 ? products.back() : products.back() / products[size - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

class ProductOfNumbers {
public:
    vector<int> products;
    
    ProductOfNumbers() {        
        products.push_back(1);
    }
    
    void add(int num) {    
        if (num == 0) {
            products = {1};
        } else {
            products.push_back(products.back() * num);
        }
    }
    
    int getProduct(int k) {                 
        int size = products.size();
        return (k < size) ? products.back() / products[products.size() - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */