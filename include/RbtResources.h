/***********************************************************************
* $Id: //depot/dev/client3/rdock/2006.1/include/RbtResources.h#3 $
* Copyright (C) Vernalis (R&D) Ltd 2006
* This file is released under the terms of the End User License Agreement
* in ../docs/EULA.txt
***********************************************************************/

//Miscellaneous string constants

#ifndef _RBTRESOURCES_H_
#define _RBTRESOURCES_H_

#include "RbtTypes.h"
#include "VERSION"

const RbtString IDS_COPYRIGHT = "Copyright (C) RiboTargets 1998-2003, Vernalis (R&D) Ltd 2003-2006";
#ifdef _DEBUG
const RbtString IDS_PRODUCT   = "libRbtD.so";
#else
const RbtString IDS_PRODUCT   = "libRbt.so";
#endif //_DEBUG

#endif //_RBTRESOURCES_H_
