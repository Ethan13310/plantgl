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



/*! \file actn_discretizer.h
    \brief Definition of the action class Discretizer.
*/


#ifndef __actn_discretizer_h__
#define __actn_discretizer_h__


#include "actn_action.h"
#include "Tools/rcobject.h"
#include "util_cache.h"
#ifndef GEOM_FWDEF
#include "geom_explicitmodel.h"
#include "geom_pointarray.h"
#endif

/* ----------------------------------------------------------------------- */

GEOM_BEGIN_NAMESPACE

/* ----------------------------------------------------------------------- */

#ifdef GEOM_FWDEF
class ExplicitModel;
typedef RCPtr<ExplicitModel> ExplicitModelPtr;
class Point2Array;
typedef RCPtr<Point2Array> Point2ArrayPtr;
class Point3Array;
typedef RCPtr<Point3Array> Point3ArrayPtr;
#endif

/* ----------------------------------------------------------------------- */

/**
   \class Discretizer
   \brief An action which computes the discretization of \e Geometry objects.
*/


class GEOM_API Discretizer : public Action
{

public:

  /// Constructs a Discretizer.
  Discretizer( );

  /// Destructor
  virtual ~Discretizer( );

  /// Clears \e self.
  void clear( );

  /// Returns the last computed discretized  geomety when applying \e self.
  const ExplicitModelPtr& getDiscretization( ) const;

  /// @name GeomShape
  //@{

  virtual bool process(GeomShape * geomShape);

  //@}

  /// @name Material
  //@{

  virtual bool process( Material * material );

  virtual bool process( MonoSpectral * monoSpectral );

  virtual bool process( MultiSpectral * multiSpectral );

  virtual bool process( ImageTexture * texture );
  //@}


  /// @name Geom3D
  //@{

  virtual bool process( AmapSymbol * amapSymbol );

  virtual bool process( AsymmetricHull * asymmetricHull );

  virtual bool process( AxisRotated * axisRotated );

  virtual bool process( BezierCurve * bezierCurve );

  virtual bool process( BezierPatch * bezierPatch );

  virtual bool process( Box * box );

  virtual bool process( Cone * cone );

  virtual bool process( Cylinder * cylinder );

  virtual bool process( ElevationGrid * elevationGrid );

  virtual bool process( EulerRotated * eulerRotated );

  virtual bool process( ExtrudedHull * extrudedHull );

  virtual bool process( FaceSet * faceSet );

  virtual bool process( Frustum * frustum );


  /** Applies \e self to an object of type Extrusion.
      Using Double-Cross Method To calculate Reference Frame along the Axis.
      See Bloomenthal Thesis, chap 5, for more Details.
      \warning
      - \e extrusion must be non null and valid.*/
  virtual bool process( Extrusion * extrusion );

  virtual bool process( Group * group );

  virtual bool process( IFS * ifs );

  virtual bool process( NurbsCurve * nurbsCurve );

  virtual bool process( NurbsPatch * nurbsPatch );

  virtual bool process( Oriented * oriented );

  virtual bool process( Paraboloid * paraboloid );

  virtual bool process( PointSet * pointSet );

  virtual bool process( GeomPolyline * polyline );

  virtual bool process( QuadSet * quadSet );

  virtual bool process( Revolution * revolution );

  virtual bool process( Swung * swung );

  virtual bool process( Scaled * scaled );

  virtual bool process( Sphere * sphere );

  virtual bool process( Tapered * tapered );

  virtual bool process( Translated * translated );

  virtual bool process( TriangleSet * triangleSet );

  //@}

  /// @name Geom2D
  //@{


  virtual bool process( BezierCurve2D * bezierCurve );

  virtual bool process( Disc * disc );

  virtual bool process( NurbsCurve2D * nurbsCurve );

  virtual bool process( PointSet2D * pointSet );

  virtual bool process( GeomPolyline2D * polyline );

  //@}

  virtual bool process( Text * text );

  virtual bool process( Font * font );

  bool texCoordComputed() const {
	return __computeTexCoord; }

  void computeTexCoord(bool b) { __computeTexCoord = b; }

  Point2ArrayPtr gridTexCoord(Point3ArrayPtr pts, int gw, int gh) const;

protected:

  /// The cache storing the already discretized geometries.
  Cache<ExplicitModelPtr> __cache;

  /// The last computed discretized geometry.
  ExplicitModelPtr __discretization;

  bool __computeTexCoord;

};


/* ----------------------------------------------------------------------- */

GEOM_END_NAMESPACE

/* ------------------------------------------------------------------------*/

// __actn_discretizer_h__
#endif


