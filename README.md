# philo
Learning proyect - 42 Málaga

## Description

This project is about learning how threads work by precisely timing a group of philosophers on when to pick up forks and eat without dying from hunger

The bonus is  done with processes and a semaphore instead of threads and mutexes

## How to use

```
$> ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat
```
all times in miliseconds.

* number_of_times_each_philosopher_must_eat is an optional argument: if all philosophers eat at least number_of_times_each_philosopher_must_eat times, the simulation will stop. If not specified, the simulation will stop with the death of a philosopher.
