#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Query {
private:
    int u, v;

public:
    Query(int uu, int vv) : u(uu), v(vv) {}

    int getU() const {
        return u;
    }

    int getV() const {
        return v;
    }
};

class Update {
private:
    int u, v, k;

public:
    Update(int uu, int vv, int kk) : u(uu), v(vv), k(kk) {}

    int getU() const {
        return u;
    }

    int getV() const {
        return v;
    }

    int getK() const {
        return k;
    }
};

class ArrayUpdater {
private:
    vector<int> arr;

public:
    ArrayUpdater(int n) : arr(n, 0) {}

    void applyUpdate(const Update& update) {
        arr[update.getU() - 1] += update.getK();
        if (update.getV() < arr.size()) {
            arr[update.getV()] -= update.getK();
        }
    }

    void calculatePrefixSum() {
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] += arr[i - 1];
        }
    }

    int getMaxValueInRange(int u, int v) const {
        int maxVal = INT_MIN;
        for (int i = u - 1; i < v; ++i) {
            maxVal = max(maxVal, arr[i]);
        }
        return maxVal;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    ArrayUpdater arrayUpdater(n);

    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        Update update(u, v, k);
        arrayUpdater.applyUpdate(update);
    }

    arrayUpdater.calculatePrefixSum();

    int p;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        Query query(u, v);
        cout << arrayUpdater.getMaxValueInRange(query.getU(), query.getV()) << endl;
    }

    return 0;
}