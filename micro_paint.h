/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:33:25 by sbensarg          #+#    #+#             */
/*   Updated: 2021/02/04 11:07:45 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
#define MICRO_PAINT_H

typedef struct l1
{
    float width;
    float height;
    char **tab;
}              l1;

typedef struct l2
{
    char    r;
    float   x;
    float   y;
    float     width;
    float     height;
    char    c;
}               l2;

l1 rec_l1;
l2 rec_l2;

#endif