#include"include/function.h"

vector<vector<double>> rpy(Acc acc1, Mag mag1) {
  auto size = mag1.get_z_data().size();
  vector<vector<double>> rpy(size);

  for (int i = 0; i < size; ++i) {
    double AccX = acc1.get_x_data()[i];
    double AccY = acc1.get_y_data()[i];
    double AccZ = acc1.get_z_data()[i];
    double MagX = mag1.get_x_data()[i];
    double MagY = mag1.get_y_data()[i];
    double MagZ = mag1.get_z_data()[i];

    double pitch = atan2(AccY, (sqrt((AccX * AccX) + (AccZ * AccZ))));

    double roll = atan2(-1 * AccX, (sqrt((AccY * AccY) + (AccZ * AccZ))));

    double Yh = (MagY * cos(roll)) - (MagZ * sin(roll));

    double Xh = (MagX * cos(pitch)) + (MagY * sin(roll) * sin(pitch)) +
                (MagZ * cos(roll) * sin(pitch));

    double yaw = atan2(Yh, Xh);
    rpy[i] = vector<double>(3);
    rpy[i][0] = roll * 57.3;
    rpy[i][1] = pitch * 57.3;
    rpy[i][2] = yaw * 57.3;
  }
  return rpy;
}
