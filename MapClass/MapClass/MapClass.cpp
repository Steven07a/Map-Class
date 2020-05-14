/*
 * Author: Steven Herrera
 * Project: Map Class
 * Purpose: to create a map class which is like an array but instead of using
 *  integers as your index you can use strings
 * Notes: 
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "Map.h"
#include "MultiMap.h"

using namespace std;

string randString();

int main()
{
    MMap<string, int> m;
    string input = "";
    (srand(time(NULL)));
    while (true) {
        cout << "[R]andom [I]nsert [C]lear si[Z]e [S]earch [E]rase [B]racket e[X]it: ";
        cin >> input;
        if (input == "r" || input == "R") {
            int num = (rand() % 100) + 1;
            string key = randString();
            cout << "-- Inserting " << key << "," << num << "\nMap : item: " << key << "," << num << endl;
            m.insert(key,num);
            cout << m;
            cout << "\n\n=========================\n";
        } else if (input == "i" || input == "I") {
            int num = 0;
            string key = "";
            cout << "? ";
            cin >> key >> num;
            m.insert(key, num);
            cout << "-- Inserting " << key << "," << num << "\nMap : item: " << key << "," << num << endl;
            cout << m;
            cout << "\n\n=========================\n";
        } else if (input == "s" || input == "S") {
            string key = "";
            cout << "? ";
            cin >> key;
            if (m.contains(key)) {
                cout << "item is found. map[" 
                    << key << "] = " << m[key] << endl; "|\n";
            } else {
                cout << "Item not found.\n";
            }
            cout << m;
            cout << "\n\n=========================\n";
        } else if (input == "c" || input == "C") {
            m.clear();
            cout << m;
            cout << "\n\n=========================\n";
        } else if (input == "x" || input == "X") {
            break;
        } else if (input == "z" || input == "Z") {
            cout << "Size of BTree: " << m.size() << endl;
            cout << m;
            cout << "\n\n=========================\n";
        } else if (input == "e" || input == "E") {
            string key = "";
            cout << "? ";
            cin >> key;
            m.erase(key);
            cout << "-- Erasing " << key << "\nMap : item: " << key << endl;
            cout << m;
            cout << "\n\n=========================\n";
        } else if (input == "b" || input == "B") {
            string key = "";
            cout << "? ";
            cin >> key;
            cout << "map[" << key << "] = " << m[key] << endl;
            cout << m;
            cout << "\n\n=========================\n";
        } else if (input == "t") {
            int num = 0;
            string key = "";
            cout << "? ";
            cin >> key >> num;
            m[key] += num;
            cout << "map[" << key << "] += " << m[key] << endl;
            cout << m;
            cout << "\n\n=========================\n";
        }
    }
    cout << "\n\n=========================\n";

    return 0;
}

string randString() {
    string alphaArr[] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
    string randString;
    for (int i = 0; i < 3; i++) {
        randString += alphaArr[rand() % 26];
    }
    return randString;
}
