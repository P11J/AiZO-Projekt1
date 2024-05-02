#ifndef PROJEKT1_SORTALGINT_H
#define PROJEKT1_SORTALGINT_H
#include <chrono>

using namespace std;

class SortAlgInt { //klasa rodzic dla algorytmow sortowania
    public:
        chrono::high_resolution_clock::time_point startTime;
        chrono::high_resolution_clock::time_point endTime;
        chrono::microseconds duration;

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

class QuickSortInt : public SortAlgInt{
private:


    int choosePivotIndex(int left, int right, int strategy);
    int partition(int *array, int left, int right, int strategy);
    void quickSort(int *array, int left, int right, int strategy);

public:
    int* sort(int* array, int arraySize, int strategy);
};

#endif //PROJEKT1_SORTALGINT_H
