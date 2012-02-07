import java.util.concurrent.Semaphore;

class Factory {
   static final int NUM_PHILOSOPHERS = 5;

   public static void main(String args[]) {

      Thread philosophers[] = new Thread[NUM_PHILOSOPHERS];

      Semaphore chopstick[] = new Semaphore[NUM_PHILOSOPHERS];

      for (int i = 0; i < NUM_PHILOSOPHERS; i++)
         chopstick[i] = new Semaphore(1);

      for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
         philosophers[i] = new Thread(new Philosopher(i, NUM_PHILOSOPHERS,
                                      chopstick));
         philosophers[i].start();
      }
   }
}
