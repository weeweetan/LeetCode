//
// Created by 11135 on 2021/3/2.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    bool isValid(vector<string>& board, int row, int col)
    {
        int n = board.size();

        //检查列是否有皇后冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--,j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        //检查左上方是否有皇后冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    // 回溯函数
    void backtrack(vector<string>& board, int row)
    {
        //触发结束条件
        if (row == board.size())
        {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col))
                continue;
            //做选择
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }

    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
};
