#ifndef ATOM_H
#define ATOM_H
//------------------------------------------------------------------------------------------------------
// Definition of the Atom class. Simple class to describe particles and be able to reset
// their velocities

// By: Timofey Golubev
// Based (with permission) on the serial skeleton code at https://github.com/andeplane/molecular-dynamics-fys3150.
//------------------------------------------------------------------------------------------------------

#include "vec2.h"
#include "global.h"
#include <mpi.h>


class Atom
{
    //make no private vars for ease of use with MPI
public:
    double m_mass = 39.948;  //this is mass in LJ units
    vec2 m_initial_position;
    vec2 position;
    vec2 velocity;
    vec2 force;
    vec2 num_bndry_crossings;  //this is to keep track of boundary crossings for calculating diffusion coeff.
    int atom_index;  


    Atom();   // for dummy array in create_MPI_ATOM
    Atom(double mass);

    void setInitialPosition(double x, double y);
    void resetForce();
    void resetVelocityMaxwellian(double temperature);
    //double mass() { return m_mass; }
    void setMass(double mass) { m_mass = mass; }
    double initial_position(int j){return m_initial_position[j];}
};


//! Creates the MPI_Atom class so it can be passed with MPI
void create_MPI_ATOM ();

//! Free the MPI type at the end of the program
void delete_MPI_atom();


#endif
