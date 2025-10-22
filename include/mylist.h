/*
** EPITECH PROJECT, 2025
** my_list.h
** File description:
** None
*/

#ifndef _MY_LIST_H
    #define _MY_LIST_H

typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;

#endif
