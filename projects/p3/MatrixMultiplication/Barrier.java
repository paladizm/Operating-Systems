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


