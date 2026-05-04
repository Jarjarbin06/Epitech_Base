/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include <stdio.h>

#include "../includes/file.h"

static size_t get_file_size(FILE *fp)
{
    size_t size = 0;
    char tmp[1];

    for (; fread(tmp, 1, 1, fp) == 1; size++);
    return size;
}

int file_open(file_t *file)
{
    if (!file || !file->full_path)
        return EXIT_ERROR;
    if (file->is_open)
        return EXIT_ERROR;
    file->fd = fopen(file->full_path, "r");
    file->is_open = true;
    return EXIT_SUCCESS;
}

int file_close(file_t *file)
{
    if (!file)
        return EXIT_ERROR;
    if (!file->is_open)
        return EXIT_ERROR;
    fclose(file->fd);
    file->fd = 0;
    file->is_open = false;
    return EXIT_SUCCESS;
}

static int get_size(file_t *file, size_t *size)
{
    if (!file)
        return EXIT_ERROR;
    if (file_open(file))
        return EXIT_ERROR;
    *size = get_file_size(file->fd);
    file_close(file);
    return EXIT_SUCCESS;
}

static int get_raw(file_t *file, const size_t size)
{
    size_t read_size = 0;

    if (!file)
        return EXIT_ERROR;
    if (file_open(file))
        return EXIT_ERROR;
    file->raw = malloc_any(sizeof(char) * (size + 1));
    if (!file->raw) {
        fclose(file->fd);
        return EXIT_ERROR;
    }
    read_size = fread(file->raw, 1, size, file->fd);
    file_close(file);
    if (read_size != size) {
        file->raw = free_any(file->raw);
        return EXIT_ERROR;
    }
    file->raw[size] = '\0';
    return EXIT_SUCCESS;
}

int file_load(file_t *file)
{
    size_t size = 0;

    if (!file)
        return EXIT_ERROR;
    if (get_size(file, &size))
        return EXIT_ERROR;
    if (get_raw(file, size))
        return EXIT_ERROR;
    file->size = size;
    return EXIT_SUCCESS;
}
