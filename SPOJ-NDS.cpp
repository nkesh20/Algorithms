#include <bits/stdc++.h>

using namespace std;

long long arr[1000009], arr1[1000009], arr2[1000009];


long long solve(long long n, long long l) {
    long long k, t = 0;
    for (long long i = 0; i < n; i++) {
        arr1[i] = arr2[i] = 0;
    }
    for (long long i = 0; i < n; i++) {
        k = lower_bound(arr2 + 1, arr2 + t + 1, arr[i]) - arr2;
        t = max(t, k);
        arr1[i] = k, arr2[k] = arr[i];
    }
    long long minimum = LLONG_MAX;
    for (long long i = 0; i < n; i++) {
        if (arr1[i] == l) {
            minimum = min(minimum, arr[i]);
        }
    }
    if (minimum == LLONG_MAX) {
        minimum = -1;
    }
    return minimum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long numTests, arrLen, seqLen;
    cin >> numTests;
    for (long long i = 0; i < numTests; i++) {
        cin >> arrLen;
        for (long long j = 0; j < arrLen; j++) {
            cin >> arr[j];
        }
        cin >> seqLen;
        cout << solve(arrLen, seqLen) << endl;
    }
    return 0;
}