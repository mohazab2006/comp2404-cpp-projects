#include "Category.h"


std::string cat::categoryToString(cat::Category c){
    switch(c){
        case cat::apartment:
            return "apartment";
        case cat::condo:
            return "condo";
        case cat::bungalow:
            return "bungalow";
        case cat::townhouse:
            return "townhouse";
        case cat::misc:
            return "misc";
    }
    return "unknown category";
}