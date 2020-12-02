/*
 * Author:		Étienne "vortydev" Ménard
 * Date:		02/12/2020
 * File:		day2.hpp
 * Description:	The methods and jank to solve day 1's puzzles.
 */

#include <iostream>
#include <string>
#include "vecteur.hpp"

using namespace std;

class day2 {
private:
    vecteur<string> _v;
    string _inputFilePath = "inputDay2.txt";

public:
    void init();    // initializes class' properties
    void solve();   // runs everything to solve Day 2's puzzles

    void puzzle1();
    void puzzle2();

    bool checkLetter(string& password, int pos1, int pos2, string& letter);
};

// initializes class' properties
void day2::init() {
    ifstream inputFile(_inputFilePath);
    string temp;

    while (!inputFile.eof()) {
        getline(inputFile, temp);
        _v.push_back(temp);
    }
}

// runs everything to solve Day 2's puzzles
void day2::solve() {
    init();
    puzzle1();
    puzzle2();
}

void day2::puzzle1() {
    cout << "Day 2, Puzzle 1." << endl;

    int count = 0;

    string s;
    string delimeterMin = "-";
    string delimeterMax = " ";
    string delimeterLetter = ":";

    string min;
    string max;
    string letter;
    string password;

    for (int i = 0; i < _v.size(); i++) {
        s = _v[i];
        
        // breaks down the input string into usable fragments
        min = s.substr(0, s.find(delimeterMin));
        s = s.substr(min.length() + delimeterMin.length());
        max = s.substr(0, s.find(delimeterMax));
        s = s.substr(max.length() + delimeterMax.length());
        letter = s.substr(0, s.find(delimeterLetter));
        s = s.substr(letter.length() + delimeterLetter.length());
        password = s.substr(1, s.length());

        int occurence = 0;
        for (int i = 0; i < password.length(); i++) {
            if (password[i] == letter[0])
                occurence++;
        }

        int minO = stoi(min);
        int maxO = stoi(max);
        if (occurence >= minO && occurence <= maxO)
            count++;
    }

    cout << "[!] " << count << " passwords are valid." << endl << endl;
}

void day2::puzzle2() {
    cout << "Day 2, Puzzle 2." << endl;

    int count = 0;

    string s;
    string delimeterMin = "-";
    string delimeterMax = " ";
    string delimeterLetter = ":";

    string pos1;
    string pos2;
    string letter;
    string password;

    for (int i = 0; i < _v.size(); i++) {
        s = _v[i];

        // breaks down the input string into usable fragments
        pos1 = s.substr(0, s.find(delimeterMin));
        s = s.substr(pos1.length() + delimeterMin.length());
        pos2 = s.substr(0, s.find(delimeterMax));
        s = s.substr(pos2.length() + delimeterMax.length());
        letter = s.substr(0, s.find(delimeterLetter));
        s = s.substr(letter.length() + delimeterLetter.length());
        password = s.substr(1, s.length());

        if (checkLetter(password, stoi(pos1), stoi(pos2), letter))
            count++;
    }

    cout << "[!] " << count << " passwords are valid." << endl << endl;
}

bool day2::checkLetter(string& password, int pos1, int pos2, string& letter) {
    bool posOne = false;
    bool posTwo = false;

    for (int i = 0; i < password.length(); i++) {
        if (i == pos1 - 1) {
            if (password[i] == letter[0])
                posOne = true;
        }
        else if (i == pos2 - 1) {
            if (password[i] == letter[0])
                posTwo = true;
        }
    }
    return (posOne != posTwo);
}