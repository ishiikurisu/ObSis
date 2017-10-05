#ifndef HELP_H
#define HELP_H

void print_bits_in_char(char c)
{
    int i = 0;
    printf("%c: ", c);
    for (i = 7; i >= 0; --i)
    {
        printf("%c", ((c >> i) & 0x1)? '1' : '0');
    }
    printf("\n");
}

void print_bits_in_int(int d)
{
    int i = 0;
    printf("%d: ", d);
    for (i = 15; i >= 0; --i)
    {
        printf("%c", ((d >> i) & 0x1)? '1' : '0');
    }
    printf("\n");
}

#endif
