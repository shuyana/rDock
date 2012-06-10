/***********************************************************************
* $Id: //depot/dev/client3/rdock/2006.1/src/lib/RbtRandLigTransform.cxx#3 $
* Copyright (C) Vernalis (R&D) Ltd 2006
* This file is released under the terms of the End User License Agreement
* in ../../docs/EULA.txt
***********************************************************************/

#include "RbtRandLigTransform.h"

//Static data member for class type
RbtString RbtRandLigTransform::_CT("RbtRandLigTransform");
//Parameter names
RbtString RbtRandLigTransform::_TORS_STEP("TORS_STEP");

////////////////////////////////////////
//Constructors/destructors
RbtRandLigTransform::RbtRandLigTransform(const RbtString& strName) :
  RbtBaseUniMolTransform(_CT,strName),m_rand(Rbt::GetRbtRand()) {
  //Add parameters
  AddParameter(_TORS_STEP,180);
#ifdef _DEBUG
  cout << _CT << " parameterised constructor" << endl;
#endif //_DEBUG
  _RBTOBJECTCOUNTER_CONSTR_(_CT);
}

RbtRandLigTransform::~RbtRandLigTransform()
{
#ifdef _DEBUG
  cout << _CT << " destructor" << endl;
#endif //_DEBUG
  _RBTOBJECTCOUNTER_DESTR_(_CT);
}


////////////////////////////////////////
//Protected methods
///////////////////
void RbtRandLigTransform::SetupTransform() {
  //Clear the rotable bond list from the previous model 
  m_rotableBonds.clear();
  //Check for undefined ligand
  if (GetLigand().Null())
    return;
  m_rotableBonds = Rbt::GetRotatableBondList(GetLigand()->GetBondList());
}

////////////////////////////////////////
//Private methods
///////////////////
//Pure virtual in RbtBaseTransform
//Actually apply the transform
void RbtRandLigTransform::Execute()
{
  RbtModelPtr spLigand = GetLigand();
  if (spLigand.Null())
    return;
  RbtDouble torsStep = GetParameter(_TORS_STEP);
  for (RbtBondListIter iter = m_rotableBonds.begin(); iter != m_rotableBonds.end(); iter++) {
    RbtDouble thetaDeg = 2.0*torsStep*m_rand.GetRandom01() - torsStep;
    spLigand->RotateBond(*iter,thetaDeg,false);
  }
}

