#ifndef PROJEKT1_SORTALGDOUBLE_H
#define PROJEKT1_SORTALGDOUBLE_H


#include <chrono>

using namespace std;

class SortAlgDouble { //klasa rodzic dla algorytmow sortowania
public:
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    chrono::milliseconds duration;

    static double* generateRandArray(int arraySize, double minimum, double maximum);
    static void printArray(double* array, int arraySize);
    bool isSorted(double* array, int arraySize);
};

//ponizej znajduja sie klasy dziedziczace po SortAlgInt rozniace sie algorytmem sortowania i ew. funkcjami pomocniczymi

class InsertionSortDouble : public SortAlgDouble{
public:
    double* sortArray(double* array, int arraySize);
};

class HeapSortDouble : public SortAlgDouble{
private:
    static void heap_fix_down(double* array, int i, int arraySize);

    static void heap_create_dn(double* array, int arraySize);

public:
    double* sortArray(double* array, int arraySize);
};

class ShellSortDouble : public SortAlgDouble{
public:
    double* sortShell(double* array, int arraySize);

    double* sortHibbard(double* array, int arraySize);
};

class QuickSortDouble : public SortAlgDouble {
public:
    double* sort(double* array, int arraySize, int strategy);

private:
    int choosePivotIndex(int left, int right, int strategy);
    void quickSort(double *array, int left, int right, int strategy);
    int partition(double *array, int left, int right, int strategy);
};

#endif //PROJEKT1_SORTALGDOUBLE_H
