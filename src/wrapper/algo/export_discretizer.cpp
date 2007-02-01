/* -*-c++-*-
 *  ----------------------------------------------------------------------------
 *
 *       GeomPy: Python wrapper for the Plant Graphic Library
 *
 *       Copyright 1995-2003 UMR AMAP 
 *
 *       File author(s): C. Pradal (christophe.pradal@cirad.fr)
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

#include "discretizer.h"

#include <boost/python.hpp>

#include "actn_discretizer.h"
#include "actn_tesselator.h"
#include "geom_explicitmodel.h"
#include "geom_triangleset.h"

#include "macro_refptr.h"
#include "macro_property.h"

GEOM_USING_NAMESPACE
TOOLS_USING_NAMESPACE
using namespace boost::python;
using namespace std;

ExplicitModelPtr d_getDiscretization( Discretizer* d )
{ return d->getDiscretization(); }

bool get_Dis_texCoord(Discretizer * obj){ 
  return obj->texCoordComputed(); 
} 
void set_Dis_texCoord(Discretizer * obj, bool v){ 
  obj->computeTexCoord(v); 
} 

void class_Discretizer()
{
  class_< Discretizer,bases< Action >,boost::noncopyable >
    ("Discretizer", init<>("Discretizer() -> Compute the objects discretization" ))
    .def("clear",&Discretizer::clear)
    .def("getDiscretization",d_getDiscretization,
	 "Return the last computed discretization.")
	 .add_property("texCoord",get_Dis_texCoord,set_Dis_texCoord)
    ;
}

TriangleSetPtr 	t_getTriangulation ( Tesselator* t )
{ return t->getTriangulation(); }

void class_Tesselator()
{
  class_< Tesselator,bases< Discretizer >,boost::noncopyable >
    ("Tesselator", init<>("Tesselator() -> Compute tobjects triangulation. " ))
    .def("getTriangulation",t_getTriangulation,
	 "Return the last computed triangulation.")
    ;

}
