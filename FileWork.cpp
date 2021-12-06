#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void stringTwoLet(char stringFromFile[]) {

    int indexOne, indexTwo, lenghtString = strlen(stringFromFile) - 1;
    int* CountTwo = new int[lenghtString];

    for (indexOne = 0; indexOne < lenghtString; indexOne++) CountTwo[indexOne] = 0;

    for (indexOne = 0; indexOne < lenghtString; indexOne++) {

        for (indexTwo = 0; indexTwo < indexOne; indexTwo++) {

            if (stringFromFile[indexOne] == stringFromFile[indexTwo] && stringFromFile[indexOne + 1] == stringFromFile[indexTwo + 1]) {

                CountTwo[indexTwo]++;
                break;
            }
        }
        if (indexTwo == indexOne)

            CountTwo[indexOne] = 1;
    }
    for (indexOne = 0; indexOne < lenghtString; indexOne++)

        if (CountTwo[indexOne])

            cout << stringFromFile[indexOne] << stringFromFile[indexOne + 1] << " - " << CountTwo[indexOne] << endl;
}

void stringOneLet(char stringFromFile[]) {

    int indexOne, indexTwo, lenghtString = strlen(stringFromFile) - 1;
    int* CountOne = new int[lenghtString];

    for (indexOne = 0; indexOne < lenghtString; indexOne++) CountOne[indexOne] = 0;

    for (indexOne = 0; indexOne < lenghtString; indexOne++) {

        for (indexTwo = 0; indexTwo < indexOne; indexTwo++) {

            if (stringFromFile[indexOne] == stringFromFile[indexTwo]) {

                CountOne[indexTwo]++;
                break;
            }
        }
        if (indexTwo == indexOne)

            CountOne[indexOne] = 1;
    }
    for (indexOne = 0; indexOne < lenghtString; indexOne++)

        if (CountOne[indexOne])

            cout << stringFromFile[indexOne] << " - " << CountOne[indexOne] << endl;
}

int main() {

    system("chcp 1251");

    char stringFromFile[200];

    ifstream input("in.txt");

    input >> stringFromFile;

    cout << "Количество сочетаний в строке:" << endl;
    stringTwoLet(stringFromFile);
    cout << "Количество букв в строке:" << endl;
    stringOneLet(stringFromFile);

}