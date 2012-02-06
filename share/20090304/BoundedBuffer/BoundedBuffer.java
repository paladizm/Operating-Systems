import java.util.concurrent.Semaphore;

class BoundedBuffer implements Buffer {

   static final int BUFFER_SIZE = 5;
   Object[] buffer;
   int in, out;
   
   Semaphore mutex;
   Semaphore empty;
   Semaphore full;

   BoundedBuffer() {
      // buffer is initially empty
      in = out = 0;

      buffer = new Object[BUFFER_SIZE];

      mutex = new Semaphore(1);
      empty = new Semaphore(BUFFER_SIZE);
      full = new Semaphore(0);
   }

   public void insert (Object item) {
      try { empty.acquire(); } catch (InterruptedException e) { }
      try { mutex.acquire(); } catch (InterruptedException e) { }

      // add an item to the buffer
      // critical section
      buffer[in] = item;
      in = (in + 1) % BUFFER_SIZE;
      System.out.println ("Producer just produced an item.");
      System.out.println ("in: " + in);

      mutex.release();
      full.release();
   }

   public Object remove() {
      try { full.acquire(); } catch (InterruptedException e) { }
      try { mutex.acquire(); } catch (InterruptedException e) { }

      // remove an item to the buffer
      // critical section
      Object item = buffer[out];
      out = (out + 1) % BUFFER_SIZE;
     
      System.out.println ("Consumer just consumed an item.");
      System.out.println ("out: " + out);

      mutex.release();
      empty.release();

      return item;
   }
}
