#ifndef Aether_Matrix_h
#define Aether_Matrix_h

template <typename Derived, int Order>
class MatrixBase
{
public:
	// Static methods
	static Derived identity();
	static Derived invert(const Derived& m);
	
	// Constructors
	template<class ...T>
	MatrixBase(float first, T... next)
		: m { first, next... }
	{ }
	
	MatrixBase();
	
	// Operators
	Derived operator*(const Derived& rhs) const;
	float operator()(const int i, const int j) const;
	float& operator()(const int i, const int j);
	
protected:
	// Protected data
	float m[Order* Order];
	
	// Protected methods
	float at(const int i, const int j) const;
	float& at(const int i, const int j);
	
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