#include "MenuFunctions.h"
#include "SortAlgInt.h"
#include "SortAlgDouble.h"
#include "SortAlgFloat.h"
#include "IntAnalysis.h"
#include "DoubleAnalysis.h"
#include "FloatAnalysis.h"

#include <iostream>
#include <fstream>
#include <cstring> // Do użycia funkcji std::strerror
#include <chrono>

using namespace std;


void intMenu2(int choice){ //menu 2 poziomu dla typu integer
    int arraySize = 0;
    int* array = nullptr;
    int* arraySorted = nullptr;
    do{
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
                if(array != nullptr)
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
                if(array != nullptr)
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

                if(array != nullptr)
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
                if(array != nullptr)
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
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 7: {
                cout << "Podaj sciezke pliku txt znajdujacego sie w katalogu projektu z danymi tablicy:\n";
                string fileName;
                cin >> fileName;
                ifstream file(fileName);
                int tempArraySize = 0;


                if(file.is_open()){
                    file >> tempArraySize; //w pierwszym wierszu podana jest liczba danych do wczytania
                    int* tempArray = new int[tempArraySize];

                    for(int i = 0; i < tempArraySize; i++){ //czytamy |tempArraySize| danych z pliku
                        file >> tempArray[i];
                    }

                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    file.close();
                }else{
                    cout << "Wystapil blad przy odczycie pliku\n";
                    cerr << strerror(errno); //wyswietla konkretny blad odczytu pliku
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
                        if(insertionSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 2:{
                        HeapSortInt* heapSortInt = new HeapSortInt();
                        arraySorted = heapSortInt ->sortArray(array, arraySize);
                        cout << heapSortInt -> duration << endl;
                        if(heapSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 3:{
                        ShellSortInt* shellSortInt = new ShellSortInt();
                        arraySorted = shellSortInt ->sortShell(array, arraySize);
                        cout << shellSortInt -> duration << endl;
                        if(shellSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 4:{
                        ShellSortInt* shellSortInt = new ShellSortInt();
                        arraySorted = shellSortInt ->sortHibbard(array, arraySize);
                        cout << shellSortInt -> duration << endl;
                        if(shellSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
                        break;
                    }

                    case 5:{
                        QuickSortInt* quickSortInt = new QuickSortInt();
                        arraySorted = quickSortInt -> sort(array, arraySize, 0); //lewy pivot
                        cout << quickSortInt -> duration << endl;
                        if(quickSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 6:{
                        QuickSortInt* quickSortInt = new QuickSortInt();
                        arraySorted = quickSortInt -> sort(array, arraySize, 1); //prawy pivot
                        cout << quickSortInt -> duration << endl;
                        if(quickSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 7:{
                        QuickSortInt* quickSortInt = new QuickSortInt();
                        arraySorted = quickSortInt -> sort(array, arraySize, 2); //srodkowy pivot
                        cout << quickSortInt -> duration << endl;
                        if(quickSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 8: {
                        srand(time(nullptr));
                        QuickSortInt* quickSortInt = new QuickSortInt();
                        arraySorted = quickSortInt->sort(array, arraySize, 3); //losowy pivot
                        cout << quickSortInt -> duration << endl;
                        if(quickSortInt -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        else
                            cout << "Tablica nie zostala posortowana prawidlowo.\n";
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
                //zakres losowanych liczb 1 - 30000
                intAnalysis();

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

}

void floatMenu2(int choice){ //menu 2. poziomu dla typu float
    int arraySize = 0;
    float* array = nullptr;
    float* arraySorted = nullptr;
    do{
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Tablica przed posortowaniem\n";
                SortAlgFloat::printArray(array,arraySize);
                break;
            }
            case 2: {
                float minimum = 0;
                float maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgFloat* sortAlgFloat = new SortAlgFloat();
                float* tempArray = sortAlgFloat->generateRandArray(tempArraySize,minimum,maximum);//generacja losowej tablicy
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 3:{
                float minimum = 0;
                float maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgFloat* sortAlgFloat = new SortAlgFloat();
                float* tempArray = sortAlgFloat->generateRandArray(tempArraySize,minimum,maximum);
                sort(tempArray, tempArray + tempArraySize);//sortowanie losowej tablicy
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 4:{
                float minimum = 0;
                float maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;

                SortAlgFloat* sortAlgFloat = new SortAlgFloat();
                float* tempArray = sortAlgFloat->generateRandArray(tempArraySize,minimum,maximum);
                sort(tempArray, tempArray + tempArraySize, compare);//sortowanie malejaco losowej tablicy

                if(array != nullptr)
                    delete[]array;

                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 5:{
                float minimum = 0;
                float maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgFloat* sortAlgFloat = new SortAlgFloat();
                float* tempArray = sortAlgFloat->generateRandArray(tempArraySize,minimum,maximum);
                int sortingSize = tempArraySize / 3; //sortujemy do 1/3 elementow
                sort(tempArray, tempArray + sortingSize);
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;

            }
            case 6:{
                float minimum = 0;
                float maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgFloat* sortAlgFloat = new SortAlgFloat();
                float* tempArray = sortAlgFloat->generateRandArray(tempArraySize,minimum,maximum);
                int sortingSize = (tempArraySize / 3) * 2; //sortujemy do 2/3 elementow
                sort(tempArray, tempArray + sortingSize);
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 7: {
                cout << "Podaj sciezke pliku txt znajdujacego sie w katalogu projektu z danymi tablicy:\n";
                string fileName;
                cin >> fileName;
                ifstream file(fileName);
                int tempArraySize = 0;


                if(file.is_open()){
                    file >> tempArraySize; //w pierwszym wierszu podana jest liczba danych do wczytania
                    float* tempArray = new float[tempArraySize];

                    for(int i = 0; i < tempArraySize; i++){ //czytamy |tempArraySize| danych z pliku
                        file >> tempArray[i];
                    }

                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    file.close();
                }else{
                    cout << "Wystapil blad przy odczycie pliku\n";
                    cerr << strerror(errno); //wyswietla konkretny blad odczytu pliku
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
                        InsertionSortFloat* insertionSortFloat = new InsertionSortFloat();
                        arraySorted = insertionSortFloat -> sortArray(array, arraySize);
                        cout << insertionSortFloat -> duration << endl;
                        if(insertionSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 2:{
                        HeapSortFloat* heapSortFloat = new HeapSortFloat();
                        arraySorted = heapSortFloat ->sortArray(array, arraySize);
                        cout << heapSortFloat -> duration << endl;
                        if(heapSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 3:{
                        ShellSortFloat* shellSortFloat = new ShellSortFloat();
                        arraySorted = shellSortFloat ->sortShell(array, arraySize);
                        cout << shellSortFloat -> duration << endl;
                        if(shellSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 4:{
                        ShellSortFloat* shellSortFloat = new ShellSortFloat();
                        arraySorted = shellSortFloat ->sortHibbard(array, arraySize);
                        cout << shellSortFloat -> duration << endl;
                        if(shellSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }

                    case 5:{
                        QuickSortFloat* quickSortFloat = new QuickSortFloat();
                        arraySorted = quickSortFloat -> sort(array, arraySize, 0); //lewy pivot
                        cout << quickSortFloat -> duration << endl;
                        if(quickSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 6:{
                        QuickSortFloat* quickSortFloat = new QuickSortFloat();
                        arraySorted = quickSortFloat -> sort(array, arraySize, 1); //prawy pivot
                        cout << quickSortFloat -> duration << endl;
                        if(quickSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 7:{
                        QuickSortFloat* quickSortFloat = new QuickSortFloat();
                        arraySorted = quickSortFloat -> sort(array, arraySize, 2); //srodkowy pivot
                        cout << quickSortFloat-> duration << endl;
                        if(quickSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 8: {
                        srand(time(nullptr));
                        QuickSortFloat* quickSortFloat = new QuickSortFloat();
                        arraySorted = quickSortFloat->sort(array, arraySize, 3); //losowy pivot
                        cout << quickSortFloat -> duration << endl;
                        if(quickSortFloat -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
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
                SortAlgFloat::printArray(arraySorted,arraySize);
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
                floatAnalysis();
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

}

void doubleMenu2(int choice){ //menu 2. poziomu dla typu double
    int arraySize = 0;
    double* array = nullptr;
    double* arraySorted = nullptr;
    do{
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Tablica przed posortowaniem\n";
                SortAlgDouble::printArray(array,arraySize);
                break;
            }
            case 2: {
                double minimum = 0;
                double maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgDouble* sortAlgDouble = new SortAlgDouble();
                double* tempArray = sortAlgDouble->generateRandArray(tempArraySize,minimum,maximum);//generacja losowej tablicy
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 3:{
                double minimum = 0;
                double maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgDouble* sortAlgDouble = new SortAlgDouble();
                double* tempArray = sortAlgDouble->generateRandArray(tempArraySize,minimum,maximum);
                sort(tempArray, tempArray + tempArraySize);//sortowanie losowej tablicy
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 4:{
                double minimum = 0;
                double maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;

                SortAlgDouble* sortAlgDouble = new SortAlgDouble();
                double* tempArray = sortAlgDouble->generateRandArray(tempArraySize,minimum,maximum);
                sort(tempArray, tempArray + tempArraySize, compare);//sortowanie malejaco losowej tablicy

                if(array != nullptr)
                    delete[]array;

                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 5:{
                double minimum = 0;
                double maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgDouble* sortAlgDouble = new SortAlgDouble();
                double* tempArray = sortAlgDouble->generateRandArray(tempArraySize,minimum,maximum);
                int sortingSize = tempArraySize / 3; //sortujemy do 1/3 elementow
                sort(tempArray, tempArray + sortingSize);
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;

            }
            case 6:{
                double minimum = 0;
                double maximum = 0;
                cout << "Podaj rozmiar generowanej tablicy:\n";
                int tempArraySize;
                cin >> tempArraySize;
                cout << "Jej minimum:\n";
                cin >> minimum;
                cout << "Oraz maximum:\n";
                cin >> maximum;
                SortAlgDouble* sortAlgDouble = new SortAlgDouble();
                double* tempArray = sortAlgDouble->generateRandArray(tempArraySize,minimum,maximum);
                int sortingSize = (tempArraySize / 3) * 2; //sortujemy do 2/3 elementow
                sort(tempArray, tempArray + sortingSize);
                if(array != nullptr)
                    delete[]array;
                array = tempArray;
                arraySize = tempArraySize;
                break;
            }
            case 7: {
                cout << "Podaj sciezke pliku txt znajdujacego sie w katalogu projektu z danymi tablicy:\n";
                string fileName;
                cin >> fileName;
                ifstream file(fileName);
                int tempArraySize = 0;


                if(file.is_open()){
                    file >> tempArraySize; //w pierwszym wierszu podana jest liczba danych do wczytania
                    double* tempArray = new double[tempArraySize];

                    for(int i = 0; i < tempArraySize; i++){ //czytamy |tempArraySize| danych z pliku
                        file >> tempArray[i];
                    }

                    delete[]array;
                    array = tempArray;
                    arraySize = tempArraySize;
                    file.close();
                }else{
                    cout << "Wystapil blad przy odczycie pliku\n";
                    cerr << strerror(errno); //wyswietla konkretny blad odczytu pliku
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
                        InsertionSortDouble* insertionSortDouble = new InsertionSortDouble();
                        arraySorted = insertionSortDouble -> sortArray(array, arraySize);
                        cout << insertionSortDouble -> duration << endl;
                        if(insertionSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 2:{
                        HeapSortDouble* heapSortDouble = new HeapSortDouble();
                        arraySorted = heapSortDouble ->sortArray(array, arraySize);
                        cout << heapSortDouble -> duration << endl;
                        if(heapSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 3:{
                        ShellSortDouble* shellSortDouble = new ShellSortDouble();
                        arraySorted = shellSortDouble ->sortShell(array, arraySize);
                        cout << shellSortDouble -> duration << endl;
                        if(shellSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 4:{
                        ShellSortDouble* shellSortDouble = new ShellSortDouble();
                        arraySorted = shellSortDouble ->sortHibbard(array, arraySize);
                        cout << shellSortDouble -> duration << endl;
                        if(shellSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }

                    case 5:{
                        QuickSortDouble* quickSortDouble = new QuickSortDouble();
                        arraySorted = quickSortDouble -> sort(array, arraySize, 0); //lewy pivot
                        cout << quickSortDouble -> duration << endl;
                        if(quickSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 6:{
                        QuickSortDouble* quickSortDouble = new QuickSortDouble();
                        arraySorted = quickSortDouble -> sort(array, arraySize, arraySize - 1); //prawy pivot
                        cout << quickSortDouble -> duration << endl;
                        if(quickSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 7:{
                        QuickSortDouble* quickSortDouble = new QuickSortDouble();
                        arraySorted = quickSortDouble -> sort(array, arraySize, arraySize / 2); //srodkowy pivot
                        cout << quickSortDouble-> duration << endl;
                        if(quickSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
                        break;
                    }
                    case 8: {
                        srand(time(nullptr));
                        QuickSortDouble* quickSortDouble = new QuickSortDouble();
                        arraySorted = quickSortDouble->sort(array, arraySize, rand() % arraySize); //losowy pivot
                        cout << quickSortDouble -> duration << endl;
                        if(quickSortDouble -> isSorted(arraySorted,arraySize))
                            cout << "Tablica zostala posortowana prawidlowo.\n";
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
                SortAlgDouble::printArray(arraySorted,arraySize);
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
                //zakres losowanych liczb 1 - 30000
                doubleAnalysis();

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

}


int menu1(){//menu 1. poziomu
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
        intMenu2(choice);
    }else if(type == 2){
        floatMenu2(choice);
    }else if(type == 3){
        doubleMenu2(choice);
    }
}




