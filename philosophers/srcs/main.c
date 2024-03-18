 #include "../header/philo.h"

int main(int argc, char **argv)
{
    t_params    params;
    t_philo     *table;

    table = NULL;
	if (argc < 5 || argc > 6)
		return (printf("invalid args\n"));
    params = params_init(argv);


    return (0);
}

//printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, get_time(my_philo->params.t0));
