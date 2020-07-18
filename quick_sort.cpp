#include <iostream>

void quickSort(int*, int, int);
int quickSwap(int*, int, int);
int swap(int&, int&);
void print(int*, int);

int main()
{
    int n = 0;

    std::cout << "Enter number of array elements: ";
    std::cin >> n;

    int arr[n];
    int element = 0;

    std::cout << "\n==== Enter array elements ====\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << "element " << i + 1 << " : ";
        std::cin >> element;
        arr[i] = element;
    }

    std::cout << std::endl;

    std::cout << "==== Array before sorting ====" << std::endl;
    print(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << std::endl << std::endl;

    std::cout << "==== Array after sorting ====" << std::endl;
    print(arr, n);

    std::cout << std::endl;
}

/* function for quck sorting */
void quickSort(int* arr, int first, int last)
{
    if (first <= last)
    {
        int index = quickSwap(arr, first, last);
        quickSort(arr, first, index - 1);
        quickSort(arr, index + 1, last);
    }
}


/* function will compare array elements with pivot,
if array element is greater than pivot it must be moved into left hand of pivot*/
int quickSwap(int* arr, int first, int last)
{
    int index = first;
    int pivot = arr[last];

    for(int i = first; i < last; ++i)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[index], arr[i]);
            ++index;
        }
    }

    swap(arr[index], arr[last]);

    return index;
}

/* function to swap two values */
int swap(int& val1, int& val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

/* function to desplay array element */
void print(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}