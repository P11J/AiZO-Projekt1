#include <iostream>
#include <string>
#include <fstream>
#include <cstring> // Do użycia funkcji std::strerror
#include <algorithm> // Do uzycia funkcji swap
#include <chrono>
#include "SortAlgInt.h"

using namespace std;


//DO POKAZANIA ZMIENIC DURATIONCOUNTER NA 50



bool compare(int a, int b); //funkcja pozwalajaca na sortowanie tablicy malejaco

void analysis(); //naglowek dla funkcji przeprowadzajacej analize danego algorytmu

int menu1(); //naglowek dla menu pierwszego poziomu

void menu2(int type); //naglowek dla menu drugiego rzedu



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
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\insertionSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            InsertionSortInt* insertionSortInt = new InsertionSortInt();

            double durationSum = 0;
            const double durationCounter = 5.0;
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
        case 5:{
            int arrayToAnalyseSize;
            int* arrayToAnalyse;
            int* arrayToAnalyseSorted;
            string fileOutName = "E:\\1_studia\\AiZO\\Projekt1\\leftQuickSortAnaliza.txt";

            ofstream fileOut(fileOutName);


            QuickSortInt* quickSortInt = new QuickSortInt();

            double durationSum = 0;
            const double durationCounter = 5.0;
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
            const double durationCounter = 5.0;
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
            const double durationCounter = 5.0;
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
            const double durationCounter = 5.0;
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
                            if(insertionSortInt -> isSorted(arraySorted,arraySize))
                                cout << "Tablica zostala posortowana prawidlowo.\n";
                            break;
                        }
                        case 2:{
                            HeapSortInt* heapSortInt = new HeapSortInt();
                            arraySorted = heapSortInt ->sortArray(array, arraySize);
                            cout << heapSortInt -> duration << endl;
                            if(heapSortInt -> isSorted(arraySorted,arraySize))
                                cout << "Tablica zostala posortowana prawidlowo.\n";
                            break;
                        }
                        case 3:{
                            ShellSortInt* shellSortInt = new ShellSortInt();
                            arraySorted = shellSortInt ->sortShell(array, arraySize);
                            cout << shellSortInt -> duration << endl;
                            if(shellSortInt -> isSorted(arraySorted,arraySize))
                                cout << "Tablica zostala posortowana prawidlowo.\n";
                            break;
                        }
                        case 4:{
                            ShellSortInt* shellSortInt = new ShellSortInt();
                            arraySorted = shellSortInt ->sortHibbard(array, arraySize);
                            cout << shellSortInt -> duration << endl;
                            if(shellSortInt -> isSorted(arraySorted,arraySize))
                                cout << "Tablica zostala posortowana prawidlowo.\n";
                            break;
                        }

                        case 5:{
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt -> sort(array, arraySize, 0); //lewy pivot
                            cout << quickSortInt -> duration << endl;
                            if(quickSortInt -> isSorted(arraySorted,arraySize))
                                cout << "Tablica zostala posortowana prawidlowo.\n";
                            break;
                        }
                        case 6:{
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt -> sort(array, arraySize, arraySize - 1); //prawy pivot
                            cout << quickSortInt -> duration << endl;
                            if(quickSortInt -> isSorted(arraySorted,arraySize))
                                cout << "Tablica zostala posortowana prawidlowo.\n";
                            break;
                        }
                        case 7:{
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt -> sort(array, arraySize, arraySize / 2); //srodkowy pivot
                            cout << quickSortInt -> duration << endl;
                            if(quickSortInt -> isSorted(arraySorted,arraySize))
                                cout << "Tablica zostala posortowana prawidlowo.\n";
                            break;
                        }
                        case 8: {
                            srand(time(nullptr));
                            QuickSortInt* quickSortInt = new QuickSortInt();
                            arraySorted = quickSortInt->sort(array, arraySize, rand() % arraySize); //losowy pivot
                            cout << quickSortInt -> duration << endl;
                            if(quickSortInt -> isSorted(arraySorted,arraySize))
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