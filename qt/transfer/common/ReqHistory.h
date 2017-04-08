#ifndef CONFIGINFO_H
#define CONFIGINFO_H

#include <QString>

class ReqHistory
{
public:
    ConfigInfo();

    QString getUrl( );
    QString getParams( );
    QString getResponse( );

    void setUrl( QString str );
    void setParams( QString str );
    void setResponse(  QString str );

private:
    QString url;
    QString params;
    QString response;

};

#endif // CONFIGINFO_H
