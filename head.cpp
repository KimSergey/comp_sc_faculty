#include <iostream>
#include <fstream>
#include <iomanip>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>
#include <random>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;
using ll = long long;

const ll INF = static_cast<ll>(1e9) + 7ll;
const ll LINF = INF * INF;
const int MAXN = static_cast<int>(1e6) + 17;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    vector<int> nums;

    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    for (auto x : nums) {
        cout << x << endl;
    }
    return 0;
}
