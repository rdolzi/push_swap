/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:52:53 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/05 23:05:51 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//https://stackoverflow.com/questions/15929869/count-the-number-of-elements-in-an-array-in-c


// determina se l input viene passato come variabile o come semplice parametro
// se e'caso 1 modifica argc e argv
char    **compute_input(int argc, char **argv)
{
    char **matrix;
    (void)argc;
    (void)argv;
    if ( argc == 2)
    {
        return (ft_split(argv[1], ' '));
    }
    return (NULL);
}

