import java.util.Date;

class Consumer implements Runnable {

    Buffer buffer;

    Consumer (Buffer buffer) {
       this.buffer = buffer;
    }

    public void run() {
       Date message;

       while (true) {
          // nap for a while
          SleepUtilities.nap();
     
          // consume an item from the buffer
          message = (Date) buffer.remove(); 
       }
    }
}
