/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:13:18 by sbensarg          #+#    #+#             */
/*   Updated: 2021/02/03 15:32:40 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
#define MICRO_PAINT_H

typedef struct l1
{
    int width;
    int height;
    char **tab;
}              l1;

typedef struct l2
{
    char    c;
    float   x;
    float   y;
    float   radius;
    char    k;
}               l2;

l1 cercle_l1;
l2 cercle_l2;

#endif