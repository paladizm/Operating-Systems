public class Factory {

   public static final int NUM_OF_CHAIRS = 10;
   public static final int NUM_OF_CUSTOMERS = 100;

   public static void main(String args[]) {
      BarberShop barbershop = new BarberShop(NUM_OF_CHAIRS);

      for (int i = 0; i < NUM_OF_CUSTOMERS; i++) {
         (new Thread(new Customer(i, barbershop))).start();
         SleepUtilities.nap();
      }
   }
}
