/*
** EPITECH PROJECT, 2025
** sources - str_putstr.c
** File description:
** <description>
*/

#include <unistd.h>

#include "../../includes/newerror.h"

int str_putstr(const char *str)
{
    if (!str)
        return E_ERROR;
    return ((write(ERR_FILE, str, str_strlen(str)) != str_strlen(str)) ?
        (E_ERROR) : (E_SUCCESS));
}
