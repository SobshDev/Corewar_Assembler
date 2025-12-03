/*
** EPITECH PROJECT, 2025
** RobotFactory
** File description:
** my_putnbr_err
*/

#include <unistd.h>

void my_putnbr_err(int n)
{
    long num;
    char digit;

    num = n;
    if (num < 0) {
        write(2, "-", 1);
        num = -num;
    }
    if (num >= 10)
        my_putnbr_err(num / 10);
    digit = (num % 10) + '0';
    write(2, &digit, 1);
}
