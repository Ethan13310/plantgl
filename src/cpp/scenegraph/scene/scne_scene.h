
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


/*! \file scne_scene.h
    \brief Definition of the scene class Scene.
*/

#ifndef __scne_scene_h__
#define __scne_scene_h__

/* ----------------------------------------------------------------------- */

#include <vector>
#include "scne_sceneobject.h"
#ifndef GEOM_FWDEF
#include "scne_shape.h"
#endif

// #include <qthread.h>
// qthread.h contains QT_THREAD_SUPPORT definition.

#ifdef QT_THREAD_SUPPORT
// forward declaration of QMutex
class QMutex;
#endif

/* ----------------------------------------------------------------------- */

GEOM_BEGIN_NAMESPACE

/* ----------------------------------------------------------------------- */

class Scene;

typedef RCPtr<Scene> ScenePtr;

#ifdef GEOM_FWDEF
class GeomShape3D;
class GeomShape;
typedef RCPtr<GeomShape3D> GeomShape3DPtr;
typedef RCPtr<GeomShape> GeomShapePtr;
#endif


/* ----------------------------------------------------------------------- */

/**
   \class Scene
   \brief A 3D Scene represented by a list of objects of type of Shape.
*/

/* ----------------------------------------------------------------------- */

class GEOM_API Scene : public TOOLS(RefCountObject)
{

public:


  /// An iterator used to iterate through a Scene.
  typedef std::vector<GeomShape3DPtr>::iterator iterator;

  /// A const iterator used to iterate through a Scene.
  typedef std::vector<GeomShape3DPtr>::const_iterator const_iterator;

  /// Constructs an empty Scene.
  Scene(unsigned int size=0);

  Scene(const Scene&);

  /// Constructs a Scene with object describe in \e filename. Write error on \e _errlog.
  Scene(const std::string& filename, std::ostream& errlog=std::cerr, int max_error = -1);

  /// Constructs a Scene with objects describe in \e table.
  Scene(const SceneObjectSymbolTable& table);

  /// Constructs a Scene with object describe in \e input. Write error on \e _errlog.
  Scene(std::istream& input, std::ostream& errlog=std::cerr, int max_error = -1);

  /// Destructs a Scene.
  virtual ~Scene( );

  Scene& operator=( const Scene& );

  void read( const std::string& fname , std::ostream& errlog=std::cerr, int max_error = -1);
  void read( std::istream& input, std::ostream& errlog=std::cerr, int max_error = -1 );
  
  /** Adds objects describe in table  */
  void add( const SceneObjectSymbolTable& table );

  /** Adds a shape to the \e self
      \pre
      - shape must be non null and valid. */
  void add( const GeomShape& shape );
  void add( const GeomShapePtr& shape );

  /** Adds a shape to the \e self
      \pre
      - shape must be non null and valid. */
  void add( const GeomShape3DPtr& shape );

  /// Deep copy of \e this.
  virtual ScenePtr copy() const ;

  /** Applies the action \e action to each shape of \e self.
    */
  bool apply( Action& action );

  /** Applies the action \e action to \e self.
      For each shape within \e self, it applies the action first to the
      Geometry part and second to the Appearance part. */
  bool applyGeometryFirst( Action& action );

  /** Applies the action \e action to \e self.
      It applies the action to the Geometry part only. The Appearance part
      is skipped. */
  bool applyGeometryOnly( Action& action );

  /** Applies the action \e action to \e self.
      It applies the action first to the Appearance part and second to the
      Geometry part. */
  bool applyAppearanceFirst( Action& action );

  /** Applies the action \e action to \e self.
      It applies the action to the Appearance part only. The Geometry
      part is skipped. */
  bool applyAppearanceOnly( Action& action );

  /// Clears \e self.
  void clear( );

  /// Returns a const iterator at the beginning of \e self.
  const_iterator getBegin( ) const;

  /// Returns an iterator at the beginning of \e self.
  iterator getBegin( );

  /// Returns a const iterator at the end of \e self.
  const_iterator getEnd( ) const;

  /// Returns an iterator at the end of \e self.
  iterator getEnd( );

  /// Returns the \e i-th element of \e self.
  const GeomShape3DPtr getAt(uint32_t i ) const ;

  /// Returns the \e i-th element of \e self.
  void setAt(uint32_t i, const GeomShape3DPtr& );

  /// Returns the \e i-th element of \e self.
  const GeomShapePtr getShapeId(uint32_t id ) const ;

  /// Returns the size of \e self.
  uint32_t getSize( ) const ;

  /// Resize  \e self.
  void Resize(const uint32_t size );

  /// Returns whether \e self is empty.
  bool isEmpty( ) const ;

  /// Returns whether \e self is valid.
  bool isValid( ) const ;

  /// Returns whether \e self is valid and output error on stream.
  bool isValid( std::ostream& stream ) const ;

  /// Returns whether \e self is valid and output error on stream error, ...
  bool isValid( std::ostream& error,std::ostream& warning, std::ostream& info) const;

  /** Merges the Scene \e subScene to \e self.
      \pre
      - \e subScene must be valid. */
  void merge( const ScenePtr& subScene );

  void save( const std::string& fname );

  /// Prints \e s to the output stream \e stream.
//  friend ostream& operator<<( ostream& stream, Scene& s );

  void lock() const ;
  void unlock() const;

protected:

  /// The list of shapes constituting the subScene.
  std::vector<GeomShape3DPtr> __shapeList;

#ifdef QT_THREAD_SUPPORT
  QMutex* __mutex;
#endif

};

/// Scene Pointer
typedef RCPtr<Scene> ScenePtr;


/* ----------------------------------------------------------------------- */

// __scne_scene_h__
/* ----------------------------------------------------------------------- */

GEOM_END_NAMESPACE

/// Write Scene \b s in \b stream.
GEOM_API std::ostream& operator<<( std::ostream& stream, GEOM(Scene&) s );

/* ----------------------------------------------------------------------- */
#endif


