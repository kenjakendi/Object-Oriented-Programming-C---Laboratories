#pragma once
#include <string>
#include <array>

const size_t maxColumns = 20;
const size_t maxRows = 20;

double average(std::array<std::array<int, maxColumns>, maxRows>& array, size_t rows, size_t columns);
int count_inner_sum(std::string str_element); // calculates the sum of digits on even positions in element of array
