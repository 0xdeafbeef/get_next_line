#include <printf.h>
#include "get_next_line.h"

void free_m(char **b, char **c) {
    free(*b);
    free(*c);
    *b = 0x0;
    *c = 0x0;
}

void init(char **strg, char **cr_line, char **redd, int *resp) {
    *redd = ft_strnew(BUFF_SIZE);
    *cr_line = ft_strnew(BUFF_SIZE);
    if (*strg == 0x0)
        *strg = ft_strnew(0);
    *resp = 1;
}

char *parse_and_cut(char **stor, char **cr_line, char **redd) {
    char *temp;

    temp = ft_strjoin(*cr_line, *redd);
    free_m(redd, cr_line);
    *cr_line = ft_strjoin(*stor, temp);
    free_m(stor, &temp);
    *stor = ft_strdup(*cr_line);
    free(*cr_line);
    temp = ft_strcopy_until(*stor, '\n');
    if (ft_strchr(*stor, '\n') != 0x0) {  // if \n exists cut it
        *cr_line = ft_strsub(ft_strchr(*stor, '\n'),1,ft_strlen(ft_strchr(*stor, '\n')));
        free(*stor);
        *stor = ft_strdup(*cr_line);
        free(*cr_line);
    }
    return (temp);
}

int get_next_line(const int fd, char **line) {
    static char *storage[590432];
    char *cr_line;
    char *redd;
    char *temp;
    int response;

    if (fd == -1)
        return -1;
    init(&storage[fd], &cr_line, &redd, &response);
    if (ft_strchr(storage[fd], '\n') == 0x0)  // just reading until \n is met
        while (ft_strchr(storage[fd], '\n') == 0x0 && (response = (int) read(fd, redd, BUFF_SIZE)) != 0 &&
               ft_strchr(redd, 10) == 0x0) {
            temp = ft_strdup(cr_line);
            free(cr_line);
            cr_line = ft_strjoin(temp, redd);
            free(temp);
        }
    if (response == 0)
    {
        free_m(&cr_line, &redd);
        free(storage[fd]);
        return 0;
    }
    *line = parse_and_cut(&storage[fd], &cr_line, &redd);
    return 1;
}
int main() {
    char *ch;
    int fg = open("sec", O_RDONLY);
    int fd = open("frst", O_RDONLY);
//    while (get_next_line(fg, &ch)>0) {
//        printf("%s\n", ch);
//    }
    get_next_line(fd, &ch);
    printf("frsr->     %s\n", ch);

    get_next_line(fg, &ch);
    printf("sec>       %s\n", ch);

    get_next_line(fd, &ch);
    printf("frst-->    %s\n", ch);

    get_next_line(fg, &ch);
    printf("sec->      %s\n", ch);

    get_next_line(fd, &ch);
    printf("frsr->     %s\n", ch);

    get_next_line(fg, &ch);
    printf("sec>       %s\n", ch);

    get_next_line(fd, &ch);
    printf("frst-->    %s\n", ch);

    get_next_line(fg, &ch);
    printf("sec->      %s\n", ch);

    
}