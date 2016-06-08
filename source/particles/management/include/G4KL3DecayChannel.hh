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
// $Id: G4KL3DecayChannel.hh,v 1.4 2001/07/11 10:01:56 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//
//
// ------------------------------------------------------------
//      GEANT 4 class header file
//
//      History: first implementation, based on object model of
//       7 June 1997 H.Kurashige
// ------------------------------------------------------------
#ifndef G4KL3DecayChannel_h
#define G4KL3DecayChannel_h 1

#include "G4ios.hh"
#include "globals.hh"
#include "G4VDecayChannel.hh"

class G4KL3DecayChannel :public G4VDecayChannel
{
  public:  // With Description
    //Constructors 
      G4KL3DecayChannel(const G4String& theParentName,
			G4double        theBR,
			const G4String& thePionName,
			const G4String& theLeptonName,
			const G4String& theNutrinoName);
    //  Destructor
      virtual ~G4KL3DecayChannel();

  public:  // With Description
     virtual G4DecayProducts *DecayIt(G4double);     

  protected:
     // assignment of daughter particles for arrays of daughters[] etc.
     enum{idPi=0, idLepton=1, idNutrino=2}; 
     G4double daughterM[3];

  protected:
     // calcurate momentum of daughters
     //     results will be stored in Edaughter[3] and Pdaughter[3]
     void PhaseSpace(G4double Mparent,
		     const G4double* Mdaughter,
		     G4double*       Edaughter,
		     G4double*       Pdaughter);

  protected:
     // Dalitz Plot Density
     // KL3 decay   Dalitz Plot Density
     //               see Chounet et al Phys. Rep. 4, 201
     //  arguments
     //    Epi: kinetic enregy of pion
     //    El:  kinetic enregy of lepton (e or mu)
     //    Enu: kinetic energy of nutrino
     //  constants
     //    pLambda : linear energy dependence of f+
     //    pXi0    : = f+(0)/f-
     //    pNorm   : normalization factor
     G4double   DalitzDensity(G4double Epi, G4double El,  G4double Enu);  
  private:
     // constants used in DalitzDensity() 
     //   Kon mass
     G4double massK;
     //   coefficients
     G4double   pLambda;
     G4double   pXi0;
     G4double   pNormalization;

  public:
     void SetDalitzParameter(G4double aLambda, G4double aXi );
     G4double GetDalitzParameterLambda() const;
     G4double GetDalitzParameterXi() const;
};  

inline 
 void G4KL3DecayChannel::SetDalitzParameter(G4double aLambda, G4double aXi)
{
   pLambda  = aLambda;
   pXi0      = aXi;
}

inline 
 G4double G4KL3DecayChannel::GetDalitzParameterLambda() const
{
  return  pLambda;
}

inline 
 G4double G4KL3DecayChannel::GetDalitzParameterXi() const
{
  return  pXi0;
}


#endif



