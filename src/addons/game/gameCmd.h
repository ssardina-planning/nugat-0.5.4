/**CHeaderFile*****************************************************************

  FileName    [ gameCmd.h ]

  PackageName [ game ]

  Synopsis    [ Public interface of 'gameCmd' ]

  Description [ ]

  SeeAlso     [ ]

  Author      [ Viktor Schuppan ]

  Copyright   [
  This file is part of the ``game'' package of NuGaT.
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

  Revision    [$Id: GameStrategy.h,v 1.1.2.3 2010-02-04 15:42:36 nusmv Exp $]

******************************************************************************/

#ifndef __GAME_CMD_H__
#define __GAME_CMD_H__

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include "utils/utils.h"
#include "utils/NodeList.h"

/*---------------------------------------------------------------------------*/
/* Type declarations                                                         */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Macro declarations                                                        */
/*---------------------------------------------------------------------------*/

/**AutomaticStart*************************************************************/

/*---------------------------------------------------------------------------*/
/* Function prototypes                                                       */
/*---------------------------------------------------------------------------*/

EXTERN void Game_init_cmd ARGS((void));
EXTERN void Game_quit_cmd ARGS((void));
EXTERN NodeList_ptr Game_cmd_get_generic_commands ARGS((void));
EXTERN NodeList_ptr Game_cmd_get_dependent_commands ARGS((void));
EXTERN NodeList_ptr Game_cmd_get_specific_commands ARGS((void));

/**AutomaticEnd***************************************************************/

#endif /* __GAME_CMD_H__ */
