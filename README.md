#OpenMP tasks

##command to compile
* ➜  git:(master) ✗ gcc -o omp1 -fopenmp OpenMP/omp01.c
* omp1 - executable file, omp1.c - file to compile

##command to run
* ➜  git:(master) ✗ ./omp1
* omp1 - executable file

## set threads amount
  * omp_set_num_threads() - via func
  * OMP_NUM_THREADS - via global variable.

## OMP tutorials from Habr
  * [Lecture 1](http://habrahabr.ru/company/intel/blog/82486/)
  * [Lecture 2](http://habrahabr.ru/company/intel/blog/83504/)
  * [Lecture 3](http://habrahabr.ru/company/intel/blog/85273/)
  * [Lecture 4](http://habrahabr.ru/company/intel/blog/86820/)
  * [Lecture 5](http://habrahabr.ru/company/intel/blog/88574/)
