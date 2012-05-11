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

template <typename Derived, unsigned Order>
MatrixBase<Derived, Order - 1> getMinor(MatrixBase<Derived, Order> src, int row, int col)
{
	// Keep track of which col and row are being copied to dest
	int colCount = 0, rowCount = 0;
	
	MatrixBase<Derived, Order - 1> dest;
	for (int i = 0; i < Order; i++)
	{
		if (i != row)
		{
			colCount = 0;
			for (int j = 0; j < Order; j++)
			{
				if (j != col)
				{
					dest(rowCount, colCount) = src(i, j);
					colCount++;
				}
			}
			rowCount++;
		}
	}
	
	return dest;
}

template <typename Derived, unsigned Order>
class MatrixDeterminantHelper
{
public:
  static double calculateDeterminant(MatrixBase<Derived, Order> mat)
  {
		// The determinant value
		float det = 0.0f;
		
		// Allocate the cofactor matrix
		Matrix<Order - 1> minor;
		
		for (int i = 0; i < Order; i++)
		{
			// Get minor of element (0, i)
			auto minor = getMinor<Derived, Order>(mat, 0, i);
			
			// If this is an odd-numbered row, negate the value.
			float factor = (i % 2 == 1) ? -1.0f : 1.0f;
			
			// Recursion!
			det += factor * mat(0, i) * MatrixDeterminantHelper<Derived, Order - 1>::calculateDeterminant(minor);
		}
		
		return det;
  }
};

// Template specialization
template <typename Derived>
class MatrixDeterminantHelper<Derived, 1>
{
public:
  static double calculateDeterminant(MatrixBase<Derived, 1> mat)
  {
    return mat(0, 0);
  }
};

template <typename Derived, int Order>
Derived
MatrixBase<Derived, Order>::invert(const Derived& m)
{
	// Get the determinant of a
	float det = 1.0f / MatrixDeterminantHelper<Derived, Order>::calculateDeterminant(m);
	
	Derived result;
  for (int j = 0; j < Order; j++)
		for (int i = 0; i < Order; i++)
		{
			auto minor = getMinor<Derived, Order>(m, j, i);
			result(i, j) = det * MatrixDeterminantHelper<Derived, Order - 1>::calculateDeterminant(minor);
			if ((i + j) % 2 == 1)
				result(i, j) = -result(i, j);
		}
	return result;
}

template <typename Derived, int Order>
MatrixBase<Derived, Order>::MatrixBase()
{
  for (int i = 0; i < Order; i++)
    for (int j = 0; j < Order; j++)
			at(i, j) = 0;
}

template <typename Derived, int Order>
bool
MatrixBase<Derived, Order>::approximatelyEquals(const Derived &rhs) const
{
  const float EPSILON = 0.0001f;
  for (int i = 0; i < Order; i++)
    for (int j = 0; j < Order; j++)
      if (fabs(at(i, j) - rhs(i, j)) > EPSILON)
        return false;
  return true;
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
bool
MatrixBase<Derived, Order>::operator==(const Derived& rhs) const
{
  for (int i = 0; i < Order; i++)
    for (int j = 0; j < Order; j++)
      if (at(i, j) != rhs(i, j))
        return false;
  return true;
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
