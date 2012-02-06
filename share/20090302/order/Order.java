// author: Perugini

import java.util.concurrent.*;

class Thread1 implements Runnable {
   Semaphore sem;
   int id;

   Thread1 (int id, Semaphore sem) {
      this.id = id;
      this.sem = sem;
   }

   public void run() {
      System.out.println ("Thread " + id + ": must print before T2.");
      sem.release();
   }
}

class Thread2 implements Runnable {
   Semaphore sem;
   int id;

   Thread2 (int id, Semaphore sem) {
      this.id = id;
      this.sem = sem;
   }

   public void run() {
      try { sem.acquire(); } catch (InterruptedException ie) { }
      System.out.println ("Thread " + id + ": must print after T1.");
   }
}

class Order {
   public static void main (String args[]) {

      Semaphore sem = new Semaphore(0);

      (new Thread(new Thread1(1, sem))).start();
      (new Thread(new Thread2(2, sem))).start();

   }
}
