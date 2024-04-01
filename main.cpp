#include <iostream>
#include <string>
#include <fstream>
#include <cstring> // Do użycia funkcji std::strerror
#include <algorithm>
#include <cmath> //dla pow()
#include <chrono>


using namespace std;
bool compare(int a, int b); //funkcja pozwalajaca na sortowanie tablicy malejaco

class SortAlgInt{ //klasa bazowa dla klas potomnych dla poszczegolnych algorytmow sortowania

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
    int* sortArray(int* array, int arraySize){
        int* arrayToSort = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arrayToSort[i] = array[i];
        }
        this -> startTime = chrono::steady_clock::now();
        heap_create_dn(arrayToSort, arraySize);
        for(int i = arraySize - 1; i > 0; i--) {
            swap(arrayToSort[0],arrayToSort[i]); //zamiana
            heap_fix_down(arrayToSort,0,i); //naprawa
        }
        this -> endTime = chrono::steady_clock::now();
        this -> duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        return arrayToSort;
    }
};

class ShellSortInt : public SortAlgInt{
public:
    int* sortShell(int* array, int arraySize){
        int* arrayToSort = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arrayToSort[i] = array[i];
        }

        this -> startTime = chrono::steady_clock::now();
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
        this -> endTime = chrono::steady_clock::now();
        this -> duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        return arrayToSort;
    }

    int* sortHibbard(int* array, int arraySize) {
        int* arrayToSort = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arrayToSort[i] = array[i];
        }

        this -> startTime = chrono::steady_clock::now();
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
        this -> endTime = chrono::steady_clock::now();
        this -> duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        return arrayToSort;
    }
};

class QuickSortInt : public SortAlgInt{//poprawic (dla skrajnego lewego odnosimy sie do indexu -1)
private:
    void quickSort(int *array, int left, int right, int pivot_index)
    {
        if(right <= left) return;

        int i = left - 1, j = right + 1,
        pivot = array[pivot_index]; //wybieramy punkt odniesienia

        while(true)
        {
            //szukam elementu wiekszego lub rownego pivot stojacego
            //po prawej stronie wartosci pivot
            while(pivot > array[++i]);

            //szukam elementu mniejszego lub rownego pivot stojacego
            //po lewej stronie wartosci pivot
            while(pivot < array[--j]);

            //jesli liczniki sie nie minely to zamień elementy ze soba
            //stojace po niewlasciwej stronie elementu pivot
            if( i <= j)
                //funkcja swap zamienia wartosciami array[i] z array[j]
                swap(array[i], array[j]);
            else
                break;
        }

        if(j > left)
            quickSort(array, left, j, pivot_index);
        if(i < right)
            quickSort(array, i, right, pivot_index);
    }

public:
    int* sort(int* array, int arraySize, int pivot_index) {
        int* arraySorted = new int[arraySize];
        for(int i = 0; i < arraySize; i++){
            arraySorted[i] = array[i];
        }

        this -> startTime = chrono::steady_clock::now();
        quickSort(arraySorted,0,arraySize - 1,pivot_index);
        this -> endTime = chrono::steady_clock::now();
        this -> duration = chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

        return arraySorted;
    }

};


void analysis(); //naglowek dla funkcji przeprowadzajacej analize danego algorytmu


int menu1(){ //menu 1. poziomu
    cout << "Wybierz typ danych: \n";
    cout << "1 - int\n";
    cout << "2 - float\n";
    cout << "3 - double\n";
    int choice = 0;
    cin >> choice;
    return choice;
}

void menu2(int type){ //menu 2. poziomu, zależne od wybranego typu danych
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
                    int* tempArray = sortAlgInt->generateRandArray(tempArraySize,minimum,maximum);//generacja losowej tablicy
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
                    sort(tempArray, tempArray + tempArraySize);//sortowanie losowej tablicy
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
                    sort(tempArray, tempArray + tempArraySize, compare);//sortowanie malejaco losowej tablicy

                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
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
                    int* tempArray;
                    int tempArraySize = 0;
                    int value;

                    if(file.is_open()){
                        while(file >> value){
                            int* tempArray2 = new int[tempArraySize + 1];//po kazdej odczytanej wartosci z pliku tworzymy nowa tablice
                            for (int i = 0; i < tempArraySize; i++)//o 1 wieksza i dopisujemy nowa wartosc
                                tempArray2[i] = tempArray[i];

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

                        case 5:{
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt -> sort(array, arraySize, 0); //lewy pivot
                            cout << quickSortInt -> duration << endl;
                            break;
                        }
                        case 6:{
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt -> sort(array, arraySize, arraySize - 1); //prawy pivot
                            cout << quickSortInt -> duration << endl;
                            break;
                        }
                        case 7:{
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt -> sort(array, arraySize, arraySize / 2); //srodkowy pivot
                            cout << quickSortInt -> duration << endl;
                            break;
                        }
                        case 8: {
                            srand(time(nullptr));
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt->sort(array, arraySize, rand() % arraySize); //losowy pivot
                            cout << quickSortInt -> duration << endl;
                            break;
                        }
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
                    //zakres losowanych licz 1 - 30000
                    analysis();

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

void analysis(){
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
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\insertionSortRandAnaliza.txt";

            ofstream fileOut(fileOutName);


            InsertionSortInt* insertionSortInt = new InsertionSortInt();

            double durationSum = 0;
            const double durationCounter = 5.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            /*
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = heapSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = heapSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += heapSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
                durationToAnalyse = 0;
            }
            */

            //dla tablicy pos. rosnaco

            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = insertionSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = insertionSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += insertionSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. malejo
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = insertionSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = insertionSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += insertionSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 33%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = insertionSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = insertionSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += insertionSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 66%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = insertionSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = insertionSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += insertionSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }


            fileOut.close();
            cout << "Zakonczono analize\n";
            break;
        }
        case 2:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\HeapSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            HeapSortInt* heapSortInt = new HeapSortInt();

            double durationSum = 0;
            const double durationCounter = 5.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = heapSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = heapSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += heapSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. rosnaco
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = heapSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = heapSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += heapSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. malejo
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = heapSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = heapSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += heapSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 33%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = heapSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = heapSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += heapSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 66%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = heapSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = heapSortInt -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += heapSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }


            fileOut.close();
            cout << "Zakonczono analize\n";
            break;
        }
        case 3:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\ShellMethodSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            ShellSortInt* shellSortInt = new ShellSortInt();

            double durationSum = 0;
            const double durationCounter = 5.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = shellSortInt -> sortShell(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. rosnaco
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = shellSortInt -> sortShell(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. malejo
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = shellSortInt -> sortShell(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 33%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = shellSortInt -> sortShell(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 66%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = shellSortInt -> sortShell(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }


            fileOut.close();
            cout << "Zakonczono analize\n";
            break;
        }
        case 4:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\hibbardMethodSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            ShellSortInt* shellSortInt = new ShellSortInt();

            double durationSum = 0;
            const double durationCounter = 5.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. rosnaco
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. malejo
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 33%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }

            //dla tablicy pos. w 66%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 80000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
            }


            fileOut.close();
            cout << "Zakonczono analize\n";
            break;
        }
        /* ZROBIC QUICKSORTA!!!!
        case 5:{
            int arrayToAnalyseSize = 10000;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\leftQuickSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            ShellSortInt* shellSortInt = new ShellSortInt();

            double durationSum = 0;
            const double durationCounter = 5.0;
            double durationToAnalyse = 0;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
                durationToAnalyse = 0;
            }

            //dla tablicy pos. rosnaco
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
                durationToAnalyse = 0;
            }

            //dla tablicy pos. malejo
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
                durationToAnalyse = 0;
            }

            //dla tablicy pos. w 33%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
                durationToAnalyse = 0;
            }

            //dla tablicy pos. w 66%
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = shellSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = shellSortInt -> sortHibbard(arrayToAnalyse, arrayToAnalyseSize);
                    durationSum += shellSortInt -> duration.count();
                }
                cout << "Aktualny rozmiar tablicy to: " << arrayToAnalyseSize << endl;
                durationToAnalyse = durationSum / durationCounter;

                if(fileOut.is_open()){
                    fileOut << arrayToAnalyseSize << ";";
                    fileOut << durationToAnalyse << endl;
                }else{
                    cerr << "Błąd: Nie można otworzyć pliku do zapisu." << endl;
                }
                delete[] arrayToAnalyse;
                delete[] arrayToAnalyseSorted;

                durationSum = 0;
                durationToAnalyse = 0;
            }


            fileOut.close();
            cout << "Zakonczono analize\n";
            break;
        }
        */
        default:
            cout << "Blednie podano nr algorytmu!!!\n";
            break;
    }
    cout << "Zakonczono analize\n";
}