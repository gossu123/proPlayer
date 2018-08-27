#ifndef _GYRO_HEADER
#define _GYRO_HEADER

#include <vector>
#include "sensor.h"

/// Gyro(Gyroscope) class on base class "Sensor"
class Gyro : public Sensor {
  /// Size of Vector
  int size;
  /// Gyroscope x-axis data
  std::vector<double> x;
  /// Gyroscope y-axis data
  std::vector<double> y;
  /// Gyroscope z-axis data
  std::vector<double> z;

 public:
  /// Storing gyroscope's x, y, z data
  explicit Gyro(vector<double> p, vector<double> q, vector<double> r);
  /// Constructor
  Gyro();
  /// Destructor
  ~Gyro();
  /// Return accelerometer's x, y, z data
  vector<double> get_x_data();
  vector<double> get_y_data();
  vector<double> get_z_data();
};

#endif
