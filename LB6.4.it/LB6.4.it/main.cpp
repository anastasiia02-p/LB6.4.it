#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>

using namespace std;

void create(int* arr, int SIZE, double MIN, double MAX)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = (MAX - MIN) * rand() / RAND_MAX + MIN;
    }
}

void Print(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << setw(10) << fixed << setprecision(2) << arr[i];
    cout << endl;
}

int findMaxModIndex(int* arr, int SIZE)
{
    int maxModIndex = 0;
    int maxMod = abs(arr[0]);
    for (int i = 1; i < SIZE; i++)
    {
        if (abs(arr[i]) > maxMod)
        {
            maxMod = abs(arr[i]);
            maxModIndex = i;
        }
    }
    return maxModIndex;
}


int sumAfterFirstPositive(int* arr, int SIZE)
{
    int sum = 0;
    bool foundPositive = false;
    for (int i = 0; i < SIZE; i++)
    {
        if (!foundPositive && arr[i] > 0)
        {
            foundPositive = true;
        }
        else if (foundPositive)
        {
            sum += arr[i];
        }
    }
    return sum;
}

void rearrangeArray(int* arr, int SIZE, int a, int b)
{
    int* tempArr = new int[SIZE];
    int inRangeIndex = 0;
    int outRangeIndex = 0;

    for (int i = 0; i < SIZE; i++)
    {
        int wholePart = static_cast<int>(arr[i]);
        if (wholePart >= a && wholePart <= b)
        
        {
           
            outRangeIndex++;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        int wholePart = static_cast<int>(arr[i]);
        if (wholePart >= a && wholePart <= b)
        {
            tempArr[inRangeIndex++] = arr[i];
        }
        else
        {
            tempArr[outRangeIndex++] = arr[i];
        }
    }

   
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = tempArr[i];
    }

    delete[] tempArr;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE,a,b;
    cout << "Введіть розмір масиву (SIZE): "; cin >> SIZE;
    cout << "Введіть нижню межу інтервалу (a): "; cin >> a;
    cout << "Введіть верхню межу інтервалу (b): "; cin >> b;

    double MIN = -20, MAX = 20;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX);

    Print(arr, SIZE);
    cout << endl;
    cout << "Номер максимального за модулем елемента масиву: " << findMaxModIndex(arr, SIZE) << endl;
    cout << "Сума  елементів масиву, розташованих після першого додатного елементу: " << sumAfterFirstPositive(arr, SIZE) << endl;
    rearrangeArray(arr, SIZE,a,b);
    cout << "\nМасив після перетворення:" << endl;
    Print(arr, SIZE);

    delete[] arr;

    return 0;
}
