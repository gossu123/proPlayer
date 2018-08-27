#include "include/feat.h"

vector<double> features(L_Acc lacc1) {
  auto size = lacc1.get_x_data().size();
  vector<double> resultant_acc(size);
  double sum = 0;
  for (int i = 0; i < size; ++i) {
    double L_Accx = lacc1.get_x_data()[i];
    double L_Accy = lacc1.get_y_data()[i];
    double L_Accz = lacc1.get_z_data()[i];
    double p =
        std::sqrt((L_Accx * L_Accx) + (L_Accy * L_Accy) + (L_Accz * L_Accz));
    resultant_acc[i] = p;
    sum = sum + p;
  }
  double mean_Acc = sum / size;

  double std_deviation = 0;
  for (int i = 0; i < size; ++i) {
    std_deviation += pow(resultant_acc[i] - mean_Acc, 2);
  }
  std_deviation = sqrt(std_deviation / size);

  for (int i = 1; i < (size); ++i) {
    resultant_acc[i] = (resultant_acc[i] - mean_Acc) / std_deviation;
  }
  return resultant_acc;
}
double steps(vector<double> resultant_acc) {
  double steps = 0;
  int size = resultant_acc.size();
  for (int j = 1; j < (size - 1); ++j) {
    if ((resultant_acc[j - 1] < resultant_acc[j]) and
        (resultant_acc[j] > resultant_acc[j + 1])) {
      steps += 1;
    }
  }

  for (int j = 1; j < (size - 1); ++j) {
    if (((-1 * resultant_acc[j - 1]) < (-1 * resultant_acc[j])) and
        ((-1 * resultant_acc[j]) > (-1 * resultant_acc[j + 1]))) {
      steps += 1;
    }
  }
  return steps;
}

double distance(double steps) {
  double stride_length = 0.85;  // meter
  double distance = steps * stride_length;
  return distance;
}
