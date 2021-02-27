#pragma once
#define DEBUG

#ifdef DEBUG
#define LOG(x) std::cout<<x<<"\n"
#else
#define LOG(x)
#endif

#define COUT(x) std::cout<<x
#define CIN(x) std::cin>>x

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "imput.h"
