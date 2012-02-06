/*******************************************************************************
/
/      filename:  Philosophers.java
/
/   description:  This is the philosophers thread that implements the dining
/                  philosophers monitor. 
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
class Philosophers implements Runnable{
     int id;
     DiningPhilosophersMonitor Monitor;
     private static final int NAP_TIME = 5;

     
     Philosophers (int nid, DiningPhilosophersMonitor M){
          this.id = nid;
          this.Monitor = M;
      }
     
     public void run() {
          System.out.println("Philosopher " + id + " just started.");
          
          while(true){
              Monitor.pickupForks(id);
              eat();
              Monitor.releaseForks(id); 
              nap();
         }
     }
     
     private void eat(){
          System.out.println("Philosopher " + id + " just ate.");
      }

     static void nap() {
         nap(NAP_TIME);
      }
     static void nap(int duration) {
         int sleeptime = (int) (duration * Math.random() );
         try { Thread.sleep(sleeptime*1000); } catch (InterruptedException ie) {}
     }
} 
