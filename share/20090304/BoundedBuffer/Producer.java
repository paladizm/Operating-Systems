import java.util.Date;

class Producer implements Runnable {

    Buffer buffer;

    Producer (Buffer buffer) {
       this.buffer = buffer;
    }

    public void run() {
       Date message;

       while (true) {
          // nap for a while
          SleepUtilities.nap();
     
          // produce an item & put it into the buffer
          message = new Date();
          buffer.insert (message); 
       }
    }
}
