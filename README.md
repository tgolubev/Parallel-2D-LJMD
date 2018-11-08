# Parallelized interactive real time simulation of molecular dynamics

Authors: Liam Clink, Zane Crawford, Forrest Glines, Timofey Golubev, Xukun Xiang

Acknowledgements:
 Initial inspiration (with permission) for the molecular dynamics Model code is from
 the code found at: https://github.com/andeplane/molecular-dynamics-fys3150v.

## Description:

 This is a Parallelized interactive real time simulation of molecular dynamics 
 using the Lennard Jones potential, meant for use on a Raspberry Pi supercomputer
 with an XBox One controller. Realtime visualization is done using OpenGL.
 
 Parallelization is done using domain decomposition in 1D. The code can simulate
 the effects on atomic-like particles due to a moving external electric potential
 which is controlled by the XBox One Controller.

 For a description of the molecular dynamics algorithms, see my report at:
 https://github.com/tgolubev/Computational-Physics-PHY905MSU/blob/master/Project4/molecular_dynamics/Report/Project4.pdf
 
## Code structure:
 Model contains the parallelized molecular dynamics calculations
 View contains the code for OpenGL real-time visualization
 Controller contains code for interacting with the XBox Controller

## Building
To build with the model and view, run:
    ./configure 
    make

To build without the view and just the model, run:
    ./configure --disable-view

To clear the files made using configure, for example when switching between
building with and without a view run 
    make distclean

If you need to add more sources files, add them to Makefile.am, then run
`autoreconf `
before running `./configure` again

If `./configure` has problems finding a C compiler, add your mpi C and C++
compilers to the lines in configure.ac
    AC_PROG_CC([mpicc])
    AC_PROG_CXX([mpic++ mpicxx])
And run `autoreconf`


## Running
The binary parallel2DLJMD will be in bin. If built with the view, by default
task 0 will run the view and rest will run with the model. If built with the
view disabled, all mpi tasks will run the model
