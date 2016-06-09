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
// $Id: XrayFluoMercuryDetectorMessenger.hh
// GEANT4 tag $Name: 
//
// Author: Alfonso Mantero (Alfonso.Mantero@ge.infn.it)
//
// History:
// -----------
//
//  18 Aug 2003  Alfonso Mantero created
//
// -------------------------------------------------------------------


#ifndef XrayFluoMercuryDetectorMessenger_h
#define XrayFluoMercuryDetectorMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class XrayFluoMercuryDetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithoutParameter;
class G4UIcmdWithABool;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class XrayFluoMercuryDetectorMessenger: public G4UImessenger
{

public:
  XrayFluoMercuryDetectorMessenger(XrayFluoMercuryDetectorConstruction* );
  ~XrayFluoMercuryDetectorMessenger();
  
  void SetNewValue(G4UIcommand*, G4String);
  
private:
  XrayFluoMercuryDetectorConstruction*    Detector;
  G4UIdirectory*             detDir;
  
  G4UIcmdWithoutParameter*   UpdateCmd;
  G4UIcmdWithAString* sampleCmd;
  G4UIcmdWithAString* detectorCmd;
  //G4UIcmdWithABool* granularityFlagCmd;
  G4UIcmdWithADoubleAndUnit* latitudeAngleCmd;
  G4UIcmdWithADoubleAndUnit* orbitHeightCmd;
};

#endif




