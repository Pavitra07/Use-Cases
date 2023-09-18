/*In this experiment, we have one victim main thread, one victim encryption thread having AES 192, one complex code*/

#include <stdio.h>
#include <string.h>
#include <zephyr.h>
#include <time.h>
#include <sys/printk.h>
#include <timing/timing.h>
#include "aes.c"
#include "comp_4.c"





void main(void)
{

      
// start the encryption function as a seperate thread
K_THREAD_DEFINE(my_victim_thread, MY_STACK_SIZE,
                Cipher, &state, &RoundKey, NULL,
                MY_PRIORITY, 0, 0);
K_THREAD_DEFINE(my_benchmark1_thread1, MY_STACK_SIZE,
                do_comp_4, NULL,NULL,NULL,
                MY_PRIORITY, 0, 0);
    // Encrypt the message
    k_thread_start(my_victim_thread);
    k_thread_start(my_benchmark1_thread1);
                

return 0;
}