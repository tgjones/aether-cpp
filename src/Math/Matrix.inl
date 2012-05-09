template <typename Derived, int Order>
Derived
Matrix<Derived, Order>::invert(const Derived& m)
{
	// Get the determinant of a
	float det = 1.0f / calculateDeterminant(m, Order);
	return Derived();
}