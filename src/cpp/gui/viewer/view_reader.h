/* -*-c++-*-
 *  ----------------------------------------------------------------------------
 *
 *       AMAPmod: Exploring and Modeling Plant Architecture
 *
 *       Copyright 1995-2000 UMR Cirad/Inra Modelisation des Plantes
 *                           UMR PIAF INRA-UBP Clermont-Ferrand
 *
 *       File author(s): F. Boudon
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

/*! \file view_reader.h
    \brief Definition of the viewer classes ViewGeomReader, ViewGeomStreamReader, ViewMultiGeomReader and ViewLinetreeReader.
*/

#ifndef __view_reader_h__
#define __view_reader_h__

/* ----------------------------------------------------------------------- */

#ifdef QT_THREAD_SUPPORT

#include <qthread.h>
#include <qstring.h>
#include "scne_scene.h"

/* ----------------------------------------------------------------------- */

class ViewGeomSceneGL;

/* ----------------------------------------------------------------------- */
/**
   \class ViewGeomReader
   \brief Create a new thread to read a geom file

*/

/* ----------------------------------------------------------------------- */

class GEOM_API ViewGeomReader : public QThread
{

    public :


      ViewGeomReader(const QString& f,
                     ViewGeomSceneGL * g,
                     int i = -1,
                         bool add = false);

    ~ViewGeomReader();

    virtual void setFilename(const QString& f);

    const QString& getFilename() const ;

    void setMaxError(int i);

    protected :

      virtual void run();

    /// The file to read.
    QString _filename;

    /// The frame for given result.
    ViewGeomSceneGL * _g;

    /// Nb d'erreur max.
    int maxerror;

        bool addition;
};


/* ----------------------------------------------------------------------- */

/**
   \class ViewGeomStreamReader
   \brief Create a new thread to read a geom stream

*/
class GEOM_API ViewGeomStreamReader : public ViewGeomReader
{

    public :


      ViewGeomStreamReader(std::istream *stream,ViewGeomSceneGL * g,int i = -1) ;

    ~ViewGeomStreamReader();

    virtual void setStream(std::istream * stream);

    protected :

      virtual void run();

    /// The stream to read.
    std::istream * __stream;
};


/* ----------------------------------------------------------------------- */
/**
   \class ViewMultiGeomReader
   \brief Create a new thread to read a geom stream

*/
class GEOM_API ViewMultiGeomReader : public ViewGeomReader
{

    public :


      ViewMultiGeomReader(const QString& f1,
                          const QString& f2,
                          ViewGeomSceneGL * g,
                          int i = -1) ;

    ~ViewMultiGeomReader();

    virtual void setSecond(const QString&);

    const QString& getSecond() const;

    protected :

      virtual void run();

    /// The second file to read.
    QString __second;

};


/* ----------------------------------------------------------------------- */

/**
   \class ViewLinetreeReader
   \brief Create a new thread to read a linetree file

*/
class GEOM_API ViewLinetreeReader : public  ViewGeomReader {
    public :

      ViewLinetreeReader(const QString& ligFile,
                     const QString& dtaFile,
                     const QString& smbPath,
                     ViewGeomSceneGL * g,
					 bool bigendian = true,
                     bool add = false);

    ~ViewLinetreeReader();

    const QString& getLigFile() const;

    void setLigFile(const QString& f);

    const QString& getDtaFile() const;

    void setDtaFile(const QString& f);

    const QString& getSmbPath() const;

    void setSmbPath(const QString& f);


    protected :

      virtual void run();

    QString _dtaFile;

    QString _smbPath;

	bool _bigendian;
};

/* ----------------------------------------------------------------------- */


#endif

#endif

