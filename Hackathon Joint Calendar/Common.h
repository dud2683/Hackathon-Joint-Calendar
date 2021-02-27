#pragma once
#define DEBUG

#ifdef DEBUG
#define LOG(x) std::cout<<x
#else
#define LOG(x)
#endif


#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
