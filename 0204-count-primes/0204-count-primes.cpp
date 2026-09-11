class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        int x = sqrt(n);
        int ans = n - 2;
        
        // Use a raw array to bypass all C++ vector overhead
        bool* prime = new bool[n];
        memset(prime, 1, n); 
        prime[0] = prime[1] = 0;
        
        for(int i = 2; i <= x; i++){
            if(prime[i]){
                for(int j = i * i; j < n; j += i){
                    if(prime[j]){ 
                        prime[j] = 0;
                        ans--;
                    }
                }
            }
        }
        
        delete[] prime; // Prevent memory leak
        return ans;
    }
};