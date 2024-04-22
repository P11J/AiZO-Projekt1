
#ifndef PROJEKT1_SORTALGFLOAT_H
#define PROJEKT1_SORTALGFLOAT_H

#include <chrono>

using namespace std;

class SortAlgFloat { //klasa rodzic dla algorytmow sortowania
public:
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    chrono::milliseconds duration;

    static float* generateRandArray(int arraySize, float minimum, float maximum);
    static void printArray(float* array, int arraySize);
    bool isSorted(float* array, int arraySize);
};

//ponizej znajduja sie klasy dziedziczace po SortAlgInt rozniace sie algorytmem sortowania i ew. funkcjami pomocniczymi

class InsertionSortFloat : public SortAlgFloat{
public:
    float* sortArray(float* array, int arraySize);
};

class HeapSortFloat : public SortAlgFloat{
private:
    static void heap_fix_down(float* array, int i, int arraySize);

    static void heap_create_dn(float* array, int arraySize);

public:
    float* sortArray(float* array, int arraySize);
};

class ShellSortFloat : public SortAlgFloat{
public:
    float* sortShell(float* array, int arraySize);

    float* sortHibbard(float* array, int arraySize);
};

class QuickSortFloat : public SortAlgFloat {
public:
    float* sort(float* array, int arraySize, int strategy);

private:
    int choosePivotIndex(int left, int right, int strategy);
    void quickSort(float* array, int left, int right, int strategy);
    int partition(float* array, int left, int right, int strategy);
};


#endif //PROJEKT1_SORTALGFLOAT_H
