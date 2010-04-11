#ifndef REQQUEUE_H
#define REQQUEUE_H

#include <QQueue>
#include <QObject>
#include <exception>
#include "queueitem.h"

/**
  * Header file of class representing priority queue for ftp requests. Simple requests like
  * USER, LIST, NOOP, etc. are removed earlier than request for FILE. Alternating of simple
  * and FILE commands is secured by counter of removed items from priority queue. After 10
  * simple commands in one line will remove 1 item from FILE queue. Queue has limited size.
  * Queue also can show first item in both queues or on specified index.
  */
class ReqQueue : public QObject
{
    Q_OBJECT

public:
    /**
      * Getter for creating / getting single instance of queue with preffered length.
      */
    static ReqQueue getReqQueue(int length);
    /**
      * Getter for creating / getting single instance of queue with 50 items length.
      */
    ReqQueue getReqQueue();
    /**
      * Put QueueItem to back of queue. Simple FTP commands are putted to priority queue.
      */
    void enque(QueueItem in);
    /**
      * Remove QueueItem from queue. First from priorityQueue then from normal queue.
      * If count of removed QueueItem from priorityQueue is more than 10, next removed
      * will be from normal queue.
      */
    QueueItem deque();
    /**
      * Return poiter to first QueueItem in priorityQueue with simple commands.
      */
    QueueItem headSimpleCommands();
    /**
      * Return poiter to first QueueItem in normal queue with requests for file.
      */
    QueueItem headFiles();
    /**
      * Return poiter in priority or normal queue on index. Values of queueIdentificator are
      * 0 - normal queue and 1 - priority queue. Value of index is from 0 to count of specified
      * queue(found by countItems(bool queueIdentificator)). If inserted index is out of bounds
      * function will return last item.
      */
    QueueItem onPosition(bool queueIdentificator, unsigned int index);
    /**
      * Testing that both queues are empty.
      */
    bool isEmpty();
    /**
      * Testing that queue can accept new item. Specially for accepting new incoming
      * connection and for return uncompleted file-send request.
      */
    bool isFull();
    /**
      * Return count of items in specified queue. Values of queueIdentificator are 0 - normal
      * queue and 1 - priority queue.
      */
    int countItems(bool queueIdentificator);

public slots:

signals:
    /**
      * Signal report full queue.
      */
    void full();
    /**
      * Signal report empty queue.
      */
    void empty();
    /**
      * Signal indicates that any thread is working with queue.
      */
    void entry();

private:
    /**
      * Private constructor of singleton class ReqQueue. Create one instance of queue with preffered
      * length.
      */
    ReqQueue(int length);
    /**
      * Static pointer to single instance of ReqQueue.
      */
    static ReqQueue instance;
    /**
      * Store queue of QueueItems contains simple FTP commands, e.g. LIST.
      */
    QQueue<QueueItem> priorityQueue;
    /**
      * Store queue of QueueItems contains requests for file.
      */
    QQueue<QueueItem> queue;
    /**
      * Size of all queue.
      */
    unsigned size;
    /**
      * Count of requests in queues together.
      */
    unsigned int count;
    /**
      * Count of requests in priority queue.
      */
    unsigned int countPriority;
    /**
      * Count of requests in normal queue.
      */
    unsigned int countNormal;
    /**
      * Max count of priority request which are served before take one normal request.
      */
    unsigned int priorityServed;
};

#endif // REQQUEUE_H
