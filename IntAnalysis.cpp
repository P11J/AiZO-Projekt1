#include "IntAnalysis.h"
#include "SortAlgInt.h"

#include <iostream>
#include <fstream>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

void intAnalysis(){
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
            int* arrayToAnalyse = nullptr;
            int* arrayToAnalyseSorted = nullptr;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\insertionSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            InsertionSortInt* insertionSortInt = new InsertionSortInt();

            double durationSum = 0;
            const double durationCounter = 50.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 10000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = insertionSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
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
            const double durationCounter = 50.0;
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
            const double durationCounter = 50.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 320000 * sizeMultiplier;
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
                arrayToAnalyseSize = 320000 * sizeMultiplier;
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
                arrayToAnalyseSize = 320000 * sizeMultiplier;
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
                arrayToAnalyseSize = 320000 * sizeMultiplier;
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
                arrayToAnalyseSize = 320000 * sizeMultiplier;
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
            const double durationCounter = 50.0;
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
        case 5:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\leftQuickSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            QuickSortInt* quickSortInt = new QuickSortInt();

            double durationSum = 0;
            const double durationCounter = 50.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,0);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,0);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,0);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,0);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,0);
                    durationSum += quickSortInt -> duration.count();
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
        case 6:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\rightQuickSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            QuickSortInt* quickSortInt = new QuickSortInt();

            double durationSum = 0;
            const double durationCounter = 50.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize - 1);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize - 1);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize - 1);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize - 1);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize - 1);
                    durationSum += quickSortInt -> duration.count();
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
        case 7:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\middleQuickSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            QuickSortInt* quickSortInt = new QuickSortInt();

            double durationSum = 0;
            const double durationCounter = 50.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize/2);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize/2);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize/2);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize/2);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,arrayToAnalyseSize/2);
                    durationSum += quickSortInt -> duration.count();
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
        case 8:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\randQuickSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            QuickSortInt* quickSortInt = new QuickSortInt();

            double durationSum = 0;
            const double durationCounter = 50.0;
            double durationToAnalyse;


            //dla calkowicie losowej tablicy
            for(int sizeMultiplier = 1; sizeMultiplier <= 64; sizeMultiplier *= 2){
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,rand() % arrayToAnalyseSize);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,rand() % arrayToAnalyseSize);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse,arrayToAnalyse + arrayToAnalyseSize, compare);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,rand() % arrayToAnalyseSize);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + arrayToAnalyseSize / 3);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,rand() % arrayToAnalyseSize);
                    durationSum += quickSortInt -> duration.count();
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
                arrayToAnalyseSize = 40000 * sizeMultiplier;
                for(int i = 0; i < durationCounter; i++){
                    arrayToAnalyse = quickSortInt -> generateRandArray(arrayToAnalyseSize, minimumAnalyse, maximumAnalyse);
                    sort(arrayToAnalyse, arrayToAnalyse + (arrayToAnalyseSize / 3) * 2);
                    arrayToAnalyseSorted = quickSortInt -> sort(arrayToAnalyse, arrayToAnalyseSize,rand() % arrayToAnalyseSize);
                    durationSum += quickSortInt -> duration.count();
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

        default:
            cout << "Blednie podano nr algorytmu!!!\n";
            break;
    }
    cout << "Zakonczono analize\n";
}