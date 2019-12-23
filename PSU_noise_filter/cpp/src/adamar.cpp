#include "adamar.h"

using namespace std;
using namespace Eigen;

//=======================================================================================
MatrixXd Adamar::make( const MatrixXd& src )
{
    MatrixXd res = src;

    for ( int i = 0; i < src.rows(); i++ )
        res.row(i) = four( res.row(i) );

    for ( int i = 0; i < src.rows(); i++ )
    {
        RowVectorXd tmp( src.cols() );

        for ( auto j = 0; j < src.cols(); j++ )
            tmp(i) = src( j, i );

        auto afour = four( tmp );

        for ( auto j = 0; j < src.cols(); j++ )
            res( j, i ) = afour(j);
    }

    return res;
}
//=======================================================================================
MatrixXd Adamar::reverse( const MatrixXd& src )
{
    MatrixXd res = src;

    res = res / qPow( src.cols(), 2 );

    for ( int i = 0; i < src.rows(); i++ )
        res.row(i) = four_reverse( res.row(i) );

    for ( int i = 0; i < src.rows(); i++ )
    {
        RowVectorXd tmp( src.cols() );

        for ( auto j = 0; j < src.cols(); j++ )
            tmp(i) = src( j, i );

        for ( auto j = 0; j < src.cols(); j++ )
            res( j, i ) = tmp(j);
    }

    return res;
}
//=======================================================================================


//=======================================================================================
RowVectorXd Adamar::four( const RowVectorXd& row )
{
    RowVectorXd res( row.cols() );

    RowVectorXd nline( row.cols() );
    nline << row(0), row(4), row(2), row(6), row(1), row(5), row(3), row(7);

    auto delta = 4;

    for ( auto i = 0; i < delta; i++ )
        res(i) = nline(i) + nline( i + delta );

    for ( auto i = delta; i < row.cols(); i++ )
        res(i) = - nline(i) + nline( i - delta );

    nline = res;

    delta = 2;

    for ( auto i = 0; i < delta; i++ )
        res(i) = nline(i) + nline( i + delta );

    for ( auto i = delta; i < 2 * delta; i++ )
        res(i) = - nline(i) + nline( i - delta );

    for ( auto i = 2 * delta; i < 3 * delta; i++ )
        res(i) = nline(i) - nline( i + delta );

    for ( auto i = 3 * delta; i < row.cols(); i++ )
        res(i) = nline(i) + nline( i - delta );

    nline = res;

    res(0) = nline(0) + nline(1);
    res(1) = nline(0) - nline(1);

    res(2) = nline(2) - nline(3);
    res(3) = nline(2) + nline(3);

    res(4) = nline(4) + nline(5);
    res(5) = nline(4) - nline(5);

    res(6) = nline(6) - nline(7);
    res(7) = nline(6) + nline(7);

    return res;
}
//=======================================================================================
RowVectorXd Adamar::four_reverse( const RowVectorXd& row )
{
    RowVectorXd res( row.cols() );

    auto nline = row;

    auto delta = 4;

    for ( auto i = 0; i < delta; i++ )
        res(i) = nline(i) + nline( i + delta );

    for ( auto i = delta; i < row.cols(); i++ )
        res(i) = nline(i) + nline( i - delta );

    nline = res;

    delta = 2;

    for ( auto i = 0; i < delta; i++ )
        res(i) = nline(i) + nline( i + delta );

    for ( auto i = delta; i < 2 * delta; i++ )
        res(i) = - nline(i) + nline( i - delta );

    for ( auto i = 2 * delta; i < 3 * delta; i++ )
        res(i) = nline(i) - nline( i + delta );

    for ( auto i = 3 * delta; i < row.cols(); i++ )
        res(i) = nline(i) + nline( i - delta );

    nline = res;

    res(0) = nline(0) + nline(1);
    res(1) = nline(0) - nline(1);

    res(2) = nline(2) - nline(3);
    res(3) = nline(2) + nline(3);

    res(4) = nline(4) + nline(5);
    res(5) = nline(4) - nline(5);

    res(6) = nline(6) - nline(7);
    res(7) = nline(6) + nline(7);

    res << row(0), row(7), row(4), row(3), row(2), row(5), row(6), row(1);

    return res;
}
//=======================================================================================
