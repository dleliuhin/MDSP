#include "jparse.h"

//=======================================================================================
Signal JParse::json_parse( const std::string& name )
{
    Signal res;

    QFile file( name.c_str() );

    if ( !file.open( QIODevice::ReadOnly | QIODevice::Text ) )
        return res;

    auto content = file.readAll();

    file.close();

    QJsonParseError error;
    auto doc = QJsonDocument::fromJson( content, &error );

    res.size = doc.object().value( "signal_size" ).toInt();

    res.origin = cvt_arr_to_ematxd( doc.object().value("clean_signal").toArray(),
                                    res.size );

    res.noise = cvt_arr_to_ematxd( doc.object().value("noise_signal").toArray(),
                                   res.size );

    res.shift = cvt_arr_to_ematxd( doc.object().value("other_signal").toArray(),
                                   res.size );

    return res;
}
//=======================================================================================


//=======================================================================================
Eigen::MatrixXd JParse::cvt_arr_to_ematxd( const QJsonArray& mat, const int size )
{
    Eigen::MatrixXd res( size, size );

    assert( mat.size() == pow( size, 2 ) );

    for ( auto i = 0; i < size; i++ )
        for ( auto j = 0; j < size; j++ )
            res( i, j ) = mat.at( size * i + j ).toDouble();

    return res;
}
//=======================================================================================
