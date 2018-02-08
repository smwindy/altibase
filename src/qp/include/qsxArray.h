/** 
 *  Copyright (c) 1999~2017, Altibase Corp. and/or its affiliates. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License, version 3,
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 

/***********************************************************************
 * $Id: qsxArray.h 82075 2018-01-17 06:39:52Z jina.kim $
 *
 * Description :
 *     PROJ-1075 associative array info.
 *
 **********************************************************************/

#ifndef _O_QSX_ARRAY_H_
#define _O_QSX_ARRAY_H_ 1

#include <qc.h>
#include <iduMemListOld.h>
#include <qsParseTree.h>
#include <qsxAvl.h>

class qsxArray
{
 public :
    static IDE_RC initArray( qcStatement  *  aQcStmt,
                             qsxArrayInfo ** aArrayInfo,
                             qcmColumn    *  aColumn,
                             idvSQL       *  aStatistics );

    static IDE_RC finalizeArray( qsxArrayInfo ** aArrayInfo );

    static IDE_RC truncateArray( qsxArrayInfo * aArrayInfo );
    
    static IDE_RC searchKey( qcStatement  * aQcStmt,
                             qsxArrayInfo * aArrayInfo,
                             mtcColumn    * aKeyCol,
                             void         * aKey,
                             idBool         aInsert,
                             idBool       * aFound );

    static IDE_RC deleteOneElement( qsxArrayInfo * aArrayInfo,
                                    mtcColumn    * aKeyCol,
                                    void         * aKey,
                                    idBool       * aDeleted );

    static IDE_RC deleteElementsRange( qsxArrayInfo * aArrayInfo,
                                       mtcColumn    * aKeyMinCol,
                                       void         * aKeyMin,
                                       mtcColumn    * aKeyMaxCol,
                                       void         * aKeyMax,
                                       SInt         * aCount );
    
    static IDE_RC searchNext( qsxArrayInfo * aArrayInfo,
                              mtcColumn    * aKeyCol,
                              void         * aKey,
                              void        ** aNextKey,
                              idBool       * aFound );

    static IDE_RC searchPrior( qsxArrayInfo * aArrayInfo,
                               mtcColumn    * aKeyCol,
                               void         * aKey,
                               void        ** aPriorKey,
                               idBool       * aFound );

    static IDE_RC searchFirst( qsxArrayInfo * aArrayInfo,
                               void        ** aFirstKey,
                               idBool       * aFound );

    static IDE_RC searchLast( qsxArrayInfo * aArrayInfo,
                              void        ** aLastKey,
                              idBool       * aFound );

    // BUG-41311
    static IDE_RC searchNth( qsxArrayInfo * aArrayInfo,
                             UInt           aIndex,
                             void        ** aKey,
                             void        ** aData,
                             idBool       * aFound ); 

    static IDE_RC exists( qsxArrayInfo * aArrayInfo,
                          mtcColumn    * aKeyCol,
                          void         * aKey,
                          idBool       * aExists );

    static SInt getElementsCount( qsxArrayInfo * aArrayInfo );

    static IDE_RC assign( mtcTemplate  * aDstTemplate,
                          qsxArrayInfo * aDstArrayInfo,
                          qsxArrayInfo * aSrcArrayInfo );
};

#endif /* _O_QSX_ARRAY_H_ */

