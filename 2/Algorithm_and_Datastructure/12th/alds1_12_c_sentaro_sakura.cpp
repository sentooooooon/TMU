#include <iostream>
#include <vector>
#include <limits>

using namespace std;

template<typename T>
struct MinHeap {
    vector<T> v;
    size_t h;
    const T E = make_pair(numeric_limits<long long>::max(), numeric_limits<int>::max());

    MinHeap() : v(1), h(0) {} 

    void insert(const T &key) {
        h++;
        v.push_back(E);
        heapIncreaseKey(h, key);
    }

    void heapIncreaseKey(int k, const T &key) {
        if (key > v[k]) {
            cerr << "Error: heapIncreaseKey()\n";
            exit(1);
        }
        v[k] = key;
        while (k > 1 && v[k / 2] > v[k]) {
            swap(v[k], v[k / 2]);
            k = k / 2;
        }
    }

    T get() const {
        if (h < 0) {
            cerr << "Error: queue is empty\n";
            exit(1);
        }
        return v[1];
    }

    T pop() {
        if (h < 0) {
            cerr << "Error: queue is empty\n";
            exit(1);
        }

        T maximum = v[1];
        v[1] = v[h];
        v.pop_back();
        h--;
        heapify(1);

        return maximum;
    }

    void heapify(int k) {
        int l = k * 2;
        int r = k * 2 + 1;

        int largest;
        if (l <= h && v[k] > v[l]) {
            largest = l;
        } else {
            largest = k;
        }

        if (r <= h && v[largest] > v[r]) {
            largest = r;
        }

        if (largest != k) {
            swap(v[k], v[largest]);
            heapify(largest);
        }
    }

    size_t size() const {
        return h;
    }

    bool empty() const {
        return h == 0;
    }
};

int main() {
        int n;
        cin >> n;

        vector<vector<pair<int, int> > > g(n);

        for (int i = 0; i < n; ++i) {
            int u, k;
            cin >> u >> k;

            for (int j = 0; j < k; ++j) {
                int v, c;
                cin >> v >> c;
                g[u].emplace_back(v, c);
            }
        }

        vector<long long> dist(n, numeric_limits<long long>::max() / 3);
        MinHeap<pair<long long, int> > pq;

        dist[0] = 0;
        pq.insert(make_pair(0, 0));

        while (!pq.empty()) {
            auto [cur_cost, cur_node] = pq.pop();
            if (dist[cur_node] < cur_cost) continue;
            for (auto [to, cost] : g[cur_node]) {
                if (dist[to] > dist[cur_node] + cost) {
                    dist[to] = dist[cur_node] + cost;
                    pq.insert(make_pair(dist[to], to));
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << i << ' ' << dist[i] << '\n';
        }

        return 0;
}
