#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_file_info(const char *filename) {
    struct stat file_stat;
    
    // Get file status
    if (stat(filename, &file_stat) != 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // File type and permissions
    printf(S_ISDIR(file_stat.st_mode) ? "d" : "-");
    printf((file_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf((file_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf((file_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf((file_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf((file_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf((file_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf((file_stat.st_mode & S_IROTH) ? "r" : "-");
    printf((file_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf((file_stat.st_mode & S_IXOTH) ? "x" : "-");
    printf(" ");

    // Number of links
    printf("%lu ", file_stat.st_nlink);

    // Owner
    struct passwd *pwd = getpwuid(file_stat.st_uid);
    if (pwd != NULL) {
        printf("%s ", pwd->pw_name);
    } else {
        printf("%d ", file_stat.st_uid);
    }

    // Group
    struct group *grp = getgrgid(file_stat.st_gid);
    if (grp != NULL) {
        printf("%s ", grp->gr_name);
    } else {
        printf("%d ", file_stat.st_gid);
    }

    // Size
    printf("%ld ", file_stat.st_size);

    // Modification time
    char time_buf[20];
    struct tm *tm_info = localtime(&file_stat.st_mtime);
    strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", tm_info);
    printf("%s ", time_buf);

    // File name
    printf("%s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_file_info(argv[1]);
    return EXIT_SUCCESS;
}
