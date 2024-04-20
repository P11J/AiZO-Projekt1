#include "DoubleAnalysis.h"
#include "SortAlgDouble.h"
#include <iostream>
#include <fstream>

using namespace std;

bool compare(double a, double b){
    return a > b;
}

void doubleAnalysis(){
    cout << "Dla typu double przeprowadzic mozna analize tylko dla Insertion Sort (zgodnie z zalozeniami projektowymi)\n";

    double minimumAnalyse = 0;
    double maximumAnalyse = 0;
    cout << "Wybierz minimum dla generowanych tablic: \n";
    cin >> minimumAnalyse;
    cout << "Oraz maximum: \n";
    cin >> maximumAnalyse;

    int arrayToAnalyseSize;
    double* arrayToAnalyse = nullptr;
    double * arrayToAnalyseSorted = nullptr;
    string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\insertionSortDoubleAnaliza.txt";

    ofstream fileOut(fileOutName);


    InsertionSortDouble* insertionSortDouble = new InsertionSortDouble();

    double durationSum = 0;
    const double durationCounter = 5.0;
    double durationToAnalyse;


    //dla calkowicie losowej tablicy
    for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
        arrayToAnalyseSize = 10000 * sizeMultiplier;
        for(int i = 0; i < durationCounter; i++){
            arrayToAnalyse = insertionSortDouble -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            arrayToAnalyseSorted = insertionSortDouble -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortDouble -> duration.count();
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
        arrayToAnalyseSize = 10000 * sizeMultiplier;
        for(int i = 0; i < durationCounter; i++){
            arrayToAnalyse = insertionSortDouble -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
            arrayToAnalyseSorted = insertionSortDouble -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortDouble -> duration.count();
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
            arrayToAnalyse = insertionSortDouble -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
            arrayToAnalyseSorted = insertionSortDouble -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortDouble -> duration.count();
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
            arrayToAnalyse = insertionSortDouble -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
            arrayToAnalyseSorted = insertionSortDouble -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortDouble -> duration.count();
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
            arrayToAnalyse = insertionSortDouble -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
            arrayToAnalyseSorted = insertionSortDouble -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortDouble -> duration.count();
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
}
