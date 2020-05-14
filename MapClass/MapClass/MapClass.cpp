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
void multiMapInteractive();
void test_multi_map_insert_random(int howMany);
void test_multi_map_random_insert_and_delete(int howMany);
void shuffle(int a[], unsigned int  size);
template <typename T>
bool contains(T a[], int size, T item);

int main()
{
    //multiMapInteractive();
    //test_multi_map_insert_random(10000);
    test_multi_map_random_insert_and_delete(100);
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

void multiMapInteractive() {
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
            m.insert(key, num);
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

}

void test_multi_map_insert_random(int howMany) {
    cout << "*********************************************************" << endl;
    cout << " INSERT RANDOM TEST: " << howMany << " ITEMS" << endl;
    cout << "*********************************************************" << endl;
    int* arr = new int[howMany];
    int found = 0;
    for (int i = 0; i < howMany; i++) {
        arr[i] = i + 1;
    }
    shuffle(arr, howMany);

    MMap<int,int> mmap;

    for (int i = 0; i < howMany; i++) {
        mmap.insert(arr[i], ((rand() % 100)+1));
    }

    for (int i = 0; i < howMany; i++) {
        if (mmap.contains(arr[i])) {
            found++;
        }
    }

    delete[]arr;
    arr = NULL;

    if (found == howMany) {
        cout << " INSERTION TEST PASSED " << "FOUND " << found << " ITEMS" << endl << endl;
    } else {
        cout << " INSERTION TEST FAILED " << endl << endl;
    }
}


void test_multi_map_random_insert_and_delete(int howMany) {
    cout << "*********************************************************" << endl;
    cout << " INSERT AND DELETEING RANDOM TEST: " << howMany << " ITEMS" << endl;
    cout << "*********************************************************" << endl;
    string* arr = new string[howMany];
    int notFound = 0;
    string temp = "";
    for (int i = 0; i < howMany; i++) {
        temp = randString();
        while (contains(arr, i + 1, temp)) {
            temp = randString();
        }
        arr[i] = temp;
        cout << arr[i] << "\n";
    }
    
    //shuffle(arr, howMany);

    MMap<string, int> mmap;

    for (int i = 0; i < howMany; i++) {
        mmap.insert(arr[i], ((rand() % 100) + 1));
    }
    cout << mmap << "\n\n";
    for (int i = 0; i < howMany; i++) {
        mmap.erase(arr[i]);
        if (!mmap.contains(arr[i])) {
            notFound++;
        } else {
            cout << arr[i] << "\n\n";
            cout << mmap << "\n\n";
            mmap.contains(arr[i]);
        }
    }
    delete []arr;
    arr = NULL;

    if (notFound == howMany) {
        cout << " INSERTION AND DELETING TEST PASSED " << "DELETED " << notFound << " ITEMS" << endl << endl;
    } else {
        cout << " INSERTION AND DELETING TEST FAILED " << endl << endl;
    }
}


void shuffle(int a[], unsigned int  size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % i;
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

template <typename T>
bool contains(T a[], int size, T item) {
    for (int i = 0; i < size; i++) {
        if (a[i] == item) {
            return true;
        } else {
            return false;
        }
    }
}
