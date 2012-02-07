public class ThrEx implements Runnable {

    public void run() {
       System.out.println("I am a thread,");
       System.out.println("and am still running,");
       System.out.println("and still running.");
    }

    public static void main(String args[]) {
       //Thread t = new Thread(new ThrEx());
       //System.out.print("Thread " + t.getId() + ": ");
       (new Thread(new ThrEx())).start();
       (new Thread(new ThrEx())).start();
       (new Thread(new ThrEx())).start();
       (new Thread(new ThrEx())).start();
       (new Thread(new ThrEx())).start();
    }
}
