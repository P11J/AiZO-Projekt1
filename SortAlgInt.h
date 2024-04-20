#ifndef PROJEKT1_SORTALGINT_H
#define PROJEKT1_SORTALGINT_H
#include <chrono>

using namespace std;

class SortAlgInt { //klasa rodzic dla algorytmow sortowania
    public:
        chrono::steady_clock::time_point startTime;
        chrono::steady_clock::time_point endTime;
        chrono::milliseconds duration;

        static int* generateRandArray(int arraySize, int minimum, int maximum);
        static void printArray(int* array, int arraySize);
        bool isSorted(int* array, int arraySize);
};

//ponizej znajduja sie klasy dziedziczace po SortAlgInt rozniace sie algorytmem sortowania i ew. funkcjami pomocniczymi

class InsertionSortInt : public SortAlgInt{
    public:
        int* sortArray(int* array, int arraySize);
};

class HeapSortInt : public SortAlgInt{
    private:
        static void heap_fix_down(int* array, int i, int arraySize);

        static void heap_create_dn(int* array, int arraySize);

    public:
        int* sortArray(int* array, int arraySize);
};

class ShellSortInt : public SortAlgInt{
public:
    int* sortShell(int* array, int arraySize);

    int* sortHibbard(int* array, int arraySize);
};

class QuickSortInt : public SortAlgInt {
public:
    int* sort(int* array, int arraySize, int pivotIndex);

private:
    void quickSort(int *array, int left, int right);
    int partition(int *array, int left, int right, int pivotIndex);
};

#endif //PROJEKT1_SORTALGINT_H
