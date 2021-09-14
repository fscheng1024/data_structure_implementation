#include <iostream>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <vector>

using namespace std;

class Finder {

public:
    Finder();
    ~Finder();

    char findFirstNonRepeatedChar(string str);
    char findFirstRepeatedChar(string str);
    int mostFrequent(int arr[], int n);
    int countPairsWIthDiffs(int arr[], int n, int diff);
    vector<int> twoSum(vector<int>& nums, int target);
};


