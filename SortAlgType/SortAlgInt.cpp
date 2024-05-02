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

    this->startTime = chrono::high_resolution_clock::now();
    int key;
    for (int i = 1; i < arraySize; i++) { // Rozpocznij pętlę od drugiego elementu tablicy
        key = arrayToSort[i]; // Przypisz aktualny element do zmiennej pomocniczej 'key'
        int j = i; // Zainicjuj zmienną pomocniczą 'j', która będzie wskazywać na obecnie analizowaną pozycję
        while (j > 0 and arrayToSort[j - 1] > key) { // Dopóki nie jesteśmy na początku tablicy i poprzedni element jest większy niż 'key'
            arrayToSort[j] = arrayToSort[j - 1]; // Przesuń element większy niż 'key' o jedną pozycję w prawo
            j--; // Dekrementuj 'j', by sprawdzić kolejne elementy w lewo
        }
        arrayToSort[j] = key; // Umieść element 'key' na odpowiedniej pozycji w posortowanej części tablicy
    }

    this->endTime = chrono::high_resolution_clock::now();
    this->duration = chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
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
    for (int i = (arraySize - 2) / 2; i >= 0; --i) // Rozpocznij od ostatniego węzła, który ma potomków i przesuwaj się wstecz
        heap_fix_down(array, i, arraySize); // Napraw kopiec, zaczynając od i-tego węzła, by utrzymać własność kopca
}


int* HeapSortInt::sortArray(int *array, int arraySize) {
    int *arrayToSort = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }
    this->startTime = chrono::high_resolution_clock::now();
    heap_create_dn(arrayToSort, arraySize); // Buduje kopiec z nieposortowanej tablicy
    for (int i = arraySize - 1; i > 0; i--) { // Przetwarzaj elementy od końca tablicy do drugiego elementu
        swap(arrayToSort[0], arrayToSort[i]); // Zamień korzeń kopca (największy element) z ostatnim elementem nieposortowanego segmentu
        heap_fix_down(arrayToSort, 0, i); // Przywróć własność kopca, ignorując elementy posortowane
    }

    this->endTime = chrono::high_resolution_clock::now();
    this->duration = chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    return arrayToSort;
}


int* ShellSortInt::sortShell(int *array, int arraySize) {
    int *arrayToSort = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    this->startTime = chrono::high_resolution_clock::now();

    // Zewnętrzna pętla określa odstep, rozpoczynając od połowy wielkości tablicy.
    // Z każdą iteracją odstep jest dzielony przez 2 aż do osiągnięcia wartości 1 (wtedy jest to zwykły insertion sort).
    for (int gap = arraySize/2; gap > 0; gap /= 2)
    {
        // Pętla przechodzi przez elementy tablicy zaczynając od indeksu 'gap'.
        // Umożliwia to porównywanie elementów oddalonych o 'gap'.
        for (int i = gap; i < arraySize; i += 1)
        {
            // Zapisanie obecnego elementu w zmiennej 'temp' oraz przygotowanie indeksu 'j' do przesuwania elementów.
            int temp = arrayToSort[i];
            int j;

            // Przesunięcie elementów większych od 'temp' o 'gap' w prawo,
            // aż do momentu gdy trafimy na mniejszy element lub początek tablicy.
            for (j = i; j >= gap && arrayToSort[j - gap] > temp; j -= gap)
                arrayToSort[j] = arrayToSort[j - gap];

            // Wstawienie elementu 'temp' na odpowiednie miejsce.
            arrayToSort[j] = temp;
        }
    }


    this->endTime = chrono::high_resolution_clock::now();
    this->duration = chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    return arrayToSort;
}

int* ShellSortInt::sortHibbard(int *array, int arraySize) {
    int *arrayToSort = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arrayToSort[i] = array[i];
    }

    this->startTime = chrono::high_resolution_clock::now();
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
    this->endTime = chrono::high_resolution_clock::now();
    this->duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    return arrayToSort;
}

int QuickSortInt::choosePivotIndex(int left, int right, int strategy) {
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
int QuickSortInt::partition(int *array, int left, int right, int strategy) {
    int pivotIndex = choosePivotIndex(left, right, strategy); // Wybiera indeks pivota na podstawie strategii
    int pivotValue = array[pivotIndex]; // Pobiera wartość pivota
    swap(array[pivotIndex], array[right]); // Przenosi pivota na koniec przedziału
    int storeIndex = left; // Ustawia początkowy indeks dla elementów mniejszych od pivota
    for (int i = left; i < right; i++) { // Iteruje przez wszystkie elementy z wyjątkiem pivota
        if (array[i] < pivotValue) { // Jeśli element jest mniejszy od pivota, zamienia go z elementem na storeIndex
            swap(array[i], array[storeIndex]);
            storeIndex++; // Przesuwa storeIndex na kolejną pozycję
        }
    }
    swap(array[storeIndex], array[right]); // Umieszcza pivota w środkowej pozycji między elementami mniejszymi i większymi od niego
    return storeIndex; // Zwraca indeks, na którym znajduje się pivot, dzieląc tablicę na dwie części
}


// quicksort rekurencyjnie
void QuickSortInt::quickSort(int *array, int left, int right, int strategy) {
    if (left < right) {
        int pivotIndex = partition(array, left, right, strategy); // dzieli tablice na dwie podtablice wzgledem pivota
        quickSort(array, left, pivotIndex - 1, strategy); // sortowanie lewej czesci
        quickSort(array, pivotIndex + 1, right, strategy); // sortowanie prawej czesci
    }
}

// funkcja sortowania quicksort z wyborem strategii wyboru pivota
int* QuickSortInt::sort(int* array, int arraySize, int strategy) {
    int* arraySorted = new int[arraySize];
    for (int i = 0; i < arraySize; i++) {
        arraySorted[i] = array[i];
    }

    this->startTime = chrono::high_resolution_clock::now();
    quickSort(arraySorted, 0, arraySize - 1, strategy);
    this->endTime = chrono::high_resolution_clock::now();
    this->duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    return arraySorted;
}

