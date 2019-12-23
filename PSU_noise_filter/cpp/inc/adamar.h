#ifndef ADAMAR_H
#define ADAMAR_H

#include <QtMath>

#include "defs.h"

//=======================================================================================

class Adamar
{
public:

    static Eigen::MatrixXd make( const Eigen::MatrixXd& mat );

    static Eigen::MatrixXd reverse( const Eigen::MatrixXd& mat );

private:

    static Eigen::RowVectorXd four( const Eigen::RowVectorXd& row );

    static Eigen::RowVectorXd four_reverse( const Eigen::RowVectorXd& row );

};

//=======================================================================================

#endif // ADAMAR_H
