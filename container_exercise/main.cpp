#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  vector<int> values{2, 5};
  values.insert(values.end(), {3, 4});

  vector<int> newVals{0, 1};
  values.insert(values.end(), newVals.begin(), newVals.end());

  vector<int> moreVals{6, 7};
  moreVals.insert(moreVals.end(), values.rbegin(), values.rend());

  for (int var : moreVals) {
    cout << var << " ";
  }
  cout << endl;

  return 0;
}
