/*******************************************************************************
/
/      filename:  Ping.java
/
/   description: This program makes 20 sequential threads in java. 
/
/        author:  Paladino, Zac
/      login id:  cps444-01.16
/
/         class:  CPS 346
/    instructor:  Perugini
/    assignment:  Homework #3
/
/      assigned:  February 5, 2009
/           due:  February 11, 2009
/
/******************************************************************************/

public class Ping implements Runnable {
    private Thread t2 = null;
    static int count = 20;
    static boolean trigger = true;
    Ping(){
       t2 = new Thread(this);
       t2.start();
    }
    public void run() {
       System.out.print("Thread " + t2.getId() + ": ");
       if(trigger){
         System.out.println("ping");
         trigger = false;
       } 
       else{
         System.out.println("pong");
         trigger = true;
       } 
       if(count > 0){  
         count--;
         new Ping();
       }
    }
    public static void main(String args[]) {
        new Ping();
    }
}
