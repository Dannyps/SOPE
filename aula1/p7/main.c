 #include <stdio.h>
 #include <stdlib.h>

 void bye(void)
 {
   printf("1-- prepping\n");
   exit(-9);
   print("1-- That was all, folks\n");
 }

 void bye2(void)
 {
    printf("2-- prepping\n");
    //exit(-9);
    printf("2-- That was all, folks\n");
 }

 int
 main(void)
 {
     long a;
     int i;

     printf("Setting eh 1.\n");
     i = atexit(bye);
     if (i != 0) {
         fprintf(stderr, "cannot set exit function\n");
         exit(EXIT_FAILURE);
     }

     printf("Setting eh 2.\n");
     i = atexit(bye2);
     if (i != 0) {
         fprintf(stderr, "cannot set exit function\n");
         exit(EXIT_FAILURE);
     }
     printf("%d\n", i);
     getc(stdin);

     exit(EXIT_FAILURE);

     exit(EXIT_SUCCESS);
 }
