//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4InteractionContent.cc,v 1.6 2002/12/12 19:17:55 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
// ------------------------------------------------------------
//      GEANT 4 class implementation file
//
//      ---------------- G4InteractionContent----------------
//             by Gunter Folger, June 1998.
//       class for a storing two colliding particles in PartonString Models
// ------------------------------------------------------------

#include "G4InteractionContent.hh"

G4InteractionContent::G4InteractionContent(G4VSplitableHadron *aPrimaryParticipant)
      : theNumberOfHard(0), theNumberOfSoft(0)
{
	theProjectile=aPrimaryParticipant;
}

G4InteractionContent::G4InteractionContent(const G4InteractionContent &right)
     : theNumberOfHard(0), theNumberOfSoft(0)
{}


G4InteractionContent::~G4InteractionContent()
{}

int G4InteractionContent::operator==(const G4InteractionContent &right) const
{
	return this==&right;
}

int G4InteractionContent::operator!=(const G4InteractionContent &right) const
{
        return this!=&right;
}


const G4InteractionContent & G4InteractionContent::operator=(const G4InteractionContent &right)
{
	G4Exception("G4InteractionContent::operator= meant to not be accessable");
	return *this;
}

