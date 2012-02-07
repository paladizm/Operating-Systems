/*******************************************************************************
/
/      filename:  Barrier.java
/
/   description:  This is the Barrier monitor class. 
/
/        author:  Paladino, Zac
/      login id:  cps346-n1.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  PJ #3
/
/      assigned:  March 11, 2009
/           due:  April 15, 2009
/
/******************************************************************************/
import java.util.concurrent.*;
import java.util.concurrent.locks.*;

class Barrier{
    int NumWait, NumCount;
    Condition workers;
    Lock lock; 
    Barrier(int num){
      lock = new ReentrantLock();
      NumWait = num;
      workers = lock.newCondition();

     }
    public void waitForOthers(){
      lock.lock();
      NumCount++;
      if(NumCount == NumWait){
        workers.signalAll();
        NumCount = 0;
      }
      else{
        try{workers.await();}catch(InterruptedException e){}
      }
      lock.unlock();
     }
}
    
