#ifndef Aether_MatrixBase_h
#define Aether_MatrixBase_h

template <typename Derived, int Order>
class Matrix
{
public:
	static Derived invert(const Derived& m);
	
private:
	static double calculateDeterminant(float** mat, int order);
	static int calculateMinor(float** src);
};

#include "Matrix.inl"

#endif