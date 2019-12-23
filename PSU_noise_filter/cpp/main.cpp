#include <iostream>

#include <eigen3/Eigen/Dense>

#include <QGuiApplication>
#include <QtDataVisualization>

#include "defs.h"
#include "jparse.h"
#include "adamar.h"

using namespace std;
using namespace Eigen;
using namespace QtDataVisualization;

static constexpr auto cfg_path = "../cpp/matrix.json";

//=======================================================================================

int main( int argc, char **argv )
{
    QGuiApplication qapp( argc, argv );

    auto src = JParse::json_parse( cfg_path );

    Signal res;

    res.origin = Adamar::make( src.origin );
    res.noise = Adamar::make( src.noise );
    res.shift = Adamar::make( src.shift );

    res.origin = res.origin / qPow( src.size, 2);
    res.noise = res.noise / qPow( src.size, 2);
    res.shift = res.shift / qPow( src.size, 2);

    MatrixXd delta = res.noise - res.origin;

    MatrixXd filter = res.noise.colPivHouseholderQr().solve( res.origin );

    //    MatrixXd adamar_21 = adamar_2 * matx.filter;
    //    MatrixXd adamar_31 = adamar_3 * matx.filter;

    //    adamar_21 = adamar_21.unaryExpr( []( const double val )
    //    {
    //        return double( qRound( val * 10000 ) ) / 10000 ;
    //    });

    //    adamar_31 = adamar_31.unaryExpr( []( const double val )
    //    {
    //        return double( qRound( val * 10000 ) ) / 10000 ;
    //    });

    //    cout << matx.noise << endl;
    //    cout << Adamar::reverse( adamar_31 ) << endl;

    return qapp.exec();
}

//=======================================================================================
