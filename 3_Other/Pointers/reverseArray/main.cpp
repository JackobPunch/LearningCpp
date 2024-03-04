#include <iostream>

using namespace std;

int findMaxElement(int *arr, int size)
{
    int max{arr[0]};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void reverse_array(int *arr, int size)
{
    int sum{};
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int half = size / 2;
    int temp{};
    for (int j = 0; j < half; j++)
    {
        temp = arr[size - 1 - j];
        arr[size - 1 - j] = sum - (sum - arr[j]);
        arr[j] = temp;
    }
}

int main()
{
    int arr[] = {12, 45, 67, 23, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxElement = findMaxElement(arr, size);

    cout << "array:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    cout << "maxElement= " << maxElement << endl;

    reverse_array(arr, size);
    cout << "reverse array:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}