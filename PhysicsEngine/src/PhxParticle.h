/********************************************************************************/
/* [File]: PhxParticle.h														*/
/* [Description]: This file contains the definitions for the paticle class,		*/
/* which can be used in place of rigid bodies for simpler simulations or		*/
/* assemblies.																	*/
/* A particle is the simplest object that can be simulated in the physics system*/
/* It has position data (no orientation data), along with velocity.				*/
/* It can be integrated forward through time, and have linear forces, and		*/
/* impulses applied to it. The particle manages its state and allows access		*/
/* through a set of methods.													*/
/*																				*/
/* [Author]: Tommaso Galatolo tommaso.galatolo@gmail.com						*/
/* [Date]: 5/6/2015																*/
/* [License]:																	*/
/* This program is free software: you can redistribute it and/or modify			*/
/* it under the terms of the GNU Lesser General Public License as published by	*/
/* the Free Software Foundation, either version 3 of the License, or			*/
/* (at your option) any later version.											*/
/*																				*/
/* This program is distributed in the hope that it will be useful,				*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of				*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the				*/
/* GNU Lesser General Public License for more details.							*/
/*																				*/
/* You should have received a copy of the GNU Lesser General Public License		*/
/* along with this program.  If not, see <http://www.gnu.org/licenses/>.		*/
/********************************************************************************/
#ifndef _PHXPARTICLE_H_
#define _PHXPARTICLE_H_
//Libs
#include "UsedLibs.h"

class PhxParticle
{
protected:
	/*
	Holds the linear position of the particle in
	world space.
	*/
	vec3 m_vPosition;
	/*
	Holds the linear velocity of the particle in
	world space.
	*/
	vec3 m_vVelocity;
	/*
	These data members store the current force and
    global linear acceleration of the particle.
	Holds the accumulated force to be applied at the next
	simulation iteration only. This value is zeroed at each
	integration step.
	*/
	vec3 m_vForceAccu;
	/* 
	Holds the acceleration of the particle.  This value
    can be used to set acceleration due to gravity (its primary
    use), or any other constant acceleration.
	*/
	vec3 m_vAcceleration;
	/*
	Holds the inverse of the mass of the particle. It
	is more useful to hold the inverse mass because
	integration is simpler, and because in real time
	simulation it is more useful to have objects with
	infinite mass (immovable) than zero mass
	(completely unstable in numerical simulation).
	*/
	real m_rInverseMass;
	/*
	Holds the amount of damping applied to linear
	motion. Damping is required to remove energy added
	through numerical instability in the integrator.
	*/
	real m_rDamping;

public:
	PhxParticle();
	~PhxParticle();
	
	/*
	Integration and simulation functions
	*/

	/*
	here
	*/
	void Integrate(real a_rDuration);

	
};

#endif //!_PHXPARTICLE_H_