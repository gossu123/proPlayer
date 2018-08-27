#ifndef _FUNCTION_HEADER
#define _FUNCTION_HEADER

#include <cmath>
#include <iostream>
#include "include/accelerometer.h"
#include "include/magnetometer.h"

/// Calculates roll pitch yaw
vector<vector<double>> rpy(Acc acc1, Mag mag1);

#endif
