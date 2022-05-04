#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errSchimbaParola : public IException
{
public:
    string print();
};