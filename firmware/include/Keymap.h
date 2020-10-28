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

#define LEFT_HAND_SIZE (sizeof(LEFT_HAND) / sizeof(char))

#endif