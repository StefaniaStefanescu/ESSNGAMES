#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errPathImage : public IException
{
public:
    string print();
};
