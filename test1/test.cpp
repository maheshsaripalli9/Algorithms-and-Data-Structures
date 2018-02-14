#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    srand(time(NULL));
    cout.precision(10);
    cout << " Estimating of Pi using Monte Carlo technique" << endl;
    const int N[] = {1e3, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9};
    for (int i = 0; i < (sizeof(N) / sizeof(N[0])); i ++) {
        int circle = 0;
        for (int j = 0; j < N[j]; j ++) {
            double x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            double y = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
            if (x * x + y * y <= 1.0) {
    circle ++;
}
        }
        cout << N[i] << (char)9 << (char)9 << (double)circle / N[i] * 4.0 << endl;
    }
    return 0;
}
