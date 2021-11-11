// Lab 6.4 iter
// Кулик Олег ІК-11
#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>


using namespace std;

void Create(int* parr, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        parr[i] = Low + rand() % (High - Low + 1);
}

void Print(int* parr, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << parr[i];
    cout << endl;
}
int sum(int* a, int n)
{
    int seen = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (!seen && a[i] < 0)
        {
            seen = 1;
            continue;
        }
        if (seen && a[i] > 0)
        {
            sum += a[i];
            continue;
        }
        if (seen && a[i] < 0)
        {
            break;
        }
    }
    return sum;
}

void min_i(int a[], const int SIZE)
{
    cout << "Number of minimal element: ";
    int min = a[0];
    for (int i = 1; i < SIZE; i++)
        if (a[i] < min)
            min = a[i];
    for (int j = 0; j < SIZE; j++)
        if (min == a[j])
            cout << j << " ";
    cout << "\n Minimal element:" << min << endl;
}


void convert(int* a, int n)
{
    int to_put = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) <= 1)
        {
            swap(a[i], a[to_put]);
            to_put++;
        }
    }
}



int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "n = ";
    cin >> n;
    int* a = new int[n];

    int Low;
    int High;
    cout << "Low = "; cin >> Low;
    cout << "High = "; cin >> High;

    Create(a, n, Low, High);
    Print(a, n);
    min_i(a, n);
    cout << "sum of array elements between two negative elements = " << sum(a, n) << endl;
    convert(a, n);
    Print(a, n);

    return 0;
}
