#ifndef RANDOMWORD_H_INCLUDED
#define RANDOMWORD_H_INCLUDED

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;

string RandomWord() {
    ifstream in("data.in");

    int n;
    in >> n;
    srand(time(NULL));
    int random = rand() % n + 1;
    string cuvant;

    for (int i = 0; i < random; ++i) {
        in >> cuvant;
    }

    in.close();
    return cuvant;
}

#endif // RANDOMWORD_H_INCLUDED

