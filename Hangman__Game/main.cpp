#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "RandomWord.h" // Include header-ul pentru funcția RandomWord

using namespace std;

// Funcție care gestionează jocul Hangman
void play();

// Desenul Hangman pentru fiecare stadiu al jocului
string hangman_art[7] = {
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |\n"
    "==========",
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |\n"
    "=========="
};

// Funcția principală care inițializează jocul
int main() {
    srand(time(0)); // Inițializează generatorul de numere random
    cout << "Bine ai venit la Hangman Game!\n"<<endl;
    play(); // Pornește jocul

    return 0;
}

// Funcție care gestionează jocul Hangman
void play() {
    string cuvant = RandomWord(); // Obține un cuvânt random din fișierul data.in
    string guess_word(cuvant.length(), '*'); // Inițializează cuvântul ghicit cu asterisk-uri

    int try_nr = 0;//nr la a cata incercare suntem, in functie de asta , se afiseaza desenul hnagman-ului
    char letter;

    while (true) //bucla infinita , se opreste la unul dintre break-uri, atunci cand juxcatorul castiga sau pierde
    {
        cout << hangman_art[try_nr] << "\n";//afisarea desenului in functie de la a cata incercare esti
        cout << guess_word << "\n";
        cout << "Introdu o litera\n";
        cin >> letter;
    bool found=false;
    for(int i=0;i<cuvant.length();i++)
    {
        if(cuvant[i]==letter)
        {
            found=true;
            break;
        }
    }
    if(found)
    {
        for (int i = 0; i < cuvant.length(); ++i)
        {
         if (cuvant[i] == letter)
          guess_word[i] = letter;

        }
         if (cuvant == guess_word)
          {cout << hangman_art[try_nr] << "\n";
           cout << guess_word << "\n";
           cout << "Ai castigat! Cuvantul era: " <<cuvant<< "\n";
           break;
          }
    }
    else
        {
            try_nr++;
        }
        if (try_nr     >= 6) {
            cout << hangman_art[try_nr] << "\n";
            cout << guess_word << "\n";
            cout << "Ai pierdut! Cuvantul era: " << cuvant << "\n";
            break;
        }
    }
}
