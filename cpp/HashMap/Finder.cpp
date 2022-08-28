#include "Finder.h"

Finder::Finder() {}

Finder::~Finder() {}


char Finder::findFirstNonRepeatedChar(const string str) {
    map<char, int> result;

    for (int i = 0; i < str.length(); ++i) {
        const char ch = str[i];
        int count = result[ch];
        result[ch] = count > 0 ? count + 1 : 1;
    }

    map<char, int>::iterator iter;
    for (iter = result.begin(); iter != result.end(); ++iter) {
        if (iter->second == 1)
            return iter->first;
    }

    return (char)0;
}


char Finder::findFirstRepeatedChar(const string str) {
    std::set<char> result;

    for (int i = 0; i < str.length(); i++) {
        const char ch = str[i];
        const bool is_in = result.find(ch) != result.end();
        if (is_in) 
            return ch;
        result.insert(ch);
    }
    return (char)0;
}


int Finder::mostFrequent(int arr[], int n) {
    map<int, int> result;
    
    for (int i = 0; i < n; ++i) {
        const int item = arr[i];
        int count = result[item];
        result[item] = count > 0 ? count + 1 : 1;
    }

    map<int, int>::iterator iter;
    int max_val = 0;
    int max_key = 0;
    for (iter = result.begin(); iter != result.end(); ++iter) {
        if (iter->second > max_val) {
            max_val = iter->second; 
            max_key = iter->first;
        }
    }

    return max_key;
}


int Finder::countPairsWIthDiffs(int arr[], int n, int diff) {
    std::set<char> result;
    for (int i=0; i<n; i++) {
        result.insert(arr[i]);
    }
    int count = 0;
    for (int i=0; i<n; i++) {
        if (result.count(arr[i] + diff))
            count += 1;
        if (result.count(arr[i] - diff))
            count += 1;
        result.erase(arr[i]);
    }

    return count;
}


vector<int> Finder::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (result.count(nums[i])) 
            return {result[target - nums[i]], i};
        result[target - nums[i]] = i;
    }
    return {};
}