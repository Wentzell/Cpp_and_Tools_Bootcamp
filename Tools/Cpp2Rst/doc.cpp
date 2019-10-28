namespace NS {

  /**
   * A brief description of this overload
   *
   * @include  File to include [default: the definition file]
   *
   * @head  Head of longer description
   * @tail  Tail of longer description
   *
   * @figure image.png: Optional illustration
   * @tparam T  Doc of template parameter
   * @param t   Doc of parameter
   * @return    Doc of returned value
   *
   * @warning  Optional Warning
   */
  template <typename T>
  T func(T t) {
    return t;
  }

  /**
   * Another overload
   */
  template <typename T>
  T func() {
    return T{};
  }

  /**
   * A brief description
   *
   * A more detailed description
   *
   * @include  File to include [default: the definition file]
   *
   * @tparam T  Doc of template parameter
   * @note     Optional Note
   * @warning  Optional Warning
   * @figure image.png: Optional illustration
   */
  template <typename T>
  struct cls {

    /// A default constructor
    cls(){}

    /// A public member
    int member;

    /// A public member function
    void func(){}
  };

} // namespace NS
