#include "head.h"

struct connection
{
    string ip;
    int port;
    connection(string i, int p) : ip(i), port(p) {}
};

struct destination
{
    string ip;
    int port;
    destination(string i, int p) : ip(i), port(p) {}
};

connection connect(destination* pDest){
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    cout << "Creating connection(" << pConn.use_count() << ")" << endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    cout << "Connection close(" << pConn.ip << ":" << pConn.port << ")" << endl;
}

// void end_connnection(connection* pConn)
// {
//     disconnect(*pConn);
// }

void f(destination &d)
{
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn, [] (connection* p){ disconnect(*p); });
    cout << " connecting now (" << p.use_count() << ")" << endl;
}


int main(){
    destination dest("220.181.111.111", 10086);
    f(dest);

    return 0;
}