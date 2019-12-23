#ifndef DEFS_H
#define DEFS_H

#include <cmath>
#include <vector>

#include <eigen3/Eigen/Core>

//=======================================================================================

static constexpr auto mat_size = 8;

using VecInt   = std::vector<int>;
using VecDbl   = std::vector<double>;
using VecFlt   = std::vector<float>;
using VecCh    = std::vector<char>;

using VecMatXd = std::vector<Eigen::MatrixXd>;

struct Signal
{
    Eigen::MatrixXd origin;
    Eigen::MatrixXd noise;
    Eigen::MatrixXd shift;
    Eigen::MatrixXd filter;

    int size;
};

//=======================================================================================

#endif // DEFS_H
