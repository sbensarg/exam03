/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:12:23 by sbensarg          #+#    #+#             */
/*   Updated: 2021/02/04 10:50:56 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "mini_paint.h"


int ft_print_err(char *msg, int nb)
{
    write(1, "Error: ", 7);
    write(1, msg, strlen(msg));
    write(1, "\n", 1);
    return (nb);
}


int draw_cercle()
{
    int i = 0;
    int j = 0;
    float ret;
    float dist;
    while (j < cercle_l1.height)
    {
        i = 0;
        while (i < cercle_l1.width)
        {
            ret = sqrtf(((i - cercle_l2.x) * (i - cercle_l2.x)) + ((j - cercle_l2.y) * (j - cercle_l2.y)));
            dist = ret - cercle_l2.radius;
            if (ret <= cercle_l2.radius)
            {
                if (dist > -1.00000000 || (cercle_l2.c == 'C'))
                    cercle_l1.tab[j][i] = cercle_l2.k;
            }
            i++;
        }
        j++;
    }
    return (1);
}
int ft_read_config_file(char *filename)
{
    FILE *fd;
    char bg_char = 0;
    int ret;
    int i = 0;
    int j = 0;

    fd = fopen(filename, "r");
    if (!fd)
        return (ft_print_err("Operation file corrupted", 1));
    ret = fscanf(fd, "%d %d %c\n", &cercle_l1.width, &cercle_l1.height, &bg_char);
        if (ret != 3 || (!(cercle_l1.width > 0 && cercle_l1.width <= 300)) 
        || (!(cercle_l1.height > 0 && cercle_l1.height <= 300)))
        {
           // printf("qwrqr");
            return (ft_print_err("Operation file corrupted", 1));
        }
        cercle_l1.tab = malloc(sizeof(char *) * cercle_l1.height);
        while (j < cercle_l1.height)
        {
            cercle_l1.tab[j] = malloc(sizeof(char) * (cercle_l1.width + 1));
            i = 0;
            while (i <= cercle_l1.width)
            {
                cercle_l1.tab[j][i] = bg_char;
                i++;
            }
            j++;
        }
        while ((ret = fscanf(fd, "%c %f %f %f %c\n", &cercle_l2.c, &cercle_l2.x, &cercle_l2.y, &cercle_l2.radius , &cercle_l2.k)) == 5)
        {
            // printf("%c\n", cercle_l2.c);
            // printf("%f\n", cercle_l2.x);
            // printf("%f\n", cercle_l2.y);
            // printf("%f\n", cercle_l2.radius);
            // printf("%c\n", cercle_l2.k);
            
            if (!(cercle_l2.radius > 0.00000000 && (cercle_l2.c == 'c' || cercle_l2.c == 'C')))
                return (ft_print_err("Operation file corrupted", 1));
            draw_cercle();
        }
        if (ret != -1)
            return (ft_print_err("Operation file corrupted", 1));
        j = 0;
        while (j < cercle_l1.height)
        {
            write(1, cercle_l1.tab[j], cercle_l1.width);
            free(cercle_l1.tab[j]);
            write(1, "\n", 1);
            j++;
        }
        free(cercle_l1.tab);
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