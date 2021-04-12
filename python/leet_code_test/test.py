class NumMatrix:
    
    def __init__(self, matrix):
        self.matrix = matrix
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int):
        total = 0
        for i in range(row1, row2+1):
            for j in range(col1, col2+1):
                total += self.matrix[i][j]
        
        return total



["NumMatrix","sumRegion","sumRegion","sumRegion"]
matrix = [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]],
          [2, 1, 4, 3],
          [1, 1, 2, 2],
          [1, 2, 2, 4]]
print(len(matrix[0][0][0]), len(matrix[1]))

matrix = [[3,0,1,4,2],
            [5,6,3,2,1],
            [1,2,0,1,5],
            [4,1,0,1,7],
            [1,0,3,0,5]]

print(len(matrix), len(matrix[0]))
# Your NumMatrix object will be instantiated and called as such:
obj = NumMatrix(matrix)
param_1 = obj.sumRegion(2, 1, 4, 3)
print(param_1)