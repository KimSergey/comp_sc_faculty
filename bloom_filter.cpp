#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// all constants were created as optimal parameters for N = 600000
const size_t N = 600000;
const size_t M = 10 * N;
const size_t K = 6;
const size_t P = 2147483647;

vector<int> fir;
vector<int> sec;

size_t hasher(const size_t& h, const size_t& a, const size_t& b) {
    return (((long long) a * h + b) % P) % M;
}

void insert(vector<bool>& filter, const size_t& h) {
    for (size_t i = 0; i < K; ++i) {
        filter[hasher(h, fir[i], sec[i])] = true;
    }
}

bool contains(const vector<bool>& filter, const size_t& h) {
    for (size_t i = 0; i < K; ++i) {
        if (filter[hasher(h, fir[i], sec[i])] == false) {
            return 0;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    hash<string> hash_fn;
    int n;
    int command;
    string str;
    vector<bool> filter(M);

    for (size_t i = 0; i < K; ++i) {
        fir.push_back(rand() % 100000);
        sec.push_back(rand() % 100000);
    }
    
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> command >> str;
        if (command == 1) {
            insert(filter, hash_fn(str));
        } else if (command == 0) {
            cout << contains(filter, hash_fn(str));
        }
    }
    return 0;
}
