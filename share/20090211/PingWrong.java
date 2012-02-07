/* author: Perugini */

public class PingWrong implements Runnable {

    int i;

    public void run() {
        if ((i % 2) == 0) {
           System.out.println("ping");
        } else {
             System.out.println("pong");
          }
    }

    public PingWrong(int i) {
       this.i = i;
    }

    public static void main(String args[]) {
       System.out.println("Main Thread " + Thread.currentThread().getId());
       for (int i=0; i < 20; i++) {
          Thread t = new Thread(new PingWrong(i));
          System.out.print("Thread " + t.getId() + ": ");
          t.start();
       }
    }
}
