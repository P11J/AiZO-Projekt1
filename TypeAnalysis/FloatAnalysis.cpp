#include "FloatAnalysis.h"
#include "../SortAlgType/SortAlgFloat.h"
#include <iostream>
#include <fstream>

using namespace std;

bool compare(float a, float b){
    return a > b;
}

void floatAnalysis(){
    cout << "Dla typu float przeprowadzic mozna analize tylko dla Insertion Sort (zgodnie z zalozeniami projektowymi)\n";

    float minimumAnalyse = 0;
    float maximumAnalyse = 0;
    cout << "Wybierz minimum dla generowanych tablic: \n";
    cin >> minimumAnalyse;
    cout << "Oraz maximum: \n";
    cin >> maximumAnalyse;

    int arrayToAnalyseSize;
    float* arrayToAnalyse = nullptr;
    float * arrayToAnalyseSorted = nullptr;
    string fileOutName = "E:\\1_Studia\\AiZO\\Projekt1\\Microseconds\\insertionSortFloatAnaliza.txt";

    ofstream fileOut(fileOutName);


    InsertionSortFloat* insertionSortFloat = new InsertionSortFloat();

    float durationSum = 0;
    const float durationCounter = 3.0;
    float durationToAnalyse;


    //dla calkowicie losowej tablicy
    for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
        arrayToAnalyseSize = 10000 * sizeMultiplier;
        for(int i = 0; i < durationCounter; i++){
            arrayToAnalyse = insertionSortFloat -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            arrayToAnalyseSorted = insertionSortFloat -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortFloat -> duration.count();
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
            arrayToAnalyse = insertionSortFloat -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
            arrayToAnalyseSorted = insertionSortFloat -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortFloat -> duration.count();
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
            arrayToAnalyse = insertionSortFloat -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
            arrayToAnalyseSorted = insertionSortFloat -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortFloat -> duration.count();
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
            arrayToAnalyse = insertionSortFloat -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
            arrayToAnalyseSorted = insertionSortFloat -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortFloat -> duration.count();
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
            arrayToAnalyse = insertionSortFloat -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
            sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
            arrayToAnalyseSorted = insertionSortFloat -> sortArray(arrayToAnalyse, arrayToAnalyseSize);
            durationSum += insertionSortFloat -> duration.count();
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
