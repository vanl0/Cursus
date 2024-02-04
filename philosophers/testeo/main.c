#include "./philo.h"

int main() {
    struct timeval time;

    // Obtiene la hora actual
    if (gettimeofday(&time, NULL) != 0) {
        perror("Error al obtener la hora");
        return 1;
    }

    // Muestra el tiempo en segundos y microsegundos
    //printf("Segundos: %ld\n", currentTime.tv_sec);
    printf("Microsegundos: %ld\n", time.tv_sec * 1000 + time.tv_usec / 1000);

    return 0;
}