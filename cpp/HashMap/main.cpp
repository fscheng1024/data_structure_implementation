#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

#include "HashMap.h"
#include "Finder.h"

using namespace std;


int main() {
    
    string str = "a green apple";
    Finder finder;
    cout << str << endl;

    char ch = finder.findFirstNonRepeatedChar(str);
    cout << "non-repeated char: " << ch << endl;

    char ch2 = finder.findFirstRepeatedChar(str);
    cout << "first-repeated char: " << ch2 << endl;

    int length = 0;
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 7, 7, 9, 9, 9, 9, 9, 9, 10};
    length = (sizeof(arr)/sizeof(*arr));
    cout << finder.mostFrequent(arr, length) << endl;

    int inputs[] = {1, 7, 5, 9, 2, 12, 3};
    length = (sizeof(inputs)/sizeof(*inputs));
    cout << finder.countPairsWIthDiffs(inputs, length, 2) << endl;

    int items[] = {2, 7, 11, 15};
    length = sizeof(items) / sizeof(items[0]);
    vector<int> dest(items, items + length);
    vector<int> result = finder.twoSum(dest, 17);
    cout << result[0] << " " << result[1] << endl;
    
    // HashMap h(5);
    // h.insertItem(1, "aa");
    // h.insertItem(2, "bb");
    // h.insertItem(6, "cc");
    // h.insertItem(8, "dd");
    // h.insertItem(20, "ee");
    // h.insertItem(199, "ff");
    // h.printHashMap();
    // cout << h.get(10) << endl;

    // HashTable ht(5);
    // ht.put(1, "aa");
    // ht.put(2, "bb");
    // ht.put(3, "cc");
    // ht.printHashMap();

    return 0;
}


