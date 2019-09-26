class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        def rotate_layer(r1, c1, r2, c2, matrix):            
            for i in range(0, c2 - c1):
                tmp = matrix[r1][c1 + i]
                matrix[r1][c1 + i] = matrix[r2 - i][c1]      
                matrix[r2 - i][c1] = matrix[r2][c2 - i]
                matrix[r2][c2 - i] = matrix[r1 + i][c2]
                matrix[r1 + i][c2] = tmp                
        if not matrix:
            return        
        r1, r2 = 0, len(matrix) - 1
        c1, c2 = 0, len(matrix[0]) - 1
        while r1 <= r2 and c1 <= c2:
            rotate_layer(r1, c1, r2, c2, matrix)            
            r1 += 1
            r2 -= 1
            c1 += 1
            c2 -= 1        
                
                
                