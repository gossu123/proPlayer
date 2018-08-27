#ifndef _ACC_HEADER
#define _ACC_HEADER

#include <vector>
#include "sensor.h"

/// Acc(Accelerometer) class on base class "Sensor"
class Acc : public Sensor {
  /// Size of Vector
  int size;
  /// Accelerometer x-axis data
  std::vector<double> x;
  /// Accelerometer y-axis data
  std::vector<double> y;
  /// Accelerometer z- axis data
  std::vector<double> z;

 public:
  /// Storing accelerometer's x, y, z data
  explicit Acc(vector<double> p, vector<double> q, vector<double> r);
  /// Constructor
  Acc();
  /// Destructor
  ~Acc();
  /// Return accelerometer's x,y,z data
  vector<double> get_x_data();
  vector<double> get_y_data();
  vector<double> get_z_data();
};

#endif
