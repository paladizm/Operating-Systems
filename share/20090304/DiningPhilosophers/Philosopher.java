import java.lang.Math;
import java.util.concurrent.Semaphore;

class Philosopher implements Runnable {

   int id;
   static int num_philosophers;

   Semaphore[] chopstick;

   Philosopher (int id, int num_philosophers,
                Semaphore chopstick[]) {
      this.id = id;
      this.num_philosophers = num_philosophers;
      this.chopstick = chopstick;
   }

   public void run() {
      System.out.println ("Philosopher " + id + " just started.");

      while (true) {
         // pick up left chopstick
         try { chopstick[id].acquire(); } catch (InterruptedException ie) { }

         // pick up right chopstick
         try { chopstick[(id+1) % num_philosophers].acquire(); }
         catch (InterruptedException ie) { }

         eat();

         // put down left chopstick
         chopstick[id].release();

         // put down right chopstick
         chopstick[(id+1) % num_philosophers].release();

         // think
      }
   }

   private void eat() {
      System.out.println ("Philosopher " + id + " is eating.");
   }
}
