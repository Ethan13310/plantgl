/* -*-c++-*-
 *  ----------------------------------------------------------------------------
 *
 *       AMAPmod: Exploring and Modeling Plant Architecture 
 *
 *       Copyright 1995-2000 UMR Cirad/Inra Modelisation des Plantes
 *
 *       File author(s): C. Nouguier & F. Boudon (frederic.boudon@cirad.fr)
 *
 *       $Source$
 *       $Id$
 *
 *       Forum for AMAPmod developers    : amldevlp@cirad.fr
 *               
 *  ----------------------------------------------------------------------------
 * 
 *                      GNU General Public Licence
 *           
 *       This program is free software; you can redistribute it and/or
 *       modify it under the terms of the GNU General Public License as
 *       published by the Free Software Foundation; either version 2 of
 *       the License, or (at your option) any later version.
 *
 *       This program is distributed in the hope that it will be useful,
 *       but WITHOUT ANY WARRANTY; without even the implied warranty of
 *       MERCHANTABILITY or FITNESS For A PARTICULAR PURPOSE. See the
 *       GNU General Public License for more details.
 *
 *       You should have received a copy of the GNU General Public
 *       License along with this program; see the file COPYING. If not,
 *       write to the Free Software Foundation, Inc., 59
 *       Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  ----------------------------------------------------------------------------
 */				

/*! \file scne_smbtable.h
    \brief Definition of the SymbolTable class SceneObjectSymbolTable,  GeometrySymbolTable and AppearanceSymbolTable.
*/

#ifndef __scne_smbtable_h__
#define __scne_smbtable_h__

/* ----------------------------------------------------------------------- */

#include "Tools/rcobject.h"
#include "Tools/gsmbtable.h"
#include "geom_namespace.h"
#ifndef GEOM_FWDEF
#include "geom_geometry.h"
#include "appe_appearance.h"
#endif
/* ----------------------------------------------------------------------- */

GEOM_BEGIN_NAMESPACE

/* ----------------------------------------------------------------------- */

#ifdef GEOM_FWDEF
class SceneObject;
typedef RCPtr<SceneObject> SceneObjectPtr;
#endif

/* ----------------------------------------------------------------------- */

/**
   \class SceneObjectSymbolTable
   \brief Class used for parsing a stream containing SceneObject.  
*/

/* ----------------------------------------------------------------------- */
class GEOM_API SceneObjectSymbolTable : public SymbolTable<SceneObjectPtr> {};

/* ----------------------------------------------------------------------- */

#ifdef GEOM_FWDEF
class Geometry;
typedef RCPtr<Geometry> GeometryPtr;
#endif

/* ----------------------------------------------------------------------- */

/**
   \class GeometrySymbolTable
   \brief Class used for parsing a stream containing Geometry.
*/

/* ----------------------------------------------------------------------- */

class GEOM_API GeometrySymbolTable : public SymbolTable<GeometryPtr> {};

/* ----------------------------------------------------------------------- */

#ifdef GEOM_FWDEF
class Appearance;
typedef RCPtr<Appearance> AppearancePtr;
#endif

/* ----------------------------------------------------------------------- */

/**
   \class AppearanceSymbolTable
   \brief Class used for parsing a stream containing Appearance.
*/

/* ----------------------------------------------------------------------- */

class GEOM_API AppearanceSymbolTable : public SymbolTable<AppearancePtr> {};

/* ----------------------------------------------------------------------- */

GEOM_END_NAMESPACE

/* ----------------------------------------------------------------------- */

#endif
