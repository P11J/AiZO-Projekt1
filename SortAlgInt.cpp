#include <chrono>
#include <cmath> //dla pow()
#include <iostream>
#include <cstdlib>

#include "SortAlgInt.h"


int* SortAlgInt::generateRandArray(int arraySize, int minimum, int maximum){ //funkcja generujaca tablice z losowymi danymi
    if(arraySize < 1 or minimum > maximum){
        throw invalid_argument("Podano bledny/e argument/y!!!\n");
    }

    int* array = new int[arraySize];

    for(int i = 0; i < arraySize; i++){
        array[i] = rand() % (maximum - minimum + 1) + minimum; //losowanie liczby z podanego zakresu
    }
    return array;
}

void SortAlgInt::printArray(int* array, int arraySize){ //wypisanie tablicy przed sortowaniem w konsoli
    for(int i = 0; i < arraySize; i++){
        cout << array[i] << " ";
    }
    cout<<endl<<endl;
}

bool SortAlgInt::isSorted(int* array, int arraySize){ //funckcja sprawdzajaca czy tablica zostala poprawnie posortowana
    for(int i = 0; i < arraySize - 1; i++){
        if(array[i] > array[i + 1]){
            return false;
        }
    }
    return true;
}

//ponizej znajduja sie metody klas dziedziczacych po klasie SortAlgInt dla każdego z algorytmow sortowania

int* InsertionSortInt::sortArray(int *array, int arraySize) {
    int *arrayToSort = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    this->startTime = chrono::steady_clock::now();
    int key;
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


void HeapSortInt::heap_fix_down(int *array, int i, int arraySize) {
    int j, temp;
    temp = array[i];
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

void HeapSortInt::heap_create_dn(int *array, int arraySize) {
    for (int i = (arraySize - 2) / 2; i >= 0; --i) // Rozpocznij od ostatniego węzła, który ma potomków
        heap_fix_down(array, i, arraySize);
}

int* HeapSortInt::sortArray(int *array, int arraySize) {
    int *arrayToSort = new int[arraySize];
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


int* ShellSortInt::sortShell(int *array, int arraySize) {
    int *arrayToSort = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    this->startTime = chrono::steady_clock::now();
    for (int gap = arraySize / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arraySize; i += 1) {
            int temp = arrayToSort[i];
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

int* ShellSortInt::sortHibbard(int *array, int arraySize) {
    int *arrayToSort = new int[arraySize];
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
            int temp = arrayToSort[i];
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


int* QuickSortInt::sort(int* array, int arraySize, int pivotIndex) {
    int* arraySorted = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arraySorted[i] = array[i];
    }

    this->startTime = std::chrono::steady_clock::now();
    if (pivotIndex < 0 || pivotIndex >= arraySize) pivotIndex = 0; // Zapewnienie, że indeks pivota jest w zakresie
    quickSort(arraySorted, 0, arraySize - 1);
    this->endTime = std::chrono::steady_clock::now();
    this->duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    return arraySorted;
}

void QuickSortInt::quickSort(int *array, int left, int right) {
    if (left < right) {
        int pivotIndex = left + (right - left) / 2; // Można tu zmodyfikować wybór pivota
        pivotIndex = partition(array, left, right, pivotIndex);
        quickSort(array, left, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, right);
    }
}

int QuickSortInt::partition(int *array, int left, int right, int pivotIndex) {
    int pivotValue = array[pivotIndex];
    swap(array[pivotIndex], array[right]); // Przesunięcie pivota na koniec
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (array[i] < pivotValue) {
            swap(array[i], array[storeIndex]);
            storeIndex++;
        }
    }
    swap(array[storeIndex], array[right]); // Przesunięcie pivota na jego docelową pozycję
    return storeIndex;
}

