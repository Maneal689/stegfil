#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
/*#include <sys/types.h>*/

void print_bin(unsigned char nb){
    for (unsigned int i = 0; i < 8; i++){
        printf("%d", nb >> (7 - i) & 1);
    }
    printf("\n=====\n");
}

unsigned int take_bits(int beg, unsigned int size, unsigned int nbr){
    unsigned int result = 0;
    unsigned int bits[32];

    beg %= 32;
    if (beg < 0)
        beg += 32;
    beg = (unsigned int) beg;
    if (beg + size > 32)
        return (0);
    for (unsigned int i = 0; i < 32; i++)
        bits[i] = (nbr >> (31 - i)) & 1;
    for (unsigned int i = beg; i < beg + size; i++){
        result = result << 1;
        result = result | bits[i];
    }
    return (result);
}

int get_offset(int fd){
    int offset;
    lseek(fd, 10, SEEK_SET);
    read(fd, &offset, 4);
    return (offset);
}

void insert_size(unsigned int size, unsigned char *msg){
    for (unsigned int i = 0; i < 4; i++){
        msg[i] = (unsigned char) take_bits(i * 8, 8, size);
    }
}

void insert_msg(int fd, unsigned char *msg, unsigned int msg_size){
    unsigned int ind_msg = 0;
    unsigned char buffer;

    for (unsigned int i = 0; i < msg_size * 4; i++){
        read(fd, &buffer, 1);
        ind_msg = (int) (i / 4);
        /*print_bin(msg[ind_msg]);*/
        buffer = (unsigned char)take_bits(24, 6, (unsigned int)buffer) | (unsigned char)take_bits(((i % 4) * 2) + 24, 2, (unsigned int)msg[ind_msg]);
        lseek(fd, -1, SEEK_CUR);
        write(fd, &buffer, 1);
    }
}

int main(int argc, char **argv){
    int fd = open(argv[1], O_RDWR, S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH);
    unsigned int msg_size;
    unsigned char *msg;
    int offset;

    if (fd == -1){
        printf("Erreur lors de l'ouverture du fichier\n");
        return (-1);
    }
    offset = get_offset(fd);
    lseek(fd, offset, SEEK_SET); //Move on the begin of pixels array;

    msg_size = strlen(argv[2]) + 4;
    msg = calloc(msg_size + 1, sizeof(char)); //Adding size of int to insert len of msg at the beginning
    if (msg == NULL){
        printf("Erreur lors de l'allocation memoire\n");
        return (-1);
    }

    insert_size(msg_size - 4, msg);
    for (unsigned int i = 0; i < msg_size - 4; i++)
        msg[i + 4] = argv[2][i];
    insert_msg(fd, msg, msg_size);

    free(msg);
    close(fd);
    return (0);
}
