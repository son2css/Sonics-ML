#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using ull = unsigned long long;

int main() {
    int n;
    while (std::cin >> n && n != 0) {             // multi-test: stop at 0

        // ---- read patterns and compute their hashes ----
        std::vector<ull> hashes;
        std::vector<std::string> name;
        for (int k = 0; k < n; k++) {
            std::string s;
            std::cin >> s;
            ull hash = 0, p = 1;
            for (int i = 0; i < s.size(); i++) {
                hash += s[i] * p;
                p *= 29;
            }
            name.push_back(s);
            hashes.push_back(hash);
        }

        // ---- read text ----
        std::string tot;
        std::cin >> tot;
        int t = tot.size();

        // ---- powers of 29 and prefix hashes of the text ----
        std::vector<ull> pw(t), h(t);
        pw[0] = 1;
        for (int i = 1; i < t; i++) pw[i] = pw[i - 1] * 29;
        h[0] = tot[0];
        for (int i = 1; i < t; i++) h[i] = h[i - 1] + tot[i] * pw[i];

        // ---- count each pattern (Rabin–Karp) ----
        std::vector<int> cnt(n, 0);
        int mx = 0;
        for (int k = 0; k < n; k++) {             // k = pattern
            
            int m = name[k].size();
            for (int i = 0; i + m <= t; i++) {    // i = window start
                ull curr = h[i + m - 1];
                if (i > 0) curr -= h[i - 1];      // window hash × 29^i
                if (hashes[k] * pw[i] == curr)    // pattern hash × 29^i
                    cnt[k]++;
            }
            mx = std::max(mx, cnt[k]);
        }

        std::cout << mx << "\n";
        for (int k = 0; k < n; k++)
            if (cnt[k] == mx) std::cout << name[k] << "\n";
    }
    return 0;
}