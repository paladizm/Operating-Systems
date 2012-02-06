class Customer implements Runnable {

   int id;
   BarberShop barbershop;

   Customer (int id, BarberShop barbershop) {
      this.id = id;
      this.barbershop = barbershop;
   }

   public void run() {
      barbershop.customerEnters(id);
   }
}
