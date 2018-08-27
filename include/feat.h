#ifndef _FEATURES_HEADER
#define _FEATURES_HEADER

#include <cmath>
#include <iostream>
#include <vector>
#include "include/linear_acc.h"
/// namespace
using namespace std;
/// Features function calculates normalized resultant acceleration
vector<double> features(L_Acc lacc1);
/// Steps function calculates number of steps
double steps(vector<double> resultant_acc);
/// Distance function calculates total distance covered
double distance(double steps);

#endif
