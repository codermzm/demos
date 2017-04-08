#include "ReqHistory.h"


QString ReqHistory::getParams()
{
    return this->params;
}

QString ReqHistory::getResponse( )
{
    return this->response;
}

QString ReqHistory::getUrl( )
{
    return this->url;
}


void ReqHistory::setParams( QString str )
{
    this->params = str;
}

void ReqHistory::setResponse( QString str )
{
    this->response = str;
}

void ReqHistory::setUrl( QString str )
{
    this->url = str;
}
