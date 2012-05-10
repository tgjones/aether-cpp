#ifndef Aether_Matrix_h
#define Aether_Matrix_h

template <typename Derived, int Order>
class MatrixBase
{
public:
  // Static constants
	static const Derived Identity;
	
	// Static methods
	static Derived invert(const Derived& m);
	
	// Constructors
	template<class ...T> inline constexpr MatrixBase(float first, T... next)
	  : m{first, next...} {}
  MatrixBase();
	
	// Operators
	float operator()(const int i, const int j) const;
	
protected:
	// Protected data
	float m[Order * Order];
	
private:
  // Private methods
  Derived getMinor(const Derived& src, int row, int col);
};

template <int Order>
class Matrix : public MatrixBase<Matrix<Order>, Order>
{
};

#include "Matrix.inl"

#endif