

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   
    char *args[] = {"ls", "-l", NULL};
    printf("Before execvp()\n");
    execvp("ls", args);
    perror("execvp failed");
    return 1;
}
/*output

Before execvp()
total 48
-rwxrwxr-x 1 cvr cvr 16832 Aug 30 16:29 a.out
-rw-rw-r-- 1 cvr cvr   435 Aug 30 16:17 dup2.c
-rw-rw-r-- 1 cvr cvr   458 Aug 30 16:07 dup.c
-rw-r--r-- 1 cvr cvr    13 Aug 30 16:07 example.txt
-rw-rw-r-- 1 cvr cvr   219 Aug 30 16:29 exec.c
-rw-rw-r-- 1 cvr cvr   486 Aug 30 16:24 fork.c
-rw-r--r-- 1 cvr cvr    35 Aug 30 16:08 output.txt
-rw-rw-r-- 1 cvr cvr   664 Aug 30 16:25 vfork.c

*/
