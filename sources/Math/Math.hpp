#ifndef _MATH_HPP_
#define _MATH_HPP_

#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <ctgmath>
#include <limits>
#include <utility>
#include <vector>

#ifndef M_PI
# define M_PI	3.14159265358979323846
#endif

namespace std
{
  template<typename Type>
  inline constexpr const Type & clamp(const Type & value, const Type & low, const Type & high)
  {
    return std::min(high, std::max(low, value));
  }
};

namespace Math
{
  float const	Pi = (float)M_PI;	// Use this instead of M_PI
  
  template<int Mod>
  inline int	Modulo(int i)
  {
    int	r = i % Mod;

    return r < 0 ? r + Mod : r;
  }

  inline int	Modulo(int i, int n)	// Return the positive modulo i of n
  {
    int	r = i % n;

    return r < 0 ? r + n : r;
  };

  inline float	RadToDeg(float r) { return (r * 180) / Math::Pi; };	// Convert radian (* accuracy) to degree
  inline float	DegToRad(float r) { return (r * Math::Pi) / 180; };	// Convert degree to radian (* accuracy)
};

#endif
