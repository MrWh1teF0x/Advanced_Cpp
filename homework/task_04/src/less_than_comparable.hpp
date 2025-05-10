#ifndef LESS_THAN_COMPARABLE_HPP
#define LESS_THAN_COMPARABLE_HPP

template <typename T>
class less_than_comparable {
 public:
  friend bool operator>(T const& lhs, T const& rhs) { return rhs < lhs; }

  friend bool operator<=(T const& lhs, T const& rhs) { return !(rhs < lhs); }

  friend bool operator>=(T const& lhs, T const& rhs) { return !(lhs < rhs); }

  friend bool operator==(T const& lhs, T const& rhs) {
    return !(lhs < rhs) && !(rhs < lhs);
  }

  friend bool operator!=(T const& lhs, T const& rhs) {
    return (lhs < rhs) || (rhs < lhs);
  }
};

#endif  // LESS_THAN_COMPARABLE_HPP