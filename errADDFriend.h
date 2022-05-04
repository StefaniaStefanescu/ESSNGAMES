#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errADDFriend : public IException
{
public:
    string print();
};
