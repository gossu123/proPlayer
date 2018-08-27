#ifndef _MAG_HEADER
#define _MAG_HEADER

#include <vector>
#include "sensor.h"

/// Mag(Magnetometer) class on base class "Sensor"
class Mag : public Sensor {
  /// Size of Vector
  int size;
  /// Magnetometer x-axis data
  std::vector<double> x;
  /// Magnetometer y-axis data
  std::vector<double> y;
  /// Magnetometer z-axis data
  std::vector<double> z;

 public:
  /// Storing magnetometer's x, y, z data
  explicit Mag(vector<double> p, vector<double> q, vector<double> r);
  /// Constructor
  Mag();
  /// Destructor
  ~Mag();
  /// Return magnetometer's x, y, z data
  vector<double> get_x_data();
  vector<double> get_y_data();
  vector<double> get_z_data();
};

#endif
