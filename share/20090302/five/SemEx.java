// author: Perugini

import java.util.concurrent.*;

class Worker implements Runnable {
   private Semaphore sem;
   private String name;

   Worker (Semaphore sem, String name) {
      this.sem = sem;
      this.name = name;
   }

   public void run() {

      while (true) {
         try { sem.acquire(); } catch (InterruptedException ie) { }
         //MutualExclusionUtilities.criticalSection(name);

         System.out.println ("Thread " + name + " is in its critical section");
         try { Thread.sleep((int) Math.random()*1000); }
         catch (InterruptedException ie) { }
         System.out.println ("Thread " + name + " is still in its critical section");

         sem.release();

         //MutualExclusionUtilities.remainderSection(name);
         System.out.println ("Thread " + name + " is in its remainder section");
      }
   }
}

class SemEx {
   public static void main (String args[]) {

      Semaphore sem = new Semaphore(3);

      Thread[] bees = new Thread[5];

      for (int i=0; i < 5; i++)
         bees[i] = new Thread (new Worker (sem,
                               "Worker " + (new Integer(i)).toString()));

      for (int i=0; i < 5; i++)
         bees[i].start();
   }
}
