/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** parsing
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void skip_esp(char *str, int *i)
{
    for (; str[*i] == ' '; (*i)++);
}

int get_nbr(char const *str, int *i)
{
    int nbr = 0;

    for (; str[*i] >= '0' && str[*i] <= '9'; (*i)++)
        nbr = nbr * 10 + (str[*i] - 48);
    return (nbr);
}

static void part_int(float *result, int *i, char const *str)
{
    while (str[*i] >= '0' && str[*i] <= '9') {
        *result = *result * 10 + (str[*i] - '0');
        (*i)++;
    }
}

static float get_float(const char *str, int *i)
{
    float result = 0.0;
    int sign = 1;
    float fractionmult = 0.1;

    while (str[*i] == ' ')
        (*i)++;
    if (str[*i] == '-') {
        sign = -1;
        (*i)++;
    }
    part_int(&result, i, str);
    if (str[*i] == '.') {
        (*i)++;
        while (str[*i] >= '0' && str[*i] <= '9') {
            result += (str[*i] - '0') * fractionmult;
            fractionmult *= 0.1;
            (*i)++;
        }
    }
    return result * sign;
}

void list_planes_push(list_plane_t **list, sfVector2f *coords,
    int speed, float delay)
{
    list_plane_t *new = malloc(sizeof(list_plane_t));
    list_plane_t *tmp = *list;
    sfVector2f start = coords[0];
    sfVector2f end = coords[1];

    new->start = start;
    new->end = end;
    new->speed = speed;
    new->delay = delay;
    new->next = NULL;
    if (*list == NULL) {
        *list = new;
        return;
    }
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
}

static void is_plane2(char *str, int i, int *speed, float *delay)
{
    skip_esp(str, &i);
    *speed = get_nbr(str, &i);
    skip_esp(str, &i);
    *delay = get_float(str, &i);
}

static int is_plane(char *str, int i, list_plane_t **list,
    unsigned int *total_planes)
{
    sfVector2f *coords = malloc(sizeof(sfVector2f) * 2);
    int speed = 0;
    float delay = 0.0;

    skip_esp(str, &i);
    coords[0].x = get_nbr(str, &i);
    skip_esp(str, &i);
    coords[0].y = get_nbr(str, &i);
    skip_esp(str, &i);
    coords[1].x = get_nbr(str, &i);
    skip_esp(str, &i);
    coords[1].y = get_nbr(str, &i);
    is_plane2(str, i, &speed, &delay);
    list_planes_push(list, coords, speed, delay);
    (*total_planes)++;
    return 0;
}

static int get_my_line(char *str, list_plane_t **list_planes,
    list_tower_t **list_towers, unsigned int *total_planes)
{
    int i = 0;

    skip_esp(str, &i);
    if (str[i] == 'A') {
        i++;
        return is_plane(str, i, list_planes, total_planes);
    } else if (str[i] == 'T') {
        i++;
        return is_tower(str, i, list_towers);
    } else {
        my_putstr("Error: Invalid file\n");
        return 1;
    }
}

static void fill_my_lists(char *str, list_plane_t **list_planes,
    list_tower_t **list_towers, unsigned int *total_planes)
{
    int i = 0;

    while (str[i] != '\0') {
        if (get_my_line(&str[i], list_planes, list_towers, total_planes)
            == 1) {
            *(total_planes) = -1;
            return;
        }
        for (; str[i] != '\n' && str[i] != '\0'; i++);
        i++;
    }
}

unsigned int parse_file(char *filepath, list_plane_t **list_planes,
    list_tower_t **list_towers)
{
    unsigned int total_planes = 0;
    int fd = open(filepath, O_RDONLY);
    char *str;
    struct stat file;

    if (fd == -1) {
        total_planes = -1;
        return total_planes;
    }
    stat(filepath, &file);
    str = malloc((file.st_size + 2) * sizeof(char));
    memset(str, 0, file.st_size + 2);
    read(fd, str, file.st_size);
    fill_my_lists(str, list_planes, list_towers, &total_planes);
    return total_planes;
}

// static void disp_list_planes(list_plane_t *list)
// {
//     list_plane_t *tmp = list;

//     for (; tmp != NULL; tmp = tmp->next) {
//         printf("start: %f %f\n", tmp->start.x, tmp->start.y);
//         printf("end: %f %f\n", tmp->end.x, tmp->end.y);
//         printf("speed: %d\n", tmp->speed);
//         printf("delay: %d\n", tmp->delay);
//     }
// }

// static void disp_list_towers(list_tower_t *list)
// {
//     list_tower_t *tmp = list;

//     for (; tmp != NULL; tmp = tmp->next) {
//         printf("pos: %f %f\n", tmp->pos.x, tmp->pos.y);
//         printf("radius: %f\n", tmp->radius);
//     }
// }
