/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:27:39 by sbensarg          #+#    #+#             */
/*   Updated: 2021/02/04 11:48:25 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "micro_paint.h"


int ft_print_err(char *msg, int nb)
{
    write(1, "Error: ", 7);
    write(1, msg, strlen(msg));
    write(1, "\n", 1);
    return (nb);
}

int in_rec(float i, float j)
{
    if (i < rec_l2.x || rec_l2.x + rec_l2.width < i
		|| j < rec_l2.y ||rec_l2.y + rec_l2.height < j)
		return (0);
   if ((i - rec_l2.x < 1.00000000 || (rec_l2.x + rec_l2.width) - i < 1.00000000 ||
	j - rec_l2.y < 1.00000000 || (rec_l2.y + rec_l2.height) - j < 1.00000000))
		return (2); 
    return (1);
}

void draw_rec()
{
    int i = 0;
    int j = 0;
    int ret;
    
    while (j < rec_l1.height)
    {
        i = 0;
        while (i < rec_l1.width)
        {
            ret = in_rec(i, j);
            if ((ret == 2 && rec_l2.r == 'r') || (ret && rec_l2.r == 'R'))
                rec_l1.tab[j][i] = rec_l2.c;
            i++;
        }
        j++;
    }
}
int ft_read_config_file(char *filename)
{
    FILE *fd;
    char bg_char;
    int ret;
    int i = 0;
    int j = 0;

    fd = fopen(filename, "r");
    if (!fd)
        return (ft_print_err("Operation file corrupted", 1));
    ret = fscanf(fd, "%f %f %c\n", &rec_l1.width, &rec_l1.height, &bg_char);
        if (ret != 3 || (!(rec_l1.width > 0 && rec_l1.width <= 300)) 
        || (!(rec_l1.height > 0 && rec_l1.height <= 300)))
            return (ft_print_err("Operation file corrupted", 1));
        rec_l1.tab = malloc(sizeof(char *) * rec_l1.height);
        while (j < rec_l1.height)
        {
            rec_l1.tab[j] = malloc(sizeof(char) * (rec_l1.width + 1));
            i = 0;
            while (i <= rec_l1.width)
            {
                rec_l1.tab[j][i] = bg_char;
                i++;
            }
            j++;
        }
        while ((ret = fscanf(fd, "%c %f %f %f %f %c\n", &rec_l2.r, &rec_l2.x, &rec_l2.y, &rec_l2.width, &rec_l2.height, &rec_l2.c)) == 6)
        {
            if (!(rec_l2.width > 0.00000000 && rec_l2.height > 0.00000000 && (rec_l2.r == 'R' || rec_l2.r == 'r')))
                return (ft_print_err("Operation file corrupted", 1));
            draw_rec();
        }
        if (ret != -1)
            return (ft_print_err("Operation file corrupted", 1));
        j = 0;
        while (j < rec_l1.height)
        {
            write(1, rec_l1.tab[j], rec_l1.width);
            free(rec_l1.tab[j]);
            write(1, "\n", 1);
            j++;
        }
        free(rec_l1.tab);
        fclose(fd);
        return (0);   
}
int main(int argc , char **argv)
{
    if (argc == 2)
    {
        if (ft_read_config_file(argv[1]) == 0)
            return (0);
        else
            return (1);
    }
    else
        return(ft_print_err("argument", 1)); 
}