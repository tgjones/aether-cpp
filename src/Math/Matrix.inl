template <typename Derived, unsigned Order>
class MatrixDeterminantHelper
{
public:
  static double calculateDeterminant(Derived mat)
  {
    return 1;
  }
};

template <typename Derived>
class MatrixDeterminantHelper<Derived, 1>
{
public:
  static double calculateDeterminant(Derived mat)
  {
    return mat(0, 0);
  }
};

template <typename Derived, int Order>
Derived
MatrixBase<Derived, Order>::identity()
{
	Derived r;
	for (int i = 0; i < Order; i++)
		for (int j = 0; j < Order; j++)
			r(i, j) = (i == j) ? 1 : 0;
	return r;
}

template <typename Derived, int Order>
Derived
MatrixBase<Derived, Order>::invert(const Derived& m)
{
	// Get the determinant of a
	float det = 1.0f / MatrixDeterminantHelper<Derived, Order>::calculateDeterminant(m);
	return Derived();
}

// calculate the cofactor of element (row,col)
template <typename Derived, int Order>
Derived
MatrixBase<Derived, Order>::getMinor(const Derived& src, int row, int col)
{
  // Indicate which col and row is being copied to dest
 return Derived();
}

template <typename Derived, int Order>
MatrixBase<Derived, Order>::MatrixBase()
{
  for (int i = 0; i < Order; i++)
    for (int j = 0; j < Order; j++)
			at(i, j) = 0;
}

template <typename Derived, int Order>
Derived
MatrixBase<Derived, Order>::operator*(const Derived& rhs) const
{
	Derived r;
	for (int i = 0; i < Order; i++)
		for (int j = 0; j < Order; j++)
			for (int k = 0; k < Order; k++)
				r(i, j) += at(i, k) * rhs(k, j);
	return r;
}

template <typename Derived, int Order>
float
MatrixBase<Derived, Order>::operator()(const int i, const int j) const
{
  return m[(i * Order) + j];
}

template <typename Derived, int Order>
float&
MatrixBase<Derived, Order>::operator()(const int i, const int j)
{
  return m[(i * Order) + j];
}	

template <typename Derived, int Order>
float
MatrixBase<Derived, Order>::at(const int i, const int j) const
{
	return (*this)(i, j);
}

template <typename Derived, int Order>
float&
MatrixBase<Derived, Order>::at(const int i, const int j)
{
	return (*this)(i, j);
}
