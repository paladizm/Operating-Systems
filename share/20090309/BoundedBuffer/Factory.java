class Factory {
   
   public static void main(String args[]) {

      Buffer buffer = new BoundedBuffer();

      // now create the producer and consumer threads
      Thread producer = new Thread (new Producer(buffer));
      Thread consumer = new Thread (new Consumer(buffer));

      producer.start();
      consumer.start();
   }
}
