#include <iostream>
#include <iomanip>

#include <cml/cml.h>
#include "Math/Matrix3D.h"

using namespace std;

struct IsCorrectMatrix
{
private:
  bool AreAlmostEqual(const float l, const float r) const
  {
    return fabs(l - r) < 0.001f;
  }
  
public:
  IsCorrectMatrix(cml::matrix44f_r expected) : _exp(expected) { }
  
  bool Matches(const Matrix3D actual) const
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (!AreAlmostEqual(_exp(i, j), actual(i, j)))
          return false;
      }
    }
    return true;
  }

  friend std::ostream& operator<<(std::ostream& stm, const IsCorrectMatrix&);
  friend std::ostream& operator<<(std::ostream& stm, const Matrix3D&);

private:
  cml::matrix44f_r _exp;
};

std::ostream& operator<<(std::ostream& stm, const IsCorrectMatrix& c)
{
  stm << std::endl;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      stm << setw(8) << setprecision(3);
      stm << c._exp(i, j);
    }
    stm << endl;
  }
  return stm;
}