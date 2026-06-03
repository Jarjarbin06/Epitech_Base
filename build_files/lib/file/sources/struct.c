/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include "../includes/file.h"

static size_t get_last_slash_idx(const char *full_path)
{
    size_t last_slash_idx = 0;

    if (!full_path)
        return -1;
    for (size_t idx = 0; full_path[idx] != '\0'; idx++)
        if (full_path[idx] == '/')
            last_slash_idx = idx;
    return last_slash_idx;
}

static char *get_path(const char *full_path)
{
    if (!full_path)
        return NULL;
    return str_ndup(full_path, get_last_slash_idx(full_path));
}

static char *get_name(const char *full_path)
{
    if (!full_path)
        return NULL;
    return str_dup(&full_path[get_last_slash_idx(full_path) + 1]);
}

static file_t *check_file(file_t **file)
{
    if (!file || !*file)
        return NULL;
    if (!(*file)->full_path || !(*file)->path || !(*file)->name) {
        file_destroy(file);
        return NULL;
    }
    return *file;
}

file_t *file_create(const char full_path[])
{
    file_t *file = NULL;

    if (!full_path)
        return NULL;
    file = malloc_any(sizeof(file_t));
    if (!file)
        return NULL;
    *file = (file_t){
        .fd = {},
        .full_path = str_dup(full_path),
        .path = get_path(full_path),
        .name = get_name(full_path),
        .rights = (rights_t){false, false, false},
        .is_open = false,
        .size = -1,
        .raw = NULL
    };
    return check_file(&file);
}

int file_destroy(file_t **file)
{
    if (!file || !*file)
        return E_ERROR;
    free_any((*file)->full_path);
    free_any((*file)->path);
    free_any((*file)->name);
    if ((*file)->raw)
        free_any((*file)->raw);
    *file = free_any(*file);
    return E_SUCCESS;
}
