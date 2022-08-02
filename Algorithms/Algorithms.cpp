#include <iostream>
#include <chrono>

#define ARRAY_SIZE 100

using namespace std;

uint32_t GetNanos();
void FillArray(int ArrayToFill[], int SizeofArray);

void BubbleSort(int ArrayToSort[], int SizeofArray);



int main()
{
    int Dataset[ARRAY_SIZE];

    srand(time(nullptr));
    FillArray(Dataset, ARRAY_SIZE);

    uint32_t StartNanos = GetNanos();
    BubbleSort(Dataset, ARRAY_SIZE);
    uint32_t EndNanos = GetNanos();
    cout << "Bubble Sort took " << (EndNanos - StartNanos) << " ns to complete";
}

uint32_t GetNanos()
{
    using namespace std::chrono;
    return static_cast<uint32_t>(duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count());
}

void FillArray(int ArrayToFill[], int SizeofArray)
{
    for (int i = 0; i < SizeofArray; i++)
    {
        ArrayToFill[i] = rand() % ARRAY_SIZE + 1;
    }
}

void BubbleSort(int ArrayToSort[], int SizeofArray)
{
    for (int i = 0; i < SizeofArray; i++)
    {
        for (int j = 0; j < SizeofArray-1; j++)
        {
            if (ArrayToSort[j] > ArrayToSort[j + 1])
            {
                int temp = ArrayToSort[j];
                ArrayToSort[j] = ArrayToSort[j + 1];
                ArrayToSort[j + 1] = temp;
            }

        }
    }
}