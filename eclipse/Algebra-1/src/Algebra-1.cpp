//============================================================================
// Name        : Algebra-1.cpp
// Author      : Greg Rigole
// Version     :
// Copyright   : Copyright (c) 2019 - GVR Software Solutions Inc.
// Description : Using Eigen in C++, Ansi-style
//============================================================================

#include <iostream>
#include <Eigen/Dense>

using Eigen::Matrix3d;
using Eigen::Vector3d;
using namespace std;

int main()
{
  Matrix3d 		transform;
  Vector3d 		point, result;

  transform <<  1.0, 2.0, 3.0,
		        4.0, 5.0, 6.0,
			    7.0, 8.0, 9.0;
  point << 11.0, 22.0, 33.0;

  result = transform * point;

  std::cout << "Transform:" << std::endl;
  std::cout << transform << std::endl << std::endl;

  std::cout << "Point:" << std::endl;
  std::cout << point << std::endl << std::endl;

  std::cout << "Result:" << std::endl;
  std::cout << result << std::endl << std::endl;

  return 0;
}
