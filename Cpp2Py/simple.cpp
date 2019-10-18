
/// A Simple class
class myclass {

  int a, b;

  public:
  myclass(int _a = 39, int _b = 3): a(_a), b(_b) {}

  /// The the sum of all members
  int get_sum() const { return a + b; }
};
