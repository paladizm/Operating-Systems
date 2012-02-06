/*******************************************************************************
/
/      filename:  Factory.java
/
/   description:  This is the factory class that creates worker threads for
/		  the barrier class. 
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
class Factory {
   static final int NUM_WORKERS = 10;

   public static void main(String args[]) {
      Barrier wall = new Barrier(NUM_WORKERS);

      for (int i = 0; i < NUM_WORKERS; i++) {
         System.out.println ("Worker " + i + " just started");
         (new Thread(new Worker(i, wall))).start();
      }
   }
}
