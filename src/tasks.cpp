#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (!lhs | !rhs) {
        return;
    }
    int x = *rhs;
    *rhs = *lhs;
    *lhs = x;
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {

    if (num_rows>0 && num_cols>0) {
        int **array_2d = new int *[num_rows];
        for (int row_index = 0; row_index < num_rows; row_index++) {
            array_2d[row_index] = new int[num_cols];
        }

        for (int row_index = 0; row_index < num_rows; row_index++) {
            for (int column_index = 0; column_index < num_cols; column_index++) {
                array_2d[row_index][column_index] = init_value;
            }
        }

        return array_2d;
    }
    return nullptr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (arr_2d_source && arr_2d_target && num_rows > 0 && num_cols > 0) {
        for (int row_index = 0; row_index < num_rows; row_index++) {
            for (int column_index = 0; column_index < num_cols; column_index++) {
                arr_2d_target[row_index][column_index] = arr_2d_source[row_index][column_index];
                }
            }
        return true;
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {

    int arr_size = arr.size();
    if (arr_size != 0) {
        for (int index = 0; index < (arr_size / 2); index++) {
            int x = arr[index];
            arr[index] = arr[arr_size - index - 1];
            arr[arr_size - index - 1] = x;
        }
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin && arr_end){
        for(;arr_end>arr_begin; arr_end--, arr_begin++){
            swap_args(arr_begin,arr_end);
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if(arr && size>0){
        int *max = arr;
        for(int i = 0; i < size ; i++){
            if(*arr > *max){
                max = arr;
            }
            arr++;
        }
        return max;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> odd_numbers {};
    for(int el : arr){
        if(std::abs(el)%2==1){
            odd_numbers.push_back(el);
        }
    }
    return odd_numbers;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> common_elements {};
    for(int & i : arr_a){
        for (int j : arr_b){
            if(i == j){
                common_elements.push_back(i);
            }
        }
    }
    return common_elements;
}
