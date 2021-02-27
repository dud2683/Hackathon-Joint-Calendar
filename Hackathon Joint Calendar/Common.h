#pragma once
#define DEBUG

#ifdef DEBUG
#define LOG(x) std::cout<<x<<"\n"
#else
#define LOG(x)
#endif

#define COUT(x) std::cout<<x
#define CIN(x) std::cin>>x
#define INVALID_INPUT std::cout<<"That was not a valid input, please try again\n"

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "Input.h"


