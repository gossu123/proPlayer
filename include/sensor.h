#ifndef _SENSOR_HEADER
#define _SENSOR_HEADER

#include <iostream>
#include <vector>
/// namespace
using namespace std;
/// Sensor(Base class)
class Sensor {
 public:
  /// Destructor
  virtual ~Sensor();
  /// Return x, y, z data
  virtual vector<double> get_x_data() = 0;
  virtual vector<double> get_y_data() = 0;
  virtual vector<double> get_z_data() = 0;
};

#endif
