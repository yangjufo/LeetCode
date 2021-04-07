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