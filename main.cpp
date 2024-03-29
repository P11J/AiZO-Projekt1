#include <iostream>
#include <string>
#include <fstream>
#include <cstring> // Do użycia funkcji std::strerror
#include <algorithm>
#include <cmath> //dla pow()
#include <profileapi.h>
#include <chrono>


using namespace std;
bool compare(int a, int b);

class SortAlgInt{

public:
    chrono::steady_clock::time_point startTime;
    chrono::steady_clock::time_point endTime;
    chrono::milliseconds duration;


    static int* generateRandArray(int arraySize, int minimum, int maximum){
        if(arraySize < 1 or minimum > maximum){
            throw invalid_argument("Podano bledny/e argument/y!!!\n");
        }

        srand(time(nullptr));

        int* array = new int[arraySize];

        for(int i = 0; i < arraySize; i++){
            array[i] = rand() % (maximum - minimum + 1) + minimum;
        }
        return array;
    }

    static void printArray(int* array, int arraySize){
        for(int i = 0; i < arraySize; i++){
            cout << array[i] << " ";
        }
        cout<<endl<<endl;
    }
};

class InsertionSortInt : public SortAlgInt{
public:

    int* sortArray(int* array, int arraySize){
        int* arrayToSort = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arrayToSort[i] = array[i];
        }

        this -> startTime = chrono::steady_clock::now();
        int key;
        for(int i = 1; i < arraySize; i++){
            key=arrayToSort[i];
            int j=i;
            while(j > 0 and arrayToSort[j-1] > key){
                arrayToSort[j] = arrayToSort[j-1];
                j--;
            }
            arrayToSort[j] = key;
        }
        this -> endTime = chrono::steady_clock::now();
        this -> duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        return arrayToSort;
    }
};

class HeapSortInt : public SortAlgInt{
private:
    static void heap_fix_down(int* array, int i, int arraySize) {
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

    static void heap_create_dn(int* array, int arraySize) {
        for(int i = (arraySize - 2) / 2; i >= 0; --i) // Rozpocznij od ostatniego węzła, który ma potomków
            heap_fix_down(array, i, arraySize);
    }

public:
    static int* sortArray(int* array, int arraySize){
        int* arrayToSort = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arrayToSort[i] = array[i];
        }

        heap_create_dn(arrayToSort, arraySize);
        for(int i = arraySize - 1; i > 0; i--) {
            swap(arrayToSort[0],arrayToSort[i]); //zamiana
            heap_fix_down(arrayToSort,0,i); //naprawa
        }
        return arrayToSort;
    }
};

class ShellSortInt : public SortAlgInt{
public:
    static int* sortShell(int* array, int arraySize){
        int* arrayToSort = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arrayToSort[i] = array[i];
        }

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
        return arrayToSort;
    }

    static int* sortHibbard(int* array, int arraySize) {
        int* arrayToSort = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arrayToSort[i] = array[i];
        }

        // Obliczanie maksymalnego k, dla którego 2^k - 1 < arraySize
        int k = 1;
        while (pow(2, k) - 1 < arraySize) {
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
        return arrayToSort;
    }
};
/*
class QuickSortInt : public SortAlgInt{
private:
    static int partition(int* array, int left, int right, int pivot_index) {
        int pivot = array[pivot_index]; // Wybieramy element o podanym indeksie jako pivot
        int i = left; // Indeks mniejszego elementu

        for (int j = left + 1; j <= right; j++) {
            // Jeśli aktualny element jest mniejszy lub równy pivotowi
            if (array[j] <= pivot) {
                i++; // Zwiększamy indeks mniejszego elementu
                swap(array[i], array[j]);
            }
        }
        swap(array[i + 1], array[pivot_index]);
        return i;
    }

    static void quickSort(int* array, int left, int right, int pivot_index) {
        if (left < right) {
            if(pivot_index != left){ // Jeżeli pivot nie jest na skraju, wykonaj normalną procedurę partition
                // podział to indeks podziału, array[pivot] jest już na właściwym miejscu
                int partition_index = partition(array, left, right, pivot_index);

                // Osobno sortujemy elementy przed i po podziale
                quickSort(array, left, partition_index - 1, pivot_index);
                quickSort(array, partition_index, right, pivot_index);
            } else { // Jeżeli pivot jest na skraju, zabezpiecz go
                // podział to indeks podziału, array[pivot] jest już na właściwym miejscu
                int partition_index = partition(array, left, right, pivot_index);

                // Osobno sortujemy elementy przed i po podziale
                quickSort(array, left, partition_index, pivot_index);
                quickSort(array, partition_index + 1, right, pivot_index);
            }
        }
    }

public:


    static int* sort(int* array, int arraySize, int pivot_index) {
        int* arraySorted = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arraySorted[i] = array[i];
        }
        quickSort(arraySorted,0,arraySize - 1,pivot_index);

        return arraySorted;
    }

};
*/
int menu1(){
    cout << "Wybierz typ danych: \n";
    cout << "1 - int\n";
    cout << "2 - float\n";
    cout << "3 - double\n";
    int choice = 0;
    cin >> choice;
    return choice;
}

void menu2(int type){
    cout << "\nWybierz akcje:\n";
    cout << "1 - Wyswietl wczytana/wygenerowana tablice\n";
    cout << "2 - Wygeneruj losowa tablice o zadanym rozmiarze\n";
    cout << "3 - Wygeneruj tablice posortowana rosnaco\n";
    cout << "4 - Wygeneruj tablice posortowana malejaco\n";
    cout << "5 - Wygeneruj tablice posortowana w 33%\n";
    cout << "6 - Wygeneruj tablice posortowana w 66%\n";
    cout << "7 - Wczytaj dane tablicy z pliku txt\n";
    cout << "8 - Uruchom wybrany algorytm sortowania\n";
    cout << "9 - Wyswietl posortowana kopie tablicy\n";
    cout << "10 - Pokaz ponownie menu\n";
    cout << "11 - Uruchom analize wybranego algorytmu\n";
    cout << "12 - Wyjdz z programu\n\n";
    int choice = 0;

    if(type == 1) {
        int arraySize = 0;
        int* array;
        int* arrayToSort;
        int* arraySorted;
        do {
            cin >> choice;
            switch (choice) {
                case 1: {
                    cout << "Tablica przed posortowaniem\n";
                    SortAlgInt::printArray(array,arraySize);
                    break;
                }
                case 2: {
                    int minimum = 0;
                    int maximum = 0;
                    cout << "Podaj rozmiar generowanej tablicy:\n";
                    int tempArraySize;
                    cin >> tempArraySize;
                    cout << "Jej minimum:\n";
                    cin >> minimum;
                    cout << "Oraz maximum:\n";
                    cin >> maximum;
                    SortAlgInt* sortAlgInt = new SortAlgInt();
                    int* tempArray = sortAlgInt->generateRandArray(tempArraySize,minimum,maximum);
                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    break;
                }
                case 3:{
                    int minimum = 0;
                    int maximum = 0;
                    cout << "Podaj rozmiar generowanej tablicy:\n";
                    int tempArraySize;
                    cin >> tempArraySize;
                    cout << "Jej minimum:\n";
                    cin >> minimum;
                    cout << "Oraz maximum:\n";
                    cin >> maximum;
                    SortAlgInt* sortAlgInt = new SortAlgInt();
                    int* tempArray = sortAlgInt->generateRandArray(tempArraySize,minimum,maximum);
                    sort(tempArray, tempArray + tempArraySize);
                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    break;
                }
                case 4:{
                    int minimum = 0;
                    int maximum = 0;
                    cout << "Podaj rozmiar generowanej tablicy:\n";
                    int tempArraySize;
                    cin >> tempArraySize;
                    cout << "Jej minimum:\n";
                    cin >> minimum;
                    cout << "Oraz maximum:\n";
                    cin >> maximum;

                    SortAlgInt* sortAlgInt = new SortAlgInt();
                    int* tempArray = sortAlgInt->generateRandArray(tempArraySize,minimum,maximum);


                    sort(tempArray, tempArray + tempArraySize, compare);

                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    break;
                    break;
                }
                case 5:{
                    int minimum = 0;
                    int maximum = 0;
                    cout << "Podaj rozmiar generowanej tablicy:\n";
                    int tempArraySize;
                    cin >> tempArraySize;
                    cout << "Jej minimum:\n";
                    cin >> minimum;
                    cout << "Oraz maximum:\n";
                    cin >> maximum;
                    SortAlgInt* sortAlgInt = new SortAlgInt();
                    int* tempArray = sortAlgInt->generateRandArray(tempArraySize,minimum,maximum);
                    int sortingSize = tempArraySize / 3; //sortujemy do 1/3 elementow
                    sort(tempArray, tempArray + sortingSize);
                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    break;

                }
                case 6:{
                    int minimum = 0;
                    int maximum = 0;
                    cout << "Podaj rozmiar generowanej tablicy:\n";
                    int tempArraySize;
                    cin >> tempArraySize;
                    cout << "Jej minimum:\n";
                    cin >> minimum;
                    cout << "Oraz maximum:\n";
                    cin >> maximum;
                    SortAlgInt* sortAlgInt = new SortAlgInt();
                    int* tempArray = sortAlgInt->generateRandArray(tempArraySize,minimum,maximum);
                    int sortingSize = (tempArraySize / 3) * 2; //sortujemy do 2/3 elementow
                    sort(tempArray, tempArray + sortingSize);
                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    break;
                }
                case 7: {
                    cout << "Podaj nazwe pliku txt znajdujacego sie w katalogu projektu z danymi tablicy:\n";
                    string fileName;
                    cin >> fileName;
                    ifstream file(fileName);
                    int* tempArray = nullptr;
                    int tempArraySize = 0;
                    int value;

                    if(file.is_open()){
                        while(file >> value){
                            int* tempArray2 = new int[tempArraySize + 1];
                            for(int i = 0; i < tempArraySize; i++){
                                tempArray2[i] = tempArray[i];
                            }
                            tempArray2[tempArraySize] = value;
                            delete[] tempArray;
                            tempArray = tempArray2;
                            tempArraySize++;
                        }
                        delete[]array;
                        array = tempArray;
                        arraySize = tempArraySize;
                        file.close();
                    }else{
                        cout << "Wystapil blad przy odczycie pliku\n";
                        cerr << strerror(errno); //wyswietla blad odczytu pliku
                    }

                    break;
                }
                case 8:{
                    cout << "Wybierz algorytm sortowania:\n";
                    cout << "1 - Insertion Sort\n";
                    cout << "2 - Heap Sort\n";
                    cout << "3 - Shell Sort metoda Shella\n";
                    cout << "4 - Shell Sort metoda Hibbarda\n";
                    cout << "5 - Quick Sort ze skrajnym lewym pivotem\n";
                    cout << "6 - Quick Sort ze skrajnym prawym pivotem\n";
                    cout << "7 - Quick Sort ze srodkowym pivotem\n";
                    cout << "8 - Quick Sort z losowym pivotem\n";
                    int algChoice;
                    cin >> algChoice;

                    switch (algChoice) {
                        case 1:{
                            InsertionSortInt* insertionSortInt = new InsertionSortInt();
                            arraySorted = insertionSortInt -> sortArray(array, arraySize);
                            cout << insertionSortInt -> duration << endl;
                            break;
                        }
                        case 2:{
                            HeapSortInt* heapSortInt = new HeapSortInt();
                            arraySorted = heapSortInt ->sortArray(array, arraySize);
                            cout << heapSortInt -> duration << endl;
                            break;
                        }
                        case 3:{
                            ShellSortInt* shellSortInt = new ShellSortInt();
                            arraySorted = shellSortInt ->sortShell(array, arraySize);
                            cout << shellSortInt -> duration << endl;
                            break;
                        }
                        case 4:{
                            ShellSortInt* shellSortInt = new ShellSortInt();
                            arraySorted = shellSortInt ->sortHibbard(array, arraySize);
                            cout << shellSortInt -> duration << endl;
                            break;
                        }
                        /*
                        case 5:{
                            QuickSort* quickSort = new QuickSort();
                            arraySorted = quickSort -> sort(array,arraySize,0); //lewy pivot
                            break;
                        }
                        case 6:{
                            QuickSort* quickSort = new QuickSort();
                            arraySorted = quickSort -> sort(array,arraySize,arraySize - 1); //prawy pivot
                            break;
                        }
                        case 7:{
                            QuickSort* quickSort = new QuickSort();
                            arraySorted = quickSort -> sort(array,arraySize,arraySize / 2); //srodkowy pivot
                            break;
                        }
                        case 8:{
                            srand(time(nullptr));
                            QuickSort* quickSort = new QuickSort();
                            arraySorted = quickSort -> sort(array,arraySize,rand() % arraySize); //losowy pivot
                            break;
                        }
                         */
                        default:{
                            cout << "Zle wybrano algorytm sortowania!!!\n";
                        }
                    }
                    break;
                }
                case 9:{
                    cout << "Tablica po posortowaniu:\n";
                    SortAlgInt::printArray(arraySorted,arraySize);
                    break;
                }
                case 10:{
                    cout << "\nWybierz akcje:\n";
                    cout << "1 - Wyswietl wczytana/wygenerowana tablice\n";
                    cout << "2 - Wygeneruj losowa tablice o zadanym rozmiarze\n";
                    cout << "3 - Wygeneruj tablice posortowana rosnaco\n";
                    cout << "4 - Wygeneruj tablice posortowana malejaco\n";
                    cout << "5 - Wygeneruj tablice posortowana w 33%\n";
                    cout << "6 - Wygeneruj tablice posortowana w 66%\n";
                    cout << "7 - Wczytaj dane tablicy z pliku txt\n";
                    cout << "8 - Uruchom wybrany algorytm sortowania\n";
                    cout << "9 - Wyswietl posortowana kopie tablicy\n";
                    cout << "10 - Pokaz ponownie menu\n";
                    cout << "11 - Uruchom analize wybranego algorytmu\n";
                    cout << "12 - Wyjdz z programu\n\n";
                    break;
                }
                case 11:{
                    cout << "Wybierz algorytm sortowania:\n";
                    cout << "1 - Insertion Sort\n";
                    cout << "2 - Heap Sort\n";
                    cout << "3 - Shell Sort metoda Shella\n";
                    cout << "4 - Shell Sort metoda Hibbarda\n";
                    cout << "5 - Quick Sort ze skrajnym lewym pivotem\n";
                    cout << "6 - Quick Sort ze skrajnym prawym pivotem\n";
                    cout << "7 - Quick Sort ze srodkowym pivotem\n";
                    cout << "8 - Quick Sort z losowym pivotem\n";
                    int choiceAnalyse = 0;
                    int minimumAnalyse = 0;
                    int maximumAnalyse = 0;
                    cin >> choiceAnalyse;
                    cout << "Wybierz minimum dla generowanych tablic: \n";
                    cin >> minimumAnalyse;
                    cout << "Oraz maximum: \n";
                    cin >> maximumAnalyse;

                    switch(choiceAnalyse){
                        case 1:{
                            int arrayToAnalyseSize;
                            int* arrayToAnalyse;
                            int* arrayToAnalyseSorted;

                            ofstream file("insertionSortAnaliza.txt");

                            cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize <<endl;
                            InsertionSortInt* insertionSortInt = new InsertionSortInt();
                            arrayToAnalyseSorted = insertionSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                            arrayToAnalyseSorted = insertionSortInt ->sortArray(arrayToAnalyse, arrayToAnalyseSize);

                            if(file.is_open()){
                                file << arrayToAnalyseSize << ";";
                                file << insertionSortInt -> duration.count() << endl;
                            }else{
                                cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                            }
                            break;
                        }
                        default:
                            cout << "Blednie podano nr algorytmu!!!\n";
                            break;
                    }

                    break;
                }
                case 12: {
                    cout << "Zakonczono program.\n";
                    return;
                }
                default: {
                    cout << "Podano bledny argument!!!\n";
                }
            }
        } while (choice != 12);

    }else if(type == 2){
        //
    }else if(type == 3){
        //
    }
}



int main() {
    menu2(menu1());

    return 0;
}

bool compare(int a, int b){
    return a > b;
}

