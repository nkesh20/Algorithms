#include <bits/stdc++.h>
using namespace std;


int primes[5862593], digits[5862593], ones[5862593];
vector<bool> isPrimeNumber(101865020);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tstCase = 1;
    long long temp;
    primes[0] = 2;
    digits[0] = 2;
    ones[0] = 1;
    int idx = 1;


    for(long long i = 3; i <= 101865019; i += 2) {
        if(isPrimeNumber[i] == 0) {
            primes[idx] = i;
            for(long long j = i * i; j < 101865019; j += i) {
                isPrimeNumber[j] = 1;
            }
            temp = i;
            int digit = 0;
            int count = 0;
            while(temp != 0) {
                digit++;
                if(temp % 2 == 1) {
                    count++;
                }
                temp /= 2;
            }
            digits[idx] = digits[idx - 1] + digit;
            ones[idx] = ones[idx - 1] + count;
            idx++;
        }
    }


    cin >> tstCase;
    for(int i = 0; i < tstCase; i++) {
        int number;
        cin >> number;
        int num = upper_bound(digits, digits + 5862593, number) - digits;
        int largestDigit = digits[num];
        int largestPrime = primes[num];
        int ans = ones[num];

        for(int i = largestDigit; i > number; i--) {
            if(largestPrime % 2 == 1) {
                ans--;
            }
            largestPrime /= 2;
        }
        cout << ans << "\n";
    }
}


