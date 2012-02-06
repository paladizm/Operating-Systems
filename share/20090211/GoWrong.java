/* author: Perugini */

class GoWrong implements Runnable {

   private Buffer buf = null;

   GoWrong (Buffer b) {
      buf = b;
   }

   public void run() {

      if (buf.buffer == 'e')
         buf.buffer = 'g';
      else 
         if (buf.buffer == 'g')
            System.out.println (buf.buffer);
   }

   public static void main(String args[]) {
      Buffer buf = new Buffer();

      (new Thread(new GoWrong(buf))).start();
      (new Thread(new GoWrong(buf))).start();
   }
}

class Buffer {
   public char buffer = 'e';
}
