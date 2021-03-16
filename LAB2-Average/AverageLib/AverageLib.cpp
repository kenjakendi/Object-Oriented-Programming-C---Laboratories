#include "Average.h"
using namespace std;

double average(array<array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns)
{
    double sum_all = 0;
    int count_elements = 0;
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t column = 0; column < columns; column++)
        {
            int element = array[row][column];
            string str_element = to_string(element);
            if (str_element.length() > 1)
            {
                int inner_sum = count_inner_sum(str_element);
                if (inner_sum % 2 == 0)
                {
                    sum_all += element;
                    count_elements++;
                }
            }
        }
    }
    if (sum_all == 0)
    {
        return 0;
    }
    else
    {
        return sum_all / count_elements;
    }
}

int count_inner_sum(string str_element)
{
    int inner_sum = 0;
    for (int k = str_element.length() - 2; k >= 0; k -= 2)
    {
        inner_sum += (int)str_element[k] - 48;
    }
    return inner_sum;
}