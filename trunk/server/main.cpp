#include <QtCore/QCoreApplication>
#include <iostream>
#include "reqqueue.h"

void choice(QString command, char* argv, bool started);
void inicialize(int length);
// argv obsahuje velikost fronty a pocet serve-vlaken
int main(int argc, char *argv[])
{

    bool go = true;
    bool started = false;
    QString command = QString::null;
    std::cout << "Server is ready to start." << std::endl;
    while(go)
    {
        std::cin << command.unicode();
        std::cout << std::endl;
        choice(command, *argv, started);
    }

}

void choice(QString command, char* argv, bool started)
{
    if(command.contains("start",Qt::CaseInsensitive))
    {
        if(!started)
        {
            inicialize(*(argv+1));
            std::cout << "Server started and listen on port 21." << std::endl;
        }
    } else {
        std::cout << "Unknown command." << std::endl;
    }
}

void inicialize(int length)
{
    // 1) vytvorit frontu argv[2]
    ReqQueue requestsQueue = ReqQueue::getReqQueue(100);
    // 2) listen thread na portu 21
        //ListenThread lt = new ListenThread();
    // 3) prijimaci thread
    //AcceptionThread at;
    //at = AcceptionThread.getAcceptionThread(requestsQueue);
    // 4) nejaky threadpool serve thread
}
