#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<algorithm>
#include <vector>
//#include <cmath>
//#include <map>
using namespace std;

class Solution {
public:
    bool isValidSudoku_ori(vector<vector<char>>& board) {
        
        for(int i=0; i<9; ++i){
            vector<int> unit(9,0);
            for(int j=0;j<9;++j){
                if(board[i][j] != '.'){
                    int tmp = board[i][j] - '1';
                    if(unit[tmp] == 0){
                        unit[tmp] = 1;
                    }else{
                        cout<<"col "<<i<<" "<<j<<endl;
                        return false;
                    }
                }
            }
        }
        for(int i=0; i<9; ++i){
            vector<int> unit(9,0);
            for(int j=0;j<9;++j){
                if(board[j][i] != '.'){
                    int tmp = board[j][i] - '1';
                    if(unit[tmp] == 0){
                        unit[tmp] = 1;
                    }else{
                        cout<<"row "<<i<<" "<<j<<endl;
                        return false;
                    }
                }
            }
        }
        for(int i=0; i<9; ++i){
            vector<int> unit(9,0);
            for(int j=0;j<9;++j){
                int l = (i/3)*3 + j/3;
                int r = (i%3)*3 + j%3; 
                if(board[l][r] != '.'){
                    int tmp = board[l][r] - '1';
                    if(unit[tmp] == 0){
                        unit[tmp] = 1;
                    }else{
                        cout<<i<<" "<<j<<endl;
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int col[9][9] = {0};
        int row[9][9] = {0};
        int box[9][9] = {0};
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.'){
                    continue;
                }else{
                    int tmp = board[i][j] - '1';
                    if(0 == col[i][tmp]){
                        col[i][tmp] = 1;
                    }else{
                        return false;
                    }
                    if(0 == row[j][tmp]){
                        row[j][tmp] = 1;
                    }else{
                        return false;
                    }
                    int idx = (i/3)*3 + (j/3);
                    if(0 == box[idx][tmp]){
                        box[idx][tmp] = 1;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution ins;
    vector<vector<char>> test_1 = {vector<char> {'5','3','.','.','7','.','.','.','.'}
                                ,vector<char> {'6','.','.','1','9','5','.','.','.'}
                                ,vector<char> {'.','9','8','.','.','.','.','6','.'}
                                ,vector<char> {'8','.','.','.','6','.','.','.','3'}
                                ,vector<char> {'4','.','.','8','.','3','.','.','1'}
                                ,vector<char> {'7','.','.','.','2','.','.','.','6'}
                                ,vector<char> {'.','6','.','.','.','.','2','8','.'}
                                ,vector<char> {'.','.','.','4','1','9','.','.','5'}
                                ,vector<char> {'.','.','.','.','8','.','.','7','9'}};


vector<vector<char>> test_2 = {vector<char>{'8','3','.','.','7','.','.','.','.'}
                                ,vector<char>{'6','.','.','1','9','5','.','.','.'}
                                ,vector<char>{'.','9','8','.','.','.','.','6','.'}
                                ,vector<char>{'8','.','.','.','6','.','.','.','3'}
                                ,vector<char>{'4','.','.','8','.','3','.','.','1'}
                                ,vector<char>{'7','.','.','.','2','.','.','.','6'}
                                ,vector<char>{'.','6','.','.','.','.','2','8','.'}
                                ,vector<char>{'.','.','.','4','1','9','.','.','5'}
                                ,vector<char>{'.','.','.','.','8','.','.','7','9'}};
    bool res = ins.isValidSudoku(test_1);

    cout<<"content: "<<endl;
    int count = 0;
    for(auto it: test_1){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"   "<<it[3]<<" "<<it[4]<<" "<<it[5]<<"   "<<it[6]<<" "<<it[7]<<" "<<it[8]<<endl;
        count++;
        if(0 == count%3){
            cout<<endl;
        }
    }

    if(res){
        cout<<"valid"<<endl;
    }else{
        cout<<"invalid"<<endl;
    }


    res = ins.isValidSudoku(test_2);
    cout<<"content: "<<endl;
    count = 0;
    for(auto it: test_2){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"   "<<it[3]<<" "<<it[4]<<" "<<it[5]<<"   "<<it[6]<<" "<<it[7]<<" "<<it[8]<<endl;
        count++;
        if(0 == count%3){
            cout<<endl;
        }
    }

    if(res){
        cout<<"valid"<<endl;
    }else{
        cout<<"invalid"<<endl;
    }
    return 0;
}