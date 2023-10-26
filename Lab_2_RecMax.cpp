#include <iostream>

using namespace std;

int SearchMax(int* Arr, int l, int r);

int main()
{
    int n;
    setlocale(LC_ALL, "Ru");
    cout << "Введите размерность массива\n";
    cin >> n;
    int* Arr = new int[n];
    int maxInd, leftInd = 0, RightInd = n - 1;

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        Arr[i] = rand() % 10;

    cout << "массив\n";
    for (int i = 0; i < n; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << Arr[i] << " ";

    maxInd = SearchMax(Arr, leftInd, RightInd);

    cout << "Arr[max] = " << Arr[maxInd] << " Index = " << maxInd;

    delete[] Arr;
}

int SearchMax(int* Arr, int l, int r)
{
    int maxi, maxl, maxr;

    if (l == r)
        return maxi = l;

    maxl = SearchMax(Arr, l, r / 2);
    maxr = SearchMax(Arr, l / 2, r);
    if (Arr[maxl] > Arr[maxr])
        return maxl;
    else
        return maxr;
}
