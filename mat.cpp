#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "mat.hpp"

namespace ariel{
    std::string mat(int col, int row, char char1, char char2){
        int helper = 0;
        int total = row * col;
        int counter =0;
        const int max_char = 126;
        const int min_char = 33;
        std::string answer;
        // Check if the dimentions are odd
        if((row * col) % 2 == 0){
            throw std::out_of_range{"Mat size is always odd"};
        }
        // Check if the simbols are ok for both simbols
        if(char1 == '\n' || char1 == '\t' || char1 == '\v' || char1 == '\0'){
            throw std::invalid_argument{"not valid simbol"};
        }
        if(char2 == '\n' || char2 == '\t' || char2 == '\v' || char2 == '\0'){
            throw std::invalid_argument{"not valid simbol"};
        }
        if((int)char1 < min_char || (int)char1> max_char){
            throw std::invalid_argument{"not valid simbol"};
        }
        if((int)char2 < min_char || (int)char2 > max_char){
            throw std::invalid_argument{"not valid simbol"};
        }
        //Allocate a vector for my matrix
        std::vector<std::vector<char>> matrix (row,std::vector<char>(col));
        //Loop until i painted all cell in matrix
        while (counter < total){
            //Upper row
            for(int i=helper ; i< col - helper ; i++){
                if (helper % 2 == 0){
                    matrix[helper][i] = char1;
                    counter = counter + 1;
                }
                else{
                    matrix[helper][i] = char2;
                    counter = counter + 1;
                }
            }
            // Left colum
            for(int i = helper + 1;i < row - helper ; i++){
                if (helper % 2 == 0){
                    matrix[i][helper] = char1;
                    counter = counter + 1;
                }
                else{
                    matrix[i][helper] = char2;
                    counter = counter + 1;
                }
            }
            // Lower row
            for(int i = helper + 1;i < col - helper ; i++){
                if (helper % 2 == 0){
                    matrix[row -1 -helper][i] = char1;
                    counter = counter + 1;
                }
                else{
                    matrix[row -1 -helper][i] = char2;
                    counter = counter + 1;
                }
            }
            // Right colum
            for(int i = helper +1 ;i < row - helper -1 ; i++){
                if (helper % 2 == 0){
                    matrix[i][col -1 -helper] = char1;
                    counter = counter + 1;
                }
                else{
                    matrix[i][col -1- helper] = char2;
                    counter = counter + 1;
                }
            }
            helper = helper + 1;
        }
        //Copy matrix values to string
        for (int i = 0; i < row ; i++){
            answer += '\n';
            for (int j =0; j< col; j++){
                answer += matrix[i][j];
            }
        }
        return answer;
    }
}
