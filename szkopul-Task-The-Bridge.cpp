#include <bits/stdc++.h>

using namespace std;

int findMinimumTime(int times[], int n) {
    if (n < 3) {
        return times[n - 1];
    } else if (n == 3) {
        return times[0] + times[1] + times[2];
    } else {
        int time1 = times[n - 1] + 2 * times[0] + times[n - 2];
        int time2 = 2 * times[1] + times[0] + times[n - 1];
        if (time1 < time2) {
            return time1 + findMinimumTime(times, n - 2);
        } else {
            return time2 + findMinimumTime(times, n - 2);
        }
    }

}


int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> k;
        arr[i] = k;
    }

    cout << findMinimumTime(arr, n);

    return 0;
}