class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isprime(n, true);
        isprime[0] = isprime[1] = false;

        // Only sieve up to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isprime[i]) {
                // Start marking from i * i and increment by i
                for (long long j = 1LL * i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }

        // Count all remaining primes
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isprime[i]) count++;
        }

        return count;
    }
};