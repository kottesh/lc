#include <bits/stdc++.h>

//sieve of eratosthenes
void generatePrimes(std::vector<int> &primes, int n) {
    std::vector<bool> prime(n+1, true); 

    for (int i = 2; i < sqrt(n); i++) {
        if (prime[i] == true) {
            int j = pow(i, 2); 
            while (j <= n) {
                prime[j] = false;
                j += i;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (prime[i])
            primes.push_back(i);
    }
}

int main() {
    std::vector<int> primes;
    generatePrimes(primes, 10);

    for (auto prime : primes) std::cout << prime << ", ";
}
