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
#define SLEEP(x) std::this_thread::sleep_for (std::chrono::seconds(x))
#define YES_NO std::cout<<"Yes (1), No (2)\n"

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include "Input.h"
#include <thread>
#include <chrono>


