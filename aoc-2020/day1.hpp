/*
 * Author:		Étienne "vortydev" Ménard
 * Date:		01/12/2020
 * File:		day1.hpp
 * Description:	The methods and jank to solve day 1's puzzles.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "vecteur.hpp"

using namespace std;

class day1 {
private:
    vecteur<int> _v;                            // vector that will contain all the integers from an input file
    string _inputFilePath = "inputDay1.txt";    // input file from which we'll read the values

public:
    void init();            // does all the necessary initialization
    void solvePuzzle1();    // bruteforces all the possible combinations with no optimisation nor limitations
    void solvePuzzle2();    // bruteforces all the possible combinations with no optimisation nor limitations (again)

    void solve();       // runs all the methods to solve day 1
};

void day1::init() {
    ifstream inputFile(_inputFilePath);
    int temp;

    while (!inputFile.eof()) {
        inputFile >> temp;
        _v.push_back(temp);
    }
}

// bruteforces all the possible combinations with no optimisation nor limitations
void day1::solvePuzzle1() {
    cout << "Day 1, Puzzle 1." << endl;

    for (int i = 0; i < _v.size(); i++) {
        for (int j = 0; j < _v.size(); j++) {
            if (_v[i] + _v[j] == 2020) {
                cout << "[!] Solution found: " << _v[i] * _v[j] << endl << endl;
                return;
            }
        }
    }

    cout << "[X] No solution was found." << endl << endl;
}

// bruteforces all the possible combinations with no optimisation nor limitations (again)
void day1::solvePuzzle2() {
    cout << "Day 1, Puzzle 2." << endl;

    for (int i = 0; i < _v.size(); i++) {
        for (int j = 0; j < _v.size(); j++) {
            for (int k = 0; k < _v.size(); k++) {
                if (_v[i] + _v[j] + _v[k] == 2020) {
                    cout << "[!] Solution found: " << _v[i] * _v[j] * _v[k] << endl << endl;
                    return;
                }
            }
        }
    }

    cout << "[X] No solution was found." << endl << endl;
}

void day1::solve() {
    init();
    solvePuzzle1();
    solvePuzzle2();
}