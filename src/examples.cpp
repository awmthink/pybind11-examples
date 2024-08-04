#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <algorithm>
#include <memory>
#include <numeric>
#include <random>
#include <utility>
#include <vector>

std::string Hello(const std::string& greeting) { return "hello, " + greeting; }

std::vector<int> RangeList(int from, int to) {
  std::vector<int> vec(to - from);
  std::iota(vec.begin(), vec.end(), from);
  return vec;
}

PYBIND11_MODULE(examples, m) {
  m.doc() = "pybind11 example plugin";

  using namespace pybind11::literals;
  m.def("hello", &Hello, "greeting"_a);
  m.def("range_list", &RangeList, "from"_a, "to"_a);
}