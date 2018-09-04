#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
/*#include <sys/types.h>*/

int get_offset(int fd){
    int offset;
    lseek(fd, 10, SEEK_SET);
    read(fd, &offset, 4);
    return (offset);
}

void insert_size(int fd, unsigned int size){
    unsigned char buffer;
    int i = 15;

    while (i >= 0){
        read(fd, &buffer, 1);
        buffer = (buffer & 252) | ((size >> (i * 2)) & 3);
        lseek(fd, -1, SEEK_CUR);
        write(fd, &buffer, 1);
        i--;
    }
}

void insert_msg(int fd, char *msg){
    unsigned int i = 0;
    unsigned int ind_msg = 0;
    unsigned char buffer;

    while (ind_msg < strlen(msg)){
        read(fd, &buffer, 1);
        ind_msg = (int) (i / 4);
        buffer = (buffer & 252) | ((msg[ind_msg] >> ((3 - (i % 4)) * 2)) & 3);
        lseek(fd, -1, SEEK_CUR);
        write(fd, &buffer, 1);
        i++;
    }
}

int main(int argc, char **argv){
    int fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH);
    char *msg;
    int offset;

    if (fd == -1){
        printf("Erreur lors de l'ouverture du fichier\n");
        return (-1);
    }
    offset = get_offset(fd);
    lseek(fd, offset, SEEK_SET); //Move on the begin of pixels array;

    msg = calloc(strlen(argv[2]) + 1, sizeof(char));
    if (msg == NULL){
        printf("Erreur lors de l'allocation memoire\n");
        return (-1);
    }
    strcpy(msg, argv[2]);
    
    insert_size(fd, strlen(msg));
    insert_msg(fd, msg);

    free(msg);    
    close(fd);
    return (0);
}
