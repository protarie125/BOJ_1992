#include <iostream>
#include <vector>
#include <string>

using namespace std;

using Image = vector<string>;

void solve(int N, const Image& img, int x, int y) {
    if (1 == N) {
        cout << img[y][x];
        return;
    }

    const auto beg = img[y][x];
    bool isOne{ true };
    for (int i = y; i < y + N && isOne; ++i)
    {
        for (int j = x; j < x + N && isOne; ++j)
        {
            if (beg != img[i][j]) {
                isOne = false;
                break;
            }
        }
    }

    if (isOne) {
        cout << beg;
    }
    else {
        auto n = N / 2;
        cout << '(';
        solve(n, img, x, y);
        solve(n, img, x + n, y);
        solve(n, img, x, y + n);
        solve(n, img, x + n, y + n);
        cout << ')';
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;

    Image img(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> img[i];
    }

    solve(N, img, 0, 0);

    return 0;
}