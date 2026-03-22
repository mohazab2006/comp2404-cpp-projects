#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>


namespace cat{
    
    enum Category {apartment, condo, bungalow, townhouse, misc};

    std::string categoryToString(Category c);

}
#endif