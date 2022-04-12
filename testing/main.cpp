#include <iostream>
#include <chrono>
#include <tuple>
using namespace std;
using namespace std::chrono;

tuple<int, int> fibo(int i);
int bad_fibo(int i);

int main() {
  auto start = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
  tuple<int, int> a = make_tuple(0,0);
  for (int i = 0; get<0>(a) >= 0; i++) {
    start = high_resolution_clock::now();
    a = fibo(i);
    duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
    cout << i << ',' << get<0>(a) << " Took " << duration.count() << endl;
  }
  start = high_resolution_clock::now();
  duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
  int b;
  for (int i = 0; duration.count() < 100; i++) {
    start = high_resolution_clock::now();
    b = bad_fibo(i);
    duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
    cout << i << ',' << b << " Took " << duration.count() << endl;
  }
}

tuple<int, int> fibo(int i) {
  if (i == 1) {
    return make_tuple(i,i-1);
  } else if (i == 0) {
    return make_tuple(i,i+1);
  }
  tuple<int, int> a = fibo(i-1);
  return make_tuple(get<0>(a)+get<1>(a),get<0>(a));
}

int bad_fibo(int i) {
  if (i < 2) {
    return i;
  }
  return bad_fibo(i-1)+bad_fibo(i-2);
}
