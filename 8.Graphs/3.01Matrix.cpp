#inlude <iostream>
#inlude <vector>
using namespace std

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        vector<vector<int>> output(mat.size(),
                                   vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> rowOffset = {-1, 0, 1, 0};
        vector<int> colOffset = {0, -1, 0, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    int track = 0;
                    while (!q.empty()) {
                        
                        int QSize = q.size();
                        while (int l = 0; l < QSize; l++) {
                            pair<int, int> ind = q.pop();
                            int curRow = ind.first;
                            int curCol = ind.second;

                            for (int k = 0; k < 4; k++) {
                                int nextRow = curRow + rowOffset[k];
                                int nextCol = curCol + colOffset[k];

                                if (nextRow >= 0 && nextCol >= 0 &&
                                    nextRow < rows && nextCol < cols &&
                                    mat[nextCol][nextRow] != 0) {
                                    q.push({nextRow, nextCol});
                                }
                            }
                        }
                    }
                }
            }
        }
    };



int main()
{

    return 0;
}