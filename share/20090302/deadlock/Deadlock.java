// author: Perugini 

import java.util.concurrent.*;

class Thread1 implements Runnable {
   Semaphore s;
   Semaphore q;
   int id;

   Thread1 (int id, Semaphore s, Semaphore q) {
      this.id = id;
      this.s = s;
      this.q = q;
   }

   public void run() {
      System.out.println ("Thread " + id + " is running.");
      try { s.acquire(); } catch (InterruptedException ie) { }
      try { Thread.sleep((int) 5*1000); } catch (Exception e) { }
      try { q.acquire(); } catch (InterruptedException ie) { }
      System.out.println ("Thread " + id + " is in its critical section.");
      s.release();
      q.release();
   }
}

class Thread2 implements Runnable {
   Semaphore s;
   Semaphore q;
   int id;

   Thread2 (int id, Semaphore s, Semaphore q) {
      this.id = id;
      this.s = s;
      this.q = q;
   }

   public void run() {
      System.out.println ("Thread " + id + " is running.");
      try { q.acquire(); } catch (InterruptedException ie) { }
      try { Thread.sleep((int) 5*1000); } catch (Exception e) { }
      try { s.acquire(); } catch (InterruptedException ie) { }
      System.out.println ("Thread " + id + " is in its critical section.");
      q.release();
      s.release();
   }
}

class Deadlock {
   public static void main (String args[]) {

      Semaphore s = new Semaphore(1);
      Semaphore q = new Semaphore(1);

      (new Thread(new Thread1(1, s, q))).start();
      (new Thread(new Thread2(2, s, q))).start();

   }
}
