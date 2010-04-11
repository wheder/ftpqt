#include "reqqueue.h"
instance = null;

ReqQueue ReqQueue::getReqQueue(int length);
{
    if(instance==null)
    {
       instance = new ReqQueue(length);
    }
    return instance;
}

ReqQueue ReqQueue::getReqQueue();
{
    if(instance==null)
    {
        return new ReqQueue(50);
    }
    return instance;
}

ReqQueue::ReqQueue(int length)
{
    queue = new QQueue<QueueItem>();
    priorityQueue = new QQueue<QueueItem>();
    size = length;
    count = 0;
    countPriority = 0;
    countNormal = 0;
    priorityServed = 0;
}

void ReqQueue::enque(QueueItem in)
{
    emit entry;

    if(ReqQueue::isFull()){
        if(in.isSimpleCommand())//doimplementovat
        {
            priorityQueue.enqueue(in);
            countPriority++;
        } else {
            queue.enqueue(in);
            countNormal++;
        }
    } else {
        // Nemela by nastat, protoze, prijem connectionu by mel hlidat, jestli uz neni plno. Radsi ji tu ale nechavam.
        // throw Exception("Full queue.");
        // Reseni pomoci signalu.
        emit full();
    }
    count++;
}

QueueItem ReqQueue::dequeue()
{
    emit entry;
    if(!ReqQueue::isEmpty()){
        if(!priorityQueue.isEmpty() && (!queue.isEmpty() && priorityServed<=10))
        {
            priorityQueue.dequeue();
            priorityServed++;
            countPriority--;
        } else {
            queue.dequeue();
            priorityServed = 0;
            countNormal--;
        }
    } else {
        // throw Exception("Empty queue.");
        // Reseni pomoci signalu.
        emit empty();
    }
    count--;
}

QueueItem ReqQueue::headSimpleCommands()
{
    if(!priorityQueue.isEmpty())
    {
        priorityQueue.head();
    } else {
        //throw Exception("Empty queue.");
        emit empty();
    }
}

QueueItem ReqQueue::headFiles()
{
    if(!queue.isEmpty())
    {
        queue.head();
    } else {
        //throw Exception("Empty queue.");
        emit empty();
    }
}

QueueItem ReqQueue::onPosition(bool queueIdentificator, unsigned int index)
{
    if(queueIdentificator==false){
        if(!queue.isEmpty())
        {
            if(index > countNormal){
                std::cout <<"Index out of bounds, return pointer to last item." << std::endl;
                return queue.back();
            } else {
                return queue.at(index);
            }
        } else {
            //throw Exception("Empty queue.");
            emit empty();
        }
    } else {
        if(!priorityQueue.isEmpty())
        {
            if(index > countPriority){
                std::cout <<"Index out of bounds, return pointer to last item." << std::endl;
                return priorityQueue.back();
            } else {
                return priorityQueue.at(index);
            }
        } else {
            //throw Exception("Empty queue.");
            emit empty();
        }

    }
}

bool ReqQueue::isEmpty()
{
    return queue.isEmpty() && priorityQueue.isEmpty();
}

bool ReqQueue::isFull(){
    // Necham kontrolu na size o 1 mensi, aby se mel nedokonceny pozadavek kam vratit (snad jich nebude vice
    // pri maximalne plne front).
    return count == size-1;
}
