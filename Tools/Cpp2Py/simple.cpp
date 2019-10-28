#include <vector>

/// A Simple class
class myclass {

  int a = 35, b = 3, c = 5;

  public:
  myclass() = default;

  /// Return a vector with all members
  std::vector<int> list_of_members() const { return {a, b, c}; }
};
