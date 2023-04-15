/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:10 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/15 17:01:45 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// https://www.programiz.com/dsa/greedy-algorithm
// https://www.geeksforgeeks.org/greedy-algorithms/

//              -----Greedy Algorithm------

// Def: A greedy algorithm is an approach for solving a problem by selecting the best option available at the moment.

// In other words: Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. So the problems where choosing locally optimal also leads to global solution are the best fit for Greedy.

// 1. It doesn't worry whether the current best result will bring the overall optimal result.

// 2. The algorithm never reverses the earlier decision even if the choice is wrong. It works in a top-down approach.

// 3. This algorithm may not produce the best result for all the problems. It's because it always goes for the local best choice to produce the global best result.However, we can determine if the algorithm can be used with any problem if the problem has the following properties:

// 1. Greedy Choice Property

// If an optimal solution to the problem can be found by choosing the best choice at each step without reconsidering the previous steps once chosen, the problem can be solved using a greedy approach. This property is called greedy choice property.

// 2. Optimal Substructure

// If the optimal overall solution to the problem corresponds to the optimal solution to its subproblems, then the problem can be solved using a greedy approach. This property is called optimal substructure.

// TODO: Push elementi (B -> A) ottimizzando per il n° mosse
//       necessarie ad inserire l elemento nell index corretto A.
//       Verrà inserito l elemento che ha le minor mosse della seguente
//       combinazione:
//     1. Mosse per andare in B[0]
//     2. Mosse per posizionare A tale che:
//        A[0] > B[0] && A[size - 1] < B[0]

// HowTO:
//       1. Creare array int (TEMP)con size B tale che:
//          a. index TEMP == index B
//          b. value of index TEMP == mosse per inserimento
//       2. Trovare elemento con valore più basso.
//       3. Muovere in B[0] tale elemento
//       4. Ruotare A && pa(B)
