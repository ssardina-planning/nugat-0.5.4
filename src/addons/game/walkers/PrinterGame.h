/**CHeaderFile*****************************************************************

  FileName    [ PrinterGame.h ]

  PackageName [ game.walkers ]

  Synopsis    [ Public interface of class 'PrinterGame' ]

  Description [ ]

  SeeAlso     [ PrinterGame.c ]

  Author      [ Andrei Tchaltsev ]

  Copyright   [
  This file is part of the ``game.walkers'' package of NuGaT.
  Copyright (C) 2010 by FBK-irst.

  NuGaT is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  NuGaT is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA.

  For more information on NuGaT see <http://es.fbk.eu/tools/nugat>
  or email to <nugat-users@list.fbk.eu>.
  Please report bugs to <nugat-users@list.fbk.eu>.

  To contact the NuGaT development board, email to <nugat@list.fbk.eu>. ]

  Revision    [$Id: PrinterGame.h,v 1.1.2.2 2010-02-08 14:39:01 nusmv Exp $]

******************************************************************************/

#ifndef __PRINTER_GAME__H__
#define __PRINTER_GAME__H__

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "utils/utils.h"

/*---------------------------------------------------------------------------*/
/* Constant declarations                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/

/**Type***********************************************************************

  Synopsis    [ Definition of the public accessor for class PrinterGame. ]

  Description [ ]

  SeeAlso     [ ]

******************************************************************************/
typedef struct PrinterGame_TAG* PrinterGame_ptr;

/*---------------------------------------------------------------------------*/
/* Structure declarations                                                    */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Variable declarations                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Macro declarations                                                        */
/*---------------------------------------------------------------------------*/

/**Macros**********************************************************************

  Synopsis    [ To cast and check instances of class PrinterGame. ]

  Description [ These macros must be used respectively to cast and to
                check instances of class PrinterGame. ]

******************************************************************************/
#define PRINTER_GAME(self) ((PrinterGame_ptr) self)
#define PRINTER_GAME_CHECK_INSTANCE(self) \
         (nusmv_assert(PRINTER_GAME(self) != PRINTER_GAME(NULL)))

/**AutomaticStart*************************************************************/

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/
EXTERN PrinterGame_ptr PrinterGame_create ARGS((const char* name));

/**AutomaticEnd***************************************************************/

#endif /* __PRINTER_GAME_H__ */
