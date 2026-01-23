#include <iostream>
#include <functional>
using namespace std;

int main() {
    int g[9][9];

    cout << "Ingrese el Sudoku (0 para celdas vacias):\n";

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> *(*(g + i) + j);

    function<bool(int (*)[9], int, int, int)> seguro =
    [&](int (*g)[9], int f, int c, int n) {

        for (int i = 0; i < 9; i++) {
            if (*(*(g + f) + i) == n) return false;
            if (*(*(g + i) + c) == n) return false;
        }

        int sf = f - f % 3, sc = c - c % 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (*(*(g + sf + i) + sc + j) == n)
                    return false;

        return true;
    };

    function<bool(int (*)[9], int, int)> resolver =
    [&](int (*g)[9], int f, int c) -> bool {

        if (f == 9) return true;
        if (c == 9) return resolver(g, f + 1, 0);

        if (*(*(g + f) + c) != 0)
            return resolver(g, f, c + 1);

        for (int n = 1; n <= 9; n++) {
            if (seguro(g, f, c, n)) {
                *(*(g + f) + c) = n;

                if (resolver(g, f, c + 1))
                    return true;

                *(*(g + f) + c) = 0;
            }
        }
        return false;
    };

    if (resolver(g, 0, 0)) {
        cout << "\nSudoku resuelto:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << *(*(g + i) + j) << " ";
            cout << "\n";
        }
    } else {
        cout << "No tiene solucion\n";
    }

    return 0;
}
