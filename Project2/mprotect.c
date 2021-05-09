#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

char *buffer;

static void
handler(int sig, siginfo_t *si, void *unused)
{
    printf("Got SIGSEGV at address: 0x%lx\n",
            (long) si->si_addr);
    exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
    char *p;
    int pagesize;
    struct sigaction sa;

   sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handler;
    if (sigaction(SIGSEGV, &sa, NULL) == -1) handle_error("sigaction");

   pagesize = sysconf(_SC_PAGE_SIZE);
    if (pagesize == -1) handle_error("sysconf");

   /* Allocate a buffer aligned on a page boundary;
       initial protection is PROT_READ | PROT_WRITE */

   buffer = memalign(pagesize, 4 * pagesize);
    if (buffer == NULL) handle_error("memalign");

    int i;
    int len = (4 * pagesize) - 1;
    buffer[len] = 0;
    for (p = buffer, i = 0 ; i < len; i++)
        *(p++) = 'a';


   printf("Start of region:        0x%lx(%c)\n", (long) buffer, *buffer);
   printf("End of region:          0x%lx(%c)\n", (long) &buffer[len-1], buffer[len-1]);

   printf("Protecting from the middle of the memory block(read-only) at:      0x%lx(%c)\n", (long) &buffer[(len+1)/2], buffer[(len+1)/2]);

    /* 
        flag 5 => PROT_READ
        mprotect(startaddr, blockLength, read/write)
    */
   if (mprotect(buffer + pagesize * 2, pagesize, 5) == -1) handle_error("mprotect");

    for (p = buffer, i = 0 ; i < len; i++)
        *(p++) = 'a';

   printf("Loop completed\n");     /* Should never happen */
    exit(EXIT_SUCCESS);
}