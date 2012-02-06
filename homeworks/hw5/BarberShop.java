/*******************************************************************************
/
/      filename:  BarberShop.java
/
/   description: This program creates a BarberShop class that solves the Sleeping 
/                Barber syncronization problem using semaphores. 
/
/        author:  Paladino, Zac
/      login id:  cps346-01.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  Homework #5
/
/      assigned:  March 10, 2009
/           due:  March 17, 2009
/
/******************************************************************************/

import java.util.concurrent.Semaphore;

class BarberShop {

   Semaphore empty;
   Semaphore mutex;
   int chr;

   BarberShop( int chairs ) {
      mutex = new Semaphore(1);
      empty = new Semaphore(chairs);
      chr = chairs;
   }

   void customerEnters(int id) {
      if(empty.availablePermits() > 0){
        try{empty.acquire();} catch(InterruptedException e) { }
        try {mutex.acquire(); } catch (InterruptedException e) { }
        empty.release();
        service(id);
        mutex.release();
      }
      else{
       System.out.println("Customer " + id + " left");
      }  

   }

   private void service(int id) {
      System.out.println ("Customer " + id + " is being serviced.");
      SleepUtilities.nap();
      System.out.println ("Customer " + id + " is done being serviced.");
   }
}
