#include <bits/stdc++.h>

using namespace std;

void CustomGenerator(int seed) {
  std::srand(seed);

}

int main(int argv, char *argc[]) {
  int seed = stoi(std::string(argc[1]));
  srand(seed);
  CustomGenerator(seed);
}
