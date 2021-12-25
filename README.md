# Philosophers' problem

With this project, I learned about multithreading in C
The problem of philosophers has existed on the Internet for a long time, and it has several types of implementations,
I chose a method that uses all the power of the "Observer"


## Technologies

1. C
2. Make

## Launch rules

The program receives 3 arguments as input (or optionally 4)

     - The first is the number of philosophers
     - The second is the life of a philosopher without food
     - The third is the time during which the philosopher satisfies his appetite
     - The fourth is the time it takes a philosopher to sleep
     - The fifth (optional parameter) is how many times Philos should be eaten

## Launch

1. Build a project using Makefile

   ```sh
   $ make
   ```

2. Run the program like this:

   ```sh
   $ ./philo 5 410 200 200
   ```

