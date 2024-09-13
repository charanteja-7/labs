


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>


void print_indentation(int depth) {

    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
}


char* construct_new_path(const char *path, const char *name) {
    size_t path_len = strlen(path);
    size_t name_len = strlen(name);
    char *new_path = malloc(path_len + name_len + 2); 
    if (new_path == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    strcpy(new_path, path);
    strcat(new_path, "/");
    strcat(new_path, name);

    return new_path;
}


void display(const char *path, int depth) {
    struct dirent *d;
    DIR *dirp = opendir(path);	

    if (dirp == NULL) {
        perror("opendir error");
        return;
    }

    print_indentation(depth);
    printf("%s:\n", path);

    while ((d = readdir(dirp)) != NULL) {

        if (d->d_name[0] == '.') {
            continue;
        }

        print_indentation(depth);

        if (d->d_type == DT_DIR) {
            printf("%s/\n", d->d_name);

            char *new_path = construct_new_path(path, d->d_name);

            display(new_path, depth + 1);

            free(new_path);
        } else if (d->d_type == DT_REG) {
            printf(" %s\n", d->d_name);
        }
    }

    closedir(dirp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    display(argv[1], 0);

    return EXIT_SUCCESS;
}
/*output 
dir:
 file.txt
 file1.txt
lp1/
    dir/lp1:
     lp1file1.txt
     lp2file2.txt
lp3/
    dir/lp3:
lp2/
    dir/lp2:
    folder1/
        dir/lp2/folder1:
         file.txt
        folder11/
            dir/lp2/folder1/folder11:
             file2.txt
             file1.txt
     lp2file1.txt
*/
