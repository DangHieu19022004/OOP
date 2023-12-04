#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<long long> nums;
int N;
long long S;

bool check(long long sum, int idx) {
    if (idx == N - 1) {
        return sum == S;
    }

    if (check(sum + nums[idx + 1], idx + 1)) {
        cout << "+";
        return true;
    }
    if (check(sum - nums[idx + 1], idx + 1)) {
        cout << "-";
        return true;
    }
    if (check(sum + 2 * nums[idx + 1], idx + 1)) {
        cout << ".";
        return true;
    }
    if (check(sum - 2 * nums[idx + 1], idx + 1)) {
        cout << "~";
        return true;
    }

    return false;
}

int main() {
    cin >> N >> S;
    nums.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    if (check(nums[0], 0)) {
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}
