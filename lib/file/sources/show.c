/*
** EPITECH PROJECT, 2025
** sub_includes - file_typedef.h
** File description:
** <description>
*/

#include "../includes/file.h"

static void put_bool(const bool b)
{
    if (b)
        str_put_str("true");
    else
        str_put_str("false");
}

static void put_raw(const cstr_t raw)
{
    if (!raw)
        return;
    str_put_str("\nraw:\n```\n");
    str_put_str(raw);
    str_put_str("```");
}

void file_show(file_t *file)
{
    if (!file)
        return;
    str_put_str("full_path: \"");
    str_put_str(file->full_path);
    str_put_str("\"\npath: \"");
    str_put_str(file->path);
    str_put_str("\"\nname: \"");
    str_put_str(file->name);
    str_put_str("\"\nis_open: ");
    put_bool(file->is_open);
    put_raw((cstr_t)file->raw);
    str_put_str("\n");
}
