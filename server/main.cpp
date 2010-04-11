#include <QtCore/QCoreApplication>
#include <iostream>
#include "acceptionthread.h"
#include "reqqueue.h"

// argv obsahuje velikost fronty a pocet serve-vlaken
int main(int argc, char *argv[])
{

    bool go = true;
    bool started = false;
    QString command = null;
    std::cout << "Server is ready to start." << std::endl;
    while(go)
    {
        std::cin << command;
        std::cout << std::endl;
        choice(command);
    }

}

void choice(QString command)
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

void start()
{
    // 1) vytvorit frontu argv[2]
    ReqQueue requestsQueue = new ReqQueue(100);
    // 2) listen thread na portu 21
        //ListenThread lt = new ListenThread();
    // 3) prijimaci thread
    AcceptionThread at;
    at = AcceptionThread.getAcceptionThread(requestsQueue);
    //nejaky threadpool
}
