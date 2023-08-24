#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>

namespace ivl {

  void print_table(auto&& callable, auto&& rowindices, auto&& colindices, std::uint32_t cellwidth = 4){

    std::cout << std::setw(4) << " \\ " << std::setw(4) << " | ";
    for (auto col : colindices)
      std::cout << std::setw(4) << col;
    std::cout << std::endl;
    std::cout << std::setw(4) << std::setfill('-') << "-" << std::setw(4) << " \\ ";
    for (auto col : colindices)
      std::cout << std::setw(4) << '-';
    std::cout << std::endl << std::setfill(' ');
  
    for (auto row : rowindices){
      std::cout << std::setw(4) << row << std::setw(4) << " | ";
      for (auto col : colindices)
        std::cout << std::setw(4) << callable(row, col);
      std::cout << std::endl;
    }
    
  }
  
};
