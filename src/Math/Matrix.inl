template <typename Derived, unsigned Order>
class MatrixDeterminantHelper
{
public:
  double calculateDeterminant(Derived mat)
  {
    return 1;
  }
};

template <typename Derived>
class MatrixDeterminantHelper<Derived, 1>
{
public:
  double calculateDeterminant(Derived mat)
  {
    return mat(0, 0);
  }
};

template <typename Derived, int Order>
Derived
MatrixBase<Derived, Order>::invert(const Derived& m)
{
	// Get the determinant of a
	float det = 1.0f / calculateDeterminant(m, Order);
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
MatrixBase::MatrixBase()
{
  for (int i = 0; i < Order; i++)
    for (int j = 0; j < Order; j++)
    {
      m[i]
    }
  m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
	m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
}