
/* we would normally indent the body of conditional,
   but not permitted here */
#if vax || u3b || u3b5 || u3b2
#define MAGIC 330
#else
#define MAGIC 500
#endif

#define DEBUG hello

#ifdef LIMIT
#undef LIMIT
#endif
#define LIMIT 1000

int x=5, y = 10;

/* when return type omitted, int assumed */
f() {
   /* allowed to indent here */
/* to use debugging statements, #define DEBUG 1
   anywhere before #ifdef finds it;
   or use gcc -DDEBUG pgm.c */
#ifdef DEBUG
  printf ("x is %d\n", x);
  printf ("y is %d\n", y);
#endif
   /* allowed to indent here */
}

main() {
   f();
}
