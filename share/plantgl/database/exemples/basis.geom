 # -Geom File-
(# --------------------------------------------------
 #  
 #  File : /home/fboudon/PovRay/Test/basis.geom
 #  
 #  File Author : fboudon
 #  Date : 10/9/2001 at 17:25:48
 #  
 #  This file was generated by the Geom 3D Viewer.
 #  Published under the GNU General Public Licence. 
 #  
 # --------------------------------------------------
 #)

:include basis_mat.geom


Box origin { 
    Size <1,1,1>
}

Shape SHAPE_1089524684 { 
    Geometry  origin
    Appearance  Default
}

Group arrow { 
    GeometryList [ 
        Cylinder { 
            Radius 0.2
            Height 8
        }, Translated { 
            Translation <0,0,8>
            Geometry Cone { 
                Radius 1
                Height 2
            }
        }
    ]
}

Shape SHAPE_1089476104 { 
    Geometry  arrow
    Appearance  Material {
	Ambient Red
	}
}

Oriented x { 
    Primary <0,1,0>
    Secondary <0,0,1>
    Geometry arrow

}

Shape SHAPE_1089550552 { 
    Geometry  x
    Appearance  Material {
	Ambient Green
	}
}

Oriented y { 
    Primary <0,0,1>
    Secondary <1,0,0>
    Geometry arrow

}

Shape SHAPE_1089524808 { 
    Geometry  y
    Appearance  Material {
	Ambient Blue
	}
}

