// 
// Author: Faiyam Islam (z5258151)
// Date: 3/11/21
//
// Description:
// A C program which implements fractions

#include "fractions.h"

// These are function stubs!
// They are functions which compile but do not have the correct behaviour.

double convert(struct fraction frac) {
    // TODO: complete the function
    double quotient; 
    double numerator = frac.top; 
    double denominator = frac.bottom; 
    quotient = numerator / denominator; 
        
    return quotient; 
}

struct fraction add(struct fraction first, struct fraction second) {
    // TODO: complete the function
    struct fraction result; 
    result.top = (first.top * second.bottom) + (first.bottom * second.top); 
    result.bottom = first.bottom * second.bottom; 
   
    if (first.top == 0) {
        result.top = second.top; 
        result.bottom = second.bottom; 
    }
   
    else if (second.top == 0) {
        result.top = first.top; 
        result.bottom = first.bottom; 
    }
    
    return result; 
}



