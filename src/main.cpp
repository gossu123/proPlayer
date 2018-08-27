#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "include/accelerometer.h"
#include "include/feat.h"
#include "include/function.h"
#include "include/gyroscope.h"
#include "include/json.hpp"
#include "include/linear_acc.h"
#include "include/magnetometer.h"
#include "include/sensor.h"
/// namespace
using json = nlohmann::json;
using namespace std;

vector<double> data_1D;
/// Importing data
ifstream fin("data/data.json");

/// Parsing json file
auto j = json::parse(fin);
vector<double> get_data_vector_1D(string key) {
  for (json::iterator it = j.begin(); it != j.end(); ++it) {
    data_1D.push_back((*it)[key]);
  }
  return std::move(data_1D);
}
/// main function
int main() {
  /// Storing acceleration x, y, z data in vector variables
  auto x_acc = get_data_vector_1D("Acc_x");
  auto y_acc = get_data_vector_1D("Acc_y");
  auto z_acc = get_data_vector_1D("Acc_z");

  /// Storing gyroscope x, y, z data in vector variables
  auto x_gyro = get_data_vector_1D("Gyro_x");
  auto y_gyro = get_data_vector_1D("Gyro_y");
  auto z_gyro = get_data_vector_1D("Gyro_z");

  /// Storing magnetometer x, y, z data in vector variables
  auto x_mag = get_data_vector_1D("Mag_x");
  auto y_mag = get_data_vector_1D("Mag_y");
  auto z_mag = get_data_vector_1D("Mag_z");

  /// Storing linear acceleration x, y, z data in vector variables
  auto x_l_acc = get_data_vector_1D("L_Acc_x");
  auto y_l_acc = get_data_vector_1D("L_Acc_y");
  auto z_l_acc = get_data_vector_1D("L_Acc_z");

  /// object
  Acc acc1(x_acc, y_acc, z_acc);
  Gyro name(x_gyro, y_gyro, z_gyro);
  Mag mag1(x_mag, y_mag, z_mag);
  L_Acc lacc1(x_l_acc, y_l_acc, z_l_acc);

  /// function calling and storing result to variables
  int size = mag1.get_z_data().size();
  vector<double> acceleration = features(lacc1);
  double T_steps = steps(acceleration);
  double distance_covered = distance(T_steps);
  vector<vector<double>> roll_pitch_yaw = rpy(acc1, mag1);

  /// printing results
  cout << "Total steps= " << T_steps << "\n";
  cout << "Distance covered= " << distance_covered << "\n";
  cout << "Final roll= " << roll_pitch_yaw[size - 1][0] << "\n";
  cout << "Final pitch= " << roll_pitch_yaw[size - 1][1] << "\n";
  cout << "Final yaw= " << roll_pitch_yaw[size - 1][2] << "\n";
  return 0;
}
