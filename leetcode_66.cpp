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
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(0 == len){
            digits.push_back(0);
            return digits;
        }

        for(int i=len-1; i>=0; --i){
            int tmp = digits[i] + 1;
            if(tmp <= 9){
                digits[i] = tmp;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution ins;
    vector<int> test {9,9,9};
    vector<int> result = ins.plusOne(test);
    int len = result.size();
    for(int i=0; i<len; ++i){
        cout<<result[i]<<",";
    }
    cout<<endl;
    return 0;
}