#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errDeleteFriend : public IException
{
public:
    string print();
};
