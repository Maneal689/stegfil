#ifndef FILE_H_
# define FILE_H_

typedef struct S_file{
    char *header;
    char *pixels;
    unsigned int offset;
    unsigned int size;
} t_file;

#endif //FILE_H_
