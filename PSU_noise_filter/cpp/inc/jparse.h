#ifndef JPARSE_H
#define JPARSE_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "defs.h"

//=======================================================================================

class JParse
{
public:

    static Signal json_parse( const std::string& name );

    //-----------------------------------------------------------------------------------

private:

    static Eigen::MatrixXd cvt_arr_to_ematxd( const QJsonArray& mat, const int size );

};

//=======================================================================================

#endif // JPARSE_H
