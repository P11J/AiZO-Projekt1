#include "SortAlgDouble.h"

#include <chrono>
#include <cmath> //dla pow()
#include <iostream>
#include <cstdlib>



double* SortAlgDouble::generateRandArray(int arraySize, double minimum, double maximum){ //funkcja generujaca tablice z losowymi danymi
    if(arraySize < 1 or minimum > maximum){
        throw invalid_argument("Podano bledny/e argument/y!!!\n");
    }

    double* array = new double[arraySize];

    for(int i = 0; i < arraySize; i++){
        //static_cast<double>(rand()) / (RAND_MAX + 1.0) zwraca wartosc <0,1),
        //ktora nastepnie skalujemy do zakresy <minimum, maximum)
        array[i] = minimum + static_cast<double>(rand()) / (RAND_MAX + 1.0) * (maximum - minimum); //losowanie liczby z podanego zakresu
    }
    return array;
}

void SortAlgDouble::printArray(double* array, int arraySize){ //wypisanie tablicy przed sortowaniem w konsoli
    for(int i = 0; i < arraySize; i++){
        cout << array[i] << " ";
    }
    cout<<endl<<endl;
}

bool SortAlgDouble::isSorted(double* array, int arraySize){ //funckcja sprawdzajaca czy tablica zostala poprawnie posortowana
    for(int i = 0; i < arraySize - 1; i++){
        if(array[i] > array[i + 1]){
            return false;
        }
    }
    return true;
}

//ponizej znajduja sie metody klas, ktore dziedzicza po klasie SortAlgInt, dla każdego z algorytmow sortowania

double* InsertionSortDouble::sortArray(double* array, int arraySize) {
    double* arrayToSort = new double[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    this->startTime = chrono::steady_clock::now();
    double key;
    for (int i = 1; i < arraySize; i++) {
        key = arrayToSort[i];
        int j = i;
        while (j > 0 and arrayToSort[j - 1] > key) {
            arrayToSort[j] = arrayToSort[j - 1];
            j--;
        }
        arrayToSort[j] = key;
    }
    this->endTime = chrono::steady_clock::now();
    this->duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    return arrayToSort;
}


void HeapSortDouble::heap_fix_down(double* array, int i, int arraySize) {
    int j;
    double temp = array[i];
    j = 2 * i + 1; // j to lewy potomek i

    while (j < arraySize) {
        if (j + 1 < arraySize && array[j] < array[j + 1]) // Sprawdza, czy prawy potomek istnieje i jest większy od lewego
            j = j + 1; // Przechodzi do prawego potomka, jeśli spełnia warunki

        if (temp >= array[j]) // Jeśli żaden z potomków nie jest większy, przerwij
            break;

        array[(j - 1) / 2] = array[j]; // Przenosi większego potomka do węzła rodzica
        j = 2 * j + 1; // Przechodzi do lewego potomka obecnego potomka
    }

    array[(j - 1) / 2] = temp; // Wstawia wartość temp (początkowa wartość array[i]) na odpowiednie miejsce w kopcu
}

void HeapSortDouble::heap_create_dn(double* array, int arraySize) {
    for (int i = (arraySize - 2) / 2; i >= 0; --i) // Rozpocznij od ostatniego węzła, który ma potomków
        heap_fix_down(array, i, arraySize);
}

double* HeapSortDouble::sortArray(double* array, int arraySize) {
    double* arrayToSort = new double[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }
    this->startTime = chrono::steady_clock::now();
    heap_create_dn(arrayToSort, arraySize);
    for (int i = arraySize - 1; i > 0; i--) {
        swap(arrayToSort[0], arrayToSort[i]); //zamiana
        heap_fix_down(arrayToSort, 0, i); //naprawa
    }
    this->endTime = chrono::steady_clock::now();
    this->duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    return arrayToSort;
}


double* ShellSortDouble::sortShell(double* array, int arraySize) {
    double* arrayToSort = new double[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    this->startTime = chrono::steady_clock::now();
    for (int gap = arraySize / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arraySize; i += 1) {
            double temp = arrayToSort[i];
            int j;
            for (j = i; j >= gap and arrayToSort[j - gap] > temp; j -= gap) {
                arrayToSort[j] = arrayToSort[j - gap];
            }
            arrayToSort[j] = temp;
        }
    }
    this->endTime = chrono::steady_clock::now();
    this->duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    return arrayToSort;
}

double* ShellSortDouble::sortHibbard(double* array, int arraySize) {
    double* arrayToSort = new double [arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    this->startTime = chrono::steady_clock::now();
    // Obliczanie maksymalnego k, dla którego 2^k - 1 < arraySize
    int k = 1;
    while ((pow(2, k) - 1) < arraySize) {
        ++k;
    }
    --k; // Znalezienie największego odstępu mniejszego niż arraySize

    // Pętla po odstępach Hibbarda 2^k - 1, zaczynając od największego
    while (k > 0) {
        int gap = pow(2, k) - 1; // Odstęp dla danej iteracji

        // Sortowanie przez wstawianie dla danego odstępu
        for (int i = gap; i < arraySize; i++) {
            double temp = arrayToSort[i];
            int j;
            for (j = i; j >= gap and arrayToSort[j - gap] > temp; j -= gap) {
                arrayToSort[j] = arrayToSort[j - gap];
            }
            arrayToSort[j] = temp;
        }

        --k; // Zmniejszenie k na końcu pętli while
    }
    this->endTime = chrono::steady_clock::now();
    this->duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    return arrayToSort;
}


int QuickSortDouble::choosePivotIndex(int left, int right, int strategy) {
    switch(strategy) {
        case 0: // skrajny lewy
            return left;
        case 1: // skrajny prawy
            return right;
        case 2: // srodkowy
            return left + (right - left) / 2;
        case 3: // losowy
            return left + rand() % (right - left + 1);
        default:
            return left + (right - left) / 2; // domyslnie srodek
    }
}

//
int QuickSortDouble::partition(double *array, int left, int right, int strategy) {
    int pivotIndex = choosePivotIndex(left, right, strategy);
    double pivotValue = array[pivotIndex];
    swap(array[pivotIndex], array[right]); // zamiana pivota na koniec
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (array[i] < pivotValue) {
            swap(array[i], array[storeIndex]);
            storeIndex++;
        }
    }
    swap(array[storeIndex], array[right]); // zamiana pivota na jego miejsce
    return storeIndex;
}

// quicksort rekurencyjnie
void QuickSortDouble::quickSort(double *array, int left, int right, int strategy) {
    if (left < right) {
        int pivotIndex = partition(array, left, right, strategy);
        quickSort(array, left, pivotIndex - 1, strategy); // sortowanie lewej czesci
        quickSort(array, pivotIndex + 1, right, strategy); // sortowanie prawej czesci
    }
}

// funkcja sortowania quicksort z wyborem strategii wyboru pivota
double* QuickSortDouble::sort(double* array, int arraySize, int strategy) {
    double * arraySorted = new double[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arraySorted[i] = array[i];
    }

    startTime = chrono::steady_clock::now();
    quickSort(arraySorted, 0, arraySize - 1, strategy);
    endTime = chrono::steady_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    return arraySorted;
}

