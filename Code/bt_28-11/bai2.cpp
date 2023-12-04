#include <iostream>
#include <vector>
using namespace std;

class ExpressionSolver {
private:
    int n;
    vector<int> signs;

public:
    ExpressionSolver(int N) : n(N), signs(N + 1, 0) {}

    void solve(int S) {
        int sum = n * (n + 1) / 2;
        for (int i = n; i >= 1; --i) {
            if (sum - 2 * i >= S) {
                signs[i] = 1;
                sum -= 2 * i;
            }
        }
        
        if (sum == S) {
            if (signs[1]) {
                for (int i = 4; i <= n; ++i) {
                    if (!signs[1]) break;
                    if (signs[i]) {
                        for (int j = 2; j <= i / 2; ++j) {
                            if (signs[j] == 0 && signs[i + 1 - j] == 0) {
                                signs[j] = signs[i + 1 - j] = 1;
                                signs[1] = signs[i] = 0;
                                break;
                            }
                        }
                    }
                }
                if (signs[1]) {
                    cout << "Impossible" << endl;
                    return;
                }
            }
            cout << "1";
            for (int i = 2; i <= n; ++i) {
                cout << (signs[i] == 1 ? '-' : '+') << i;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }
};

int main() {
    int N, S;
    cin >> N >> S;

    ExpressionSolver exprSolver(N);
    exprSolver.solve(S);

    return 0;
}
