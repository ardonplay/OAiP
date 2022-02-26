#include <iostream>
using namespace std;
int main() {
    int n, m;
    cout << "Введите количество строчек N\n";
    cin >> n;
    cout << "Введите количество столбцов M\n";
    cin >> m;

    int **matrix = new int *[n]();

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m +1];

        cout << "\n";

        for (int j = 0; j < m; j++) {
            cout << "Введите элемент " << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nИсходная матрица:\n\n";

    for (int i = 0; i < n; i++, cout << endl) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
    }
    cout << "\nколичество нулей в каждой строке:\n\n";

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < m; j++){
            if (matrix[i][j] == 0) {
                count++;
            }
        }

        matrix[i][m] = count;
    }

    for (int i = 0; i < n; i++){
        cout << matrix[i][m] << "\t";
    }
    cout << "\n\n";
    cout << "\nОтсортированная матрица по убыванию:\n\n";
    for (int i = 0; i < n; i++) {
        for (int r = 0; r < n - 1; r++) {
            if (matrix[r][m] < matrix[r + 1][m]) {
                int *temp = matrix[r];
                matrix[r] = matrix[r + 1];
                matrix[r + 1] = temp;
            }

        }
    }
    for (int i = 0; i < n; i++, cout << "\n") {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
    }
    cout << "\n";
    cout<<"\nМатрица, у которой удалена строка с наибольшимм количеством нулей\n";
    if(matrix[0][m] != 0) {
        delete[] matrix[0];
        for (int i = 0; i < n - 1; i++) {
            matrix[i] = matrix[i + 1];
        }
        n--;
    }
    for (int i = 0; i < n; i++, cout << "\n") {
        for (int j = 0; j < m; j++){
            cout << matrix[i][j] << "\t";
        }
    }
    cout << "\n";
    for (int i = 0; i < n; i++) delete[] matrix[i];
    delete[] matrix;
}