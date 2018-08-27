#ifndef _LI_ACC_HEADER
#define _LI_ACC_HEADER

#include <vector>
#include "sensor.h"

/// L_Acc(Linear Accelerometer) class on base class "Sensor"
class L_Acc : public Sensor {
  /// Size of Vector
  int size;
  /// Linear accelerometer x-axis data
  std::vector<double> x;
  /// Linear accelerometer y-axis data
  std::vector<double> y;
  /// Linear accelerometer z-axis data
  std::vector<double> z;

 public:
  /// Storing linear accelerometer's x, y, z data
  explicit L_Acc(vector<double> p, vector<double> q, vector<double> r);
  /// Constructor
  L_Acc();
  /// Destructor
  ~L_Acc();
  /// Return linear accelerometer's x, y, z data
  vector<double> get_x_data();
  vector<double> get_y_data();
  vector<double> get_z_data();
};

#endif
