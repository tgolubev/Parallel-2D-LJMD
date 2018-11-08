//------------------------------------------------------------------------------------------------------
// Definition of VelocityVerlet class which controls the integration of
// the equations of motion in order to time-step the simulation.
//
// By Timofey Golubev
// Based (with permission) on the serial skeleton code at https://github.com/andeplane/molecular-dynamics-fys3150.
//------------------------------------------------------------------------------------------------------

#ifndef VELOCITYVERLET_H
#define VELOCITYVERLET_H

class VelocityVerlet
{
private:
    bool m_firstStep = true;
public:
    VelocityVerlet() {}
    void integrate(class System &system, double dt);
};
#endif
