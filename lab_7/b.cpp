#include <iostream>
#include <vector>

int main() {
    int n, m;
    
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }
    
    std::vector<int> c(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    
    while (i < n) {
        c[k++] = a[i++];
    }
    
    while (j < m) {
        c[k++] = b[j++];
    }
    
    for (int x : c) {
        std::cout << x << " ";
    }
    
    return 0;
}