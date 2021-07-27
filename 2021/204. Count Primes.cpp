class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> primes(n, true);
        for (int i = 2; i < n; i++) {            
            if (primes[i] && isPrime(i)) {
                count++;
                for (int j = 2; i * j < n; j++) {
                    primes[i * j] = false;
                }                
            }
        }
        return count;
    }
    
    bool isPrime(int n) {
        cout << n << endl;
        for (int i = 2; i * i <= n; i++) {            
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> primes(n, true);
        for (int i = 2; i < n; i++) {            
            if (primes[i]) {
                count++;
                for (int j = 2; i * j < n; j++) {
                    primes[i * j] = false;
                }                
            }
        }
        return count;
    }        
};

class Solution {
public:
    int countPrimes(int n) {
        int count = 0, upper = sqrt(n);
        vector<bool> primes(n, true);        
        for (int i = 2; i < n; i++) {            
            if (primes[i]) {
                count++;
                if (i > upper) continue;
                for (int j = 2; i * j < n; j++) {
                    primes[i * j] = false;
                }                
            }
        }
        return count;
    }        
};

class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (!passed[i]) {
                sum++;
                //avoid overflow
                if (i>upper) continue;
                for (int j=i*i; j<n; j+= 2 * i) {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> prime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                for (int j = 2; i * j < n; j++) {
                    prime[i * j] = false;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> prime(n, true);
        int count = 1, upper = (int)sqrt(n);
        for (int i = 3; i < n; i+=2) {
            if (prime[i]) {
                count++;
                if (i > upper) continue;
                for (int j = i * i; j < n; j += 2 * i) {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};