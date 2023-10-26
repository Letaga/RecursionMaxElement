#include <iostream>
#include <algorithm>

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

    for (int i = 0; i < n; i++)
        Arr[i] = i;
    random_shuffle(&Arr[0], &Arr[n]);

    cout << "Массив\n";
    for (int i = 0; i < n; i++)
        cout << "Arr[" << i << "] = " << Arr[i] << endl;

    maxInd = SearchMax(Arr, leftInd, RightInd);

    cout << "\nЗначение максимального элемента: " << Arr[maxInd] << "\nЕго индекс: " << maxInd;

    delete[] Arr;
}

int SearchMax(int* Arr, int l, int r)
{
    int maxl, maxr, mid = (l + r) / 2;
    if (l == r)
        return r;
    if ((r - l) == 1)
    {
        if (Arr[l] > Arr[r])
            return l;
        return r;
    }
    maxl = SearchMax(Arr, l, mid);
    maxr = SearchMax(Arr, mid, r);
    if (Arr[maxl] > Arr[maxr])
        return maxl;
    else
        return maxr;
}
