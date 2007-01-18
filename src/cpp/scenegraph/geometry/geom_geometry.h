/* -*-c++-*-
 *  ----------------------------------------------------------------------------
 *
 *       AMAPmod: Exploring and Modeling Plant Architecture
 *
 *       Copyright 1995-2000 UMR Cirad/Inra Modelisation des Plantes
 *
 *       File author(s): C. Nouguier & F. Boudon (frederic.boudon@cirad.fr) nouguier
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


/*! \file geom_geometry.h
    \brief Definition of the geometry class Geometry.
*/


#ifndef __geom_geometry_h__
#define __geom_geometry_h__

/* ------------------------------------------------------------------------- */

#include "scne_sceneobject.h"

/* ------------------------------------------------------------------------- */

GEOM_BEGIN_NAMESPACE

/* ------------------------------------------------------------------------- */

class Geometry;
typedef RCPtr<Geometry> GeometryPtr;
class GeometrySymbolTable;

/* ------------------------------------------------------------------------- */

/**
    \class Geometry
    \brief Abstract base class for all 3D geometric geometry models.
*/

class GEOM_API Geometry : public virtual SceneObject
{

public:

  /** A structure which helps to build a Geometry when parsing.
      Fields are normally allocated while parsing and are free when the
      object is contructed using the member \c destroy. */

    struct Builder : public SceneObject::Builder {

    /// A constructor. It inits all the pointers to null.
    Builder( );

    /// A destructor.
    virtual ~Builder( );

    /** Returns a pointer to a Geometry constructed using the values
        contained within \e self. If \e self is not valid, it returns a
        null pointer. */
    virtual SceneObjectPtr build( ) const = 0;

  };


  /// Default constructor.
  Geometry( );

  /// Destructor
  virtual ~Geometry( );

  /// Returns whether \e self represent a curve.
  virtual bool isACurve( ) const = 0;

  /// Returns whether \e self represent a surface.
  virtual bool isASurface( ) const = 0;

  /// Returns whether \e self represent a volume.
  virtual bool isAVolume( ) const = 0;

  /// Returns whether \e self is explicit.
  virtual bool isExplicit( ) const = 0;

  /// Prints \e g to the output stream \e stream.
//  friend ostream& operator<<( ostream& stream, Geometry& g );

  /** Parses the input stream \e inputStream and returns the corresponding
      symbol table \e symbolTable
      \pre
      - \e inputStream must be valid;
      - \e outputStream must be valid. */
  static bool parse( std::istream& inputStream,
                     std::ostream& outputStream,
                     GeometrySymbolTable& symbolTable,
                     int max_errors = -1 );

  /** Parses the file \e fileName and returns the corresponding symbol table
      \e symbolTable.
      \pre
      - \e fileName must exist;
      - \e outputStream must be valid. */
  static bool parse( const std::string& fileName,
                     std::ostream& outputStream,
                     GeometrySymbolTable& symbolTable,
                     int max_errors = -1 );

}; // class Geometry

/// Geometry Pointer
typedef RCPtr<Geometry> GeometryPtr;


/* ------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------- */

GEOM_END_NAMESPACE

/// Write Geometry in \b stream
GEOM_API std::ostream& operator<<( std::ostream& stream, GEOM(Geometry&) g );

/* ----------------------------------------------------------------------- */
#endif

