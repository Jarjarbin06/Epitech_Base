/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "../includes/file.h"

static size_t get_file_size(const int fd)
{
    size_t size = 0;
    char tmp[1];

    for (; read(fd, tmp, 1) == 1; size++);
    return size;
}

int file_open(file_t *file)
{
    if (!file || !file->full_path)
        return EXIT_ERROR;
    if (file->is_open)
        return EXIT_ERROR;
    file->fd = open(file->full_path, O_RDONLY);
    if (file->fd == -1)
        return EXIT_ERROR;
    file->is_open = true;
    return EXIT_SUCCESS;
}

int file_close(file_t *file)
{
    if (!file || !file->is_open)
        return EXIT_ERROR;

    close(file->fd);
    file->fd = -1;
    file->is_open = false;
    return EXIT_SUCCESS;
}

static int get_size(file_t *file, size_t *size)
{
    if (!file || !size)
        return EXIT_ERROR;
    if (file_open(file))
        return EXIT_ERROR;
    *size = get_file_size(file->fd);
    if (file_close(file))
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static int get_raw(file_t *file, const size_t size)
{
    ssize_t read_size = 0;

    if (!file)
        return EXIT_ERROR;
    if (file_open(file))
        return EXIT_ERROR;
    file->raw = malloc_any(sizeof(char) * (size + 1));
    if (!file->raw)
        return (file_close(file)) ? (EXIT_ERROR) : (EXIT_ERROR);
    read_size = read(file->fd, file->raw, size);
    if (file_close(file))
        return EXIT_ERROR;
    if (read_size != (ssize_t)size) {
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
