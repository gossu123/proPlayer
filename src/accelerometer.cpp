#include "include/accelerometer.h"

Acc::Acc(vector<double> p, vector<double> q, vector<double> r)
    : size(p.size()) {
  auto iter = p.begin();
  int i = 0;
  for (iter; iter != p.end(); ++iter, i++) {
    x.push_back(*iter);
    // cout << x[i];
  }
  iter = q.begin();
  i = 0;
  for (iter; iter != q.end(); ++iter, i++) {
    y.push_back(*iter);
    // cout << y[i];
  }
  iter = r.begin();
  i = 0;
  for (iter; iter != r.end(); ++iter, i++) {
    z.push_back(*iter);
    // cout << z[i];
  }
}

Acc::Acc() {}
Acc::~Acc() {}

vector<double> Acc::get_x_data() { return x; }
vector<double> Acc::get_y_data() { return y; }
vector<double> Acc::get_z_data() { return z; }
