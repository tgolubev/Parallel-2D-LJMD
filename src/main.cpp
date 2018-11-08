//-------------------------------------------------------------------------------------------------------------
/*          Parallelized interactive real time simulation of molecular dynamics


      Authors: Liam Clink, Zane Crawford, Forrest Glines, Timofey Golubev, Xukun Xiang

 Acknowledgements:
 Initial inspiration (with permission) for the molecular dynamics Model code is from
 the code found at: https://github.com/andeplane/molecular-dynamics-fys3150v.

 Description:

 This is a Parallelized interactive real time simulation of molecular dynamics 
 using the Lennard Jones potential, meant for use on a Raspberry Pi supercomputer
 with an XBox One controller. Realtime visualization is done using OpenGL.
 
 Parallelization is done using domain decomposition in 1D. The code can simulate
 the effects on atomic-like particles due to a moving external electric potential
 which is controlled by the XBox One Controller.

 This file sets up the simulation and allows to run the simulation either with 
 or without the View (OpenGL visualization)

 For a description of the molecular dynamics algorithms, see my report at:
 https://github.com/tgolubev/Computational-Physics-PHY905MSU/blob/master/Project4/molecular_dynamics/Report/Project4.pdf

*/
//-------------------------------------------------------------------------------------------------------------


#include <mpi.h>
#include "main.hpp"

int main(int argc,char **argv){
  int my_id, nprocs;

  MPI_Init(&argc, &argv);  
  MPI_Comm_rank(MPI_COMM_WORLD, &my_id);   
  MPI_Comm_size(MPI_COMM_WORLD, &nprocs);  

#ifdef VIEW_ENABLED
  if(my_id == 0){
    //Run the View on root
    /*MPI_Comm comm_model;
    MPI_Comm_split(MPI_COMM_WORLD,
        MPI_UNDEFINED,my_id,&comm_model);*/

    viewMain(argc,argv);
  } else{
    /*MPI_Comm comm_model;
    MPI_Comm_split(MPI_COMM_WORLD,
        1,my_id,&comm_model);

    modelMain(argc,argv,comm_model);*/
    modelMain(argc,argv);
  }
#else
  /*MPI_Comm comm_model;
  MPI_Comm_split(MPI_COMM_WORLD,
      1,my_id,&comm_model);

  modelMain(argc,argv,comm_model);*/
  modelMain(argc,argv);
#endif
  MPI_Finalize();
}
