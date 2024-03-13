#include "rsi_login.h"
#include <QApplication>
#include <QLockFile>
#include <QSharedMemory>
#define ONLY_ONE_INSTANCE "1_Single_instance_a"
#include <QDebug>
#include "mydll.h"
#include "mystaticlib.h"
#include <QSystemSemaphore>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <signal.h>

sem_t *semmem;
QSharedMemory shrdmem(ONLY_ONE_INSTANCE);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyStaticLib myslib;
    myslib.testsl();
//    QFile file1("/home/kodiak/Desktop/Vikas/documents/lock.txt");
//    if(!file1.open(QIODevice::WriteOnly|QIODevice::Text))
//    {
//        qDebug()<<"unable to open file";
//    }
//    file1.close();
    QLockFile lockfile("/home/kodiak/Desktop/Vikas/documents/lock.txt");
    if(lockfile.tryLock())
    {
        qDebug()<<"1st instance of RSI application!!!";
        rsi_login w;
        w.show();
        return a.exec();
    }
    else
    {
        qDebug()<<"Appliccation already running not allowed more than one instance!!!";
        return 1;
    }





//    if( shrdmem.create(512,QSharedMemory::ReadOnly) )
//    {
//        qDebug()<<"shared memory error : "<<shrdmem.errorString();
//        rsi_login w;
//        w.show();
//        return a.exec();
//    }
//    else
//    {
//        qDebug()<<"vikas, shared memory already created!!,\n "
//                  "Appliccation already running not allowed more than one instance!!! ";
//        return 1;
//    }

}

