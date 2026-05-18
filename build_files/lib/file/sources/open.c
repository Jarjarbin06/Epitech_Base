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
        return E_ERROR;
    if (file->is_open)
        return E_ERROR;
    file->fd = open(file->full_path, O_RDONLY);
    if (file->fd == -1)
        return E_ERROR;
    file->is_open = true;
    return E_SUCCESS;
}

int file_close(file_t *file)
{
    if (!file || !file->is_open)
        return E_ERROR;
    close(file->fd);
    file->fd = -1;
    file->is_open = false;
    return E_SUCCESS;
}

static int get_size(file_t *file, size_t *size)
{
    if (!file || !size)
        return E_ERROR;
    if (file_open(file))
        return E_ERROR;
    *size = get_file_size(file->fd);
    if (file_close(file))
        return E_ERROR;
    return E_SUCCESS;
}

static int get_raw(file_t *file, const size_t size)
{
    ssize_t read_size = 0;

    if (!file)
        return E_ERROR;
    if (file_open(file))
        return E_ERROR;
    file->raw = malloc_any(sizeof(char) * (size + 1));
    if (!file->raw) {
        file_close(file);
        return E_ERROR;
    }
    read_size = read(file->fd, file->raw, size);
    if (file_close(file))
        return E_ERROR;
    if (read_size != (ssize_t)size) {
        file->raw = free_any(file->raw);
        return E_ERROR;
    }
    file->raw[size] = '\0';
    return E_SUCCESS;
}

int file_load(file_t *file)
{
    size_t size = 0;

    if (!file)
        return E_ERROR;
    if (get_size(file, &size))
        return E_ERROR;
    if (get_raw(file, size))
        return E_ERROR;
    file->size = size;
    return E_SUCCESS;
}
