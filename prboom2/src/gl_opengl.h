/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *   Thanks Roman "Vortex" Marchenko
 *---------------------------------------------------------------------
 */

#ifndef _GL_OPENGL_H
#define _GL_OPENGL_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define USE_VERTEX_ARRAYS
//#define USE_VBO

#include <GL/gl.h>
#include <GL/glext.h>

#include "doomtype.h"

extern dboolean gl_ext_arb_vertex_buffer_object;

/* VBO */
extern PFNGLGENBUFFERSARBPROC              GLEXT_glGenBuffersARB;
extern PFNGLDELETEBUFFERSARBPROC           GLEXT_glDeleteBuffersARB;
extern PFNGLBINDBUFFERARBPROC              GLEXT_glBindBufferARB;
extern PFNGLBUFFERDATAARBPROC              GLEXT_glBufferDataARB;
  
void gld_InitOpenGL();

//states
void gld_EnableTexture2D(int enable);

typedef enum
{
  TMF_MASKBIT = 1,
  TMF_OPAQUEBIT = 2,
  TMF_INVERTBIT = 4,

  TM_MODULATE = 0,
  TM_MASK = TMF_MASKBIT,
  TM_OPAQUE = TMF_OPAQUEBIT,
  TM_INVERT = TMF_INVERTBIT,
  //TM_INVERTMASK = TMF_MASKBIT | TMF_INVERTBIT
  TM_INVERTOPAQUE = TMF_INVERTBIT | TMF_OPAQUEBIT,
} tex_mode_e;
void SetTextureMode(tex_mode_e type);

#endif // _GL_OPENGL_H
