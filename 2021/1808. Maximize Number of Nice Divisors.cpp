typedef long long ll;
int mod = 1000000007;
ll power(ll x, ll y){
	ll res = 1;                
	while (y > 0){        
		if (y & 1)
			res = (res*x) % mod;         
		y >>= 1; // y /= 2
		x = (x*x) % mod;
	}
	return res % mod;
}

class Solution {
public:
    int maxNiceDivisors(int n) {        
        if(n <= 3)return n;        
        ll numOfDiv3 = n / 3, rem = n % 3;
        if(rem == 1) rem = 4, --numOfDiv3;
        else if(!rem) rem = 1;

        return (power(3, numOfDiv3) * rem) % mod;                                        
    }
};