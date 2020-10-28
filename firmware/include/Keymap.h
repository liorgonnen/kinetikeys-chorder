#ifndef KEYMAP_H
#define KEYMAP_H

#define T 0x01
#define I 0x02
#define M 0x04
#define R 0x08
#define P 0x10

char LEFT_HAND[] = {
    0,
    ' ',
    't',
    'i',
    'a',
    'y',
    'x',
    'k',
    'o',
    'j',
    'g',
    0,
    'p',
    'q',
    'z',
    0,
    'd',
    0,
    '1',
    '2',
    0,
    0,
    '3',
    0,
    '4',
    0,
    '5',
    0,
    '6',
    0,
    '7',
    27, /* Esc */
};

char RIGHT_HAND[] = {
    0,
    13,  /* Enter */
    'e',
    's',
    'n',
    'c',
    'b',
    'm',
    'r',
    'w',
    'u',
    0,
    'l',
    0,
    0,
    0,
    'h',
    'f',
    'v',
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,  
};

#define LEFT_HAND_SIZE (sizeof(LEFT_HAND) / sizeof(char))
#define RIGHT_HAND_SIZE (sizeof(RIGHT_HAND) / sizeof(char))

#endif