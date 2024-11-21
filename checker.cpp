#include <iostream>

int CustomComparison(const std::string &stress_out, const std::string &main_out) {
  std::string f1, f2;
  freopen(stress_out.c_str(), "r", stdin);
  std::cin >> f1;
  freopen(main_out.c_str(), "r", stdin);
  std::cin >> f2;
  if (f1 != f2) {
    return 1;
  }
  return 0;
}

int main(int argv, char *argc[]) {
  // argc {_, type comparison, stress out, main out}
  std::string stress_out = argc[2];
  std::string main_out = argc[3];
  if (argc[1][0] == '0') {
    // byte-by-byte comparison
    return system(("fc " + stress_out + " " + main_out + " >NUL").c_str());
  }
  return CustomComparison(stress_out, main_out);
}