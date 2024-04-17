/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 philo.h											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/01/16 12:57:43 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2024/01/16 13:03:10 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_val
{
	int				die;
	int				eat;
	int 			sleep;
	int				n_philo;
	int				max_meals;
	long int		t0;
	pthread_t		*th;
	int				*death_flg;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	write_mutex;
}	t_val;

typedef struct s_philo
{
	t_val				val;
	int					num;
	pthread_mutex_t		fork;
	long int			last_meal;
	int					n_meal;
	struct s_philo		*right;
}	t_philo;

typedef struct s_params
{
	t_val		val;
	t_philo		*table;
}	t_params;


//TABLE
t_philo		*add_philo(t_philo **table, t_val val, int i);
void		set_table(t_philo **table, t_val val);
void		free_table(t_philo *table);
//THREADS
void		start_threads(t_philo *philo, t_params *params);
void		close_threads(t_val val);
//PHILO
void		print_action(t_philo *philo, char *msg);
void		take_fork(pthread_mutex_t *fork, t_philo *philo);
void		eat(t_philo *philo);
//TIME
long int	get_time(long int t0);
//UTILS
int			ft_atoi(char *str);

#endif
