#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
        int length = triangle.size();
        int** result = new int*[length];
        for (int i=0; i<length; i++) 
            result[i] = new int[i+1];
        
        result[0][0] = triangle[0][0];

        for(int i=1; i<length; i++) { 
            result[i][0] = result[i-1][0] + triangle[i][0];
            result[i][-1] = result[i-1][-1] + triangle[i][-1];
            for(int j=1; j<i; j++) {
                result[i][j] = min(
                    result[i-1][j-1], result[i-1][j]) + triangle[i][j];
                cout << result[i][j] << endl;
            }
            
        }
        cout << result[3] << endl;
        return *result[3];
        
    }
};

int main() {
    Solution so;
    int M=4;
    std::vector<std::vector<int> > matrix(M, std::vector<int>(1, 0));

    for (int i=0; i<4; i++) {
        for (int j=0; j<1; j++)
        cout << matrix[i][j] << " " << endl;
    }
    // vector< vector<int> > &vect {
    //     {2},
    //     {3, 4},
    //     {6, 5, 7},
    //     {4, 8, 1, 3}
    // };

    
    
}