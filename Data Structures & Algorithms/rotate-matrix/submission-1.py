class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        temp = 0
        n = len(matrix)
        numIterLayer = n // 2

        for layer in range(numIterLayer):
            print('new layer')
            for i in range(n - (2 *layer) - 1):
                print(i)
                print(layer)
                temp = matrix[layer][i + layer]
                matrix[layer][i + layer] = matrix[n - layer - i - 1][layer]
                matrix[n - layer - i - 1][layer] = matrix[n - layer - 1][n - layer - i - 1]
                matrix[n - layer - 1][n - layer - i - 1] = matrix[i + layer][n - layer - 1]
                matrix[i + layer][n - layer - 1] = temp

                print(matrix)