# 0 "chafa-term-seq-doc-in.h"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4

# 1 "/usr/include/stdc-predef.h" 3 4
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */




/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */

/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
# 56 "/usr/include/stdc-predef.h" 3 4
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
# 0 "<command-line>" 2
# 1 "chafa-term-seq-doc-in.h"

# 1 "chafa-term-seq-doc-in.h"
/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/* Copyright (C) 2020-2022 Hans Petter Jansson
 *
 * This file is part of Chafa, a program that turns images into character art.
 *
 * Chafa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chafa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Chafa.  If not, see <http://www.gnu.org/licenses/>. */



# 1 "chafa-term-seq-def.h" 1
/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/* Copyright (C) 2020-2022 Hans Petter Jansson
 *
 * This file is part of Chafa, a program that turns images into character art.
 *
 * Chafa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chafa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Chafa.  If not, see <http://www.gnu.org/licenses/>. */

/* Terminal sequence definitions
 * -----------------------------
 *
 * This file is #included in various contexts with CHAFA_TERM_SEQ_DEF()
 * expanding to different things. It allows us to keep all the terminal
 * sequence metadata in one place.
 *
 * We process this file with 'cpp -CC' to let the docstrings through to
 * gtk-doc.
 *
 * The generator macro is invoked with the following arguments:
 *
 * CHAFA_TERM_SEQ_DEF (name, NAME, n_args, args_proc, args_type, ...)
 *
 * Sequences are grouped by the library version they became available in,
 * with CHAFA_TERM_SEQ_AVAILABILITY expanding to the appropriate version
 * macro in each case.
 *
 * The actual sequence strings are not defined here; they belong to the
 * individual terminal model definitions.
 *
 * References
 * ----------
 *
 * VT220 sequences: https://vt100.net/docs/vt220-rm/chapter4.html
 * Sixels: https://vt100.net/docs/vt3xx-gp/chapter14.html
 */

/* For zero-argument functions, we use "char" as the argument type instead
 * of the more appropriate "void", since we need to be able to use it with
 * sizeof() and -Wpointer-arith. */

/* __VA_OPT__ from C++2a would be nice, but it's too recent to rely on in
 * public headers just yet. So we have this exciting trick instead. */


/* --- Available in 1.6+ --- */



/**
 * chafa_term_info_emit_reset_terminal_soft:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_TERMINAL_SOFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_reset_terminal_soft (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_reset_terminal_hard:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_TERMINAL_HARD.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_reset_terminal_hard (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_reset_attributes:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_ATTRIBUTES.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_reset_attributes (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_clear:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CLEAR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_clear (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_invert_colors:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INVERT_COLORS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_invert_colors (const ChafaTermInfo *term_info, gchar *dest );

/* Cursor movement. Cursor stops at margins. */

/**
 * chafa_term_info_emit_cursor_to_top_left:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_TO_TOP_LEFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_to_top_left (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_cursor_to_bottom_left:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_TO_BOTTOM_LEFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_to_bottom_left (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_cursor_to_pos:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @x: Offset from left edge of display, zero-indexed
 * @y: Offset from top edge of display, zero-indexed
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_TO_POS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_to_pos (const ChafaTermInfo *term_info, gchar *dest , guint x, guint y);

/**
 * chafa_term_info_emit_cursor_up_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_UP_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_up_1 (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_cursor_up:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_UP.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_up (const ChafaTermInfo *term_info, gchar *dest , guint n);

/**
 * chafa_term_info_emit_cursor_down_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_DOWN_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_down_1 (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_cursor_down:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_DOWN.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_down (const ChafaTermInfo *term_info, gchar *dest , guint n);

/**
 * chafa_term_info_emit_cursor_left_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_LEFT_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_left_1 (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_cursor_left:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_LEFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_left (const ChafaTermInfo *term_info, gchar *dest , guint n);

/**
 * chafa_term_info_emit_cursor_right_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_RIGHT_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_right_1 (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_cursor_right:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_RIGHT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_right (const ChafaTermInfo *term_info, gchar *dest , guint n);

/* Cursor movement. Cursor crossing margin causes scrolling region to
 * scroll. */

/**
 * chafa_term_info_emit_cursor_up_scroll:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_UP_SCROLL.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_up_scroll (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_cursor_down_scroll:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_DOWN_SCROLL.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_cursor_down_scroll (const ChafaTermInfo *term_info, gchar *dest );

/* Cells will shift on insert. Cells shifted off the edge will be lost. */

/**
 * chafa_term_info_emit_insert_cells:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of cells to insert
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_CELLS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_insert_cells (const ChafaTermInfo *term_info, gchar *dest , guint n);

/**
 * chafa_term_info_emit_delete_cells:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of cells to delete
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_CELLS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_delete_cells (const ChafaTermInfo *term_info, gchar *dest , guint n);

/* Cursor must be inside scrolling region. Rows are shifted inside the
 * scrolling region. Rows shifted off the edge will be lost. The cursor
 * position is reset to the first column. */

/**
 * chafa_term_info_emit_insert_rows:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of rows to insert
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_ROWS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_insert_rows (const ChafaTermInfo *term_info, gchar *dest , guint n);

/**
 * chafa_term_info_emit_delete_rows:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of rows to delete
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_ROWS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_delete_rows (const ChafaTermInfo *term_info, gchar *dest , guint n);

/* Defines the scrolling region. */

/**
 * chafa_term_info_emit_set_scrolling_rows:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @top: First row in scrolling area, zero-indexed
 * @bottom: Last row in scrolling area, zero-indexed
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_SCROLLING_ROWS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_scrolling_rows (const ChafaTermInfo *term_info, gchar *dest , guint top, guint bottom);

/* Indicates whether characters printed in the middle of a row should
 * cause subsequent cells to shift forwards. Cells shifted off the edge
 * will be lost. If disabled, cells at the cursor position will be
 * overwritten instead. */

/**
 * chafa_term_info_emit_enable_insert:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_INSERT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_enable_insert (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_disable_insert:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_INSERT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_disable_insert (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_enable_cursor:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_CURSOR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_enable_cursor (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_disable_cursor:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_CURSOR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_disable_cursor (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_enable_echo:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_ECHO.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_enable_echo (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_disable_echo:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_ECHO.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_disable_echo (const ChafaTermInfo *term_info, gchar *dest );

/* When printing a character in the last column, indicates whether the
 * cursor should move to the next row and potentially cause scrolling. If
 * disabled, the cursor may still move to the first column. */

/**
 * chafa_term_info_emit_enable_wrap:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_WRAP.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_enable_wrap (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_disable_wrap:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_WRAP.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_disable_wrap (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_set_color_fg_direct:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component, 0-255
 * @g: Green component, 0-255
 * @b: Blue component, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_DIRECT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_fg_direct (const ChafaTermInfo *term_info, gchar *dest , guint8 r, guint8 g, guint8 b);

/**
 * chafa_term_info_emit_set_color_bg_direct:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component, 0-255
 * @g: Green component, 0-255
 * @b: Blue component, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_DIRECT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_bg_direct (const ChafaTermInfo *term_info, gchar *dest , guint8 r, guint8 g, guint8 b);

/**
 * chafa_term_info_emit_set_color_fgbg_direct:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_r: Foreground red component, 0-255
 * @fg_g: Foreground green component, 0-255
 * @fg_b: Foreground blue component, 0-255
 * @bg_r: Background red component, 0-255
 * @bg_g: Background green component, 0-255
 * @bg_b: Background blue component, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_DIRECT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_fgbg_direct (const ChafaTermInfo *term_info, gchar *dest , guint8 fg_r, guint8 fg_g, guint8 fg_b, guint8 bg_r, guint8 bg_g, guint8 bg_b);

/**
 * chafa_term_info_emit_set_color_fg_256:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_256.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_fg_256 (const ChafaTermInfo *term_info, gchar *dest , guint8 pen);

/**
 * chafa_term_info_emit_set_color_bg_256:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_256.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_bg_256 (const ChafaTermInfo *term_info, gchar *dest , guint8 pen);

/**
 * chafa_term_info_emit_set_color_fgbg_256:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_pen: Foreground pen number, 0-255
 * @bg_pen: Background pen number, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_256.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_fgbg_256 (const ChafaTermInfo *term_info, gchar *dest , guint8 fg_pen, guint8 bg_pen);

/**
 * chafa_term_info_emit_set_color_fg_16:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-15
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_16.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_fg_16 (const ChafaTermInfo *term_info, gchar *dest , guint8 pen);

/**
 * chafa_term_info_emit_set_color_bg_16:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-15
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_16.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_bg_16 (const ChafaTermInfo *term_info, gchar *dest , guint8 pen);

/**
 * chafa_term_info_emit_set_color_fgbg_16:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_pen: Foreground pen number, 0-15
 * @bg_pen: Background pen number, 0-15
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_16.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_set_color_fgbg_16 (const ChafaTermInfo *term_info, gchar *dest , guint8 fg_pen, guint8 bg_pen);

/**
 * chafa_term_info_emit_begin_sixels:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @p1: Pixel aspect selector
 * @p2: Background color selector
 * @p3: Horizontal grid selector
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_SIXELS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * All three parameters (@p1, @p2 and @p3) can normally be set to 0.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_begin_sixels (const ChafaTermInfo *term_info, gchar *dest , guint p1, guint p2, guint p3);

/**
 * chafa_term_info_emit_end_sixels:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_SIXELS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_end_sixels (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_repeat_char:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of repetitions
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_REPEAT_CHAR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
gchar *chafa_term_info_emit_repeat_char (const ChafaTermInfo *term_info, gchar *dest , guint n);

/* --- Available in 1.8+ --- */




/**
 * chafa_term_info_emit_begin_kitty_immediate_image_v1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @bpp: Bits per pixel
 * @width_pixels: Image width in pixels
 * @height_pixels: Image height in pixels
 * @width_cells: Target width in cells
 * @height_cells: Target height in cells
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_KITTY_IMMEDIATE_IMAGE_V1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * @bpp must be set to either 24 for RGB data, 32 for RGBA, or 100 to embed a
 * PNG file.
 *
 * This sequence must be followed by zero or more paired sequences of
 * type #CHAFA_TERM_SEQ_BEGIN_KITTY_IMAGE_CHUNK and #CHAFA_TERM_SEQ_END_KITTY_IMAGE_CHUNK
 * with base-64 encoded image data between them.
 *
 * When the image data has been transferred, #CHAFA_TERM_SEQ_END_KITTY_IMAGE must
 * be emitted.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
gchar *chafa_term_info_emit_begin_kitty_immediate_image_v1 (const ChafaTermInfo *term_info, gchar *dest , guint bpp, guint width_pixels, guint height_pixels, guint width_cells, guint height_cells);

/**
 * chafa_term_info_emit_end_kitty_image:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_KITTY_IMAGE.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
gchar *chafa_term_info_emit_end_kitty_image (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_begin_kitty_image_chunk:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_KITTY_IMAGE_CHUNK.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
gchar *chafa_term_info_emit_begin_kitty_image_chunk (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_end_kitty_image_chunk:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_KITTY_IMAGE_CHUNK.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
gchar *chafa_term_info_emit_end_kitty_image_chunk (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_begin_iterm2_image:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @width: Image width in character cells
 * @height: Image height in character cells
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_ITERM2_IMAGE.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * This sequence must be followed by base64-encoded image file data. The image
 * can be any format supported by MacOS, e.g. PNG, JPEG, TIFF, GIF. When the
 * image data has been transferred, #CHAFA_TERM_SEQ_END_ITERM2_IMAGE must be
 * emitted.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
gchar *chafa_term_info_emit_begin_iterm2_image (const ChafaTermInfo *term_info, gchar *dest , guint width, guint height);

/**
 * chafa_term_info_emit_end_iterm2_image:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_ITERM2_IMAGE.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
gchar *chafa_term_info_emit_end_iterm2_image (const ChafaTermInfo *term_info, gchar *dest );

/* --- Available in 1.10+ --- */




/**
 * chafa_term_info_emit_enable_sixel_scrolling:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_SIXEL_SCROLLING.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.10
 **/
gchar *chafa_term_info_emit_enable_sixel_scrolling (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_disable_sixel_scrolling:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_SIXEL_SCROLLING.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.10
 **/
gchar *chafa_term_info_emit_disable_sixel_scrolling (const ChafaTermInfo *term_info, gchar *dest );

/* --- Available in 1.12+ --- */




/**
 * chafa_term_info_emit_enable_bold:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_BOLD.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
gchar *chafa_term_info_emit_enable_bold (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_set_color_fg_8:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-7
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_8.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
gchar *chafa_term_info_emit_set_color_fg_8 (const ChafaTermInfo *term_info, gchar *dest , guint8 pen);

/**
 * chafa_term_info_emit_set_color_bg_8:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-7
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_8.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
gchar *chafa_term_info_emit_set_color_bg_8 (const ChafaTermInfo *term_info, gchar *dest , guint8 pen);

/**
 * chafa_term_info_emit_set_color_fgbg_8:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_pen: Foreground pen number, 0-7
 * @bg_pen: Background pen number, 0-7
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_8.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
gchar *chafa_term_info_emit_set_color_fgbg_8 (const ChafaTermInfo *term_info, gchar *dest , guint8 fg_pen, guint8 bg_pen);

/* --- Available in 1.14+ --- */




/**
 * chafa_term_info_emit_reset_default_fg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_DEFAULT_FG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_reset_default_fg (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_set_default_fg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component (0-65535)
 * @g: Green component (0-65535)
 * @b: Blue component (0-65535)
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_DEFAULT_FG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_set_default_fg (const ChafaTermInfo *term_info, gchar *dest , guint16 r, guint16 g, guint16 b);

/**
 * chafa_term_info_emit_query_default_fg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_QUERY_DEFAULT_FG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_query_default_fg (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_reset_default_bg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_DEFAULT_BG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_reset_default_bg (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_set_default_bg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component (0-65535)
 * @g: Green component (0-65535)
 * @b: Blue component (0-65535)
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_DEFAULT_BG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_set_default_bg (const ChafaTermInfo *term_info, gchar *dest , guint16 r, guint16 g, guint16 b);

/**
 * chafa_term_info_emit_query_default_bg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_QUERY_DEFAULT_BG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_query_default_bg (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_tab_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_TAB_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_tab_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_up_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_UP_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_up_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_up_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_UP_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_up_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_up_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_UP_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_up_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_down_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DOWN_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_down_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_down_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DOWN_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_down_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_down_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DOWN_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_down_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_left_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_LEFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_left_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_left_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_LEFT_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_left_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_left_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_LEFT_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_left_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_right_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RIGHT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_right_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_right_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RIGHT_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_right_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_right_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RIGHT_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_right_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_page_up_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_UP_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_page_up_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_page_up_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_UP_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_page_up_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_page_up_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_UP_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_page_up_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_page_down_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_DOWN_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_page_down_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_page_down_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_DOWN_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_page_down_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_page_down_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_DOWN_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_page_down_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_home_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_HOME_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_home_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_home_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_HOME_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_home_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_home_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_HOME_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_home_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_end_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_end_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_end_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_end_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_end_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_end_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_insert_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_insert_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_insert_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_insert_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_insert_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_insert_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_delete_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_delete_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_delete_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_delete_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_delete_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_delete_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f1_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F1_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f1_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f1_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F1_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f1_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f1_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F1_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f1_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f2_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F2_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f2_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f2_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F2_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f2_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f2_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F2_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f2_shift_key (const ChafaTermInfo *term_info, gchar *dest );


/**
 * chafa_term_info_emit_f3_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F3_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f3_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f3_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F3_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f3_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f3_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F3_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f3_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f4_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F4_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f4_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f4_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F4_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f4_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f4_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F4_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f4_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f5_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F5_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f5_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f5_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F5_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f5_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f5_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F5_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f5_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f6_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F6_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f6_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f6_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F6_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f6_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f6_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F6_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f6_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f7_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F7_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f7_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f7_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F7_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f7_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f7_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F7_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f7_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f8_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F8_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f8_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f8_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F8_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f8_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f8_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F8_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f8_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f9_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F9_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f9_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f9_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F9_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f9_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f9_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F9_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f9_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f10_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F10_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f10_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f10_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F10_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f10_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f10_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F10_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f10_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f11_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F11_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f11_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f11_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F11_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f11_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f11_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F11_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f11_shift_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f12_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F12_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f12_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f12_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F12_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f12_ctrl_key (const ChafaTermInfo *term_info, gchar *dest );

/**
 * chafa_term_info_emit_f12_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F12_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
gchar *chafa_term_info_emit_f12_shift_key (const ChafaTermInfo *term_info, gchar *dest );
# 23 "chafa-term-seq-doc-in.h" 2


typedef enum
{

# 1 "chafa-term-seq-def.h" 1
/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/* Copyright (C) 2020-2022 Hans Petter Jansson
 *
 * This file is part of Chafa, a program that turns images into character art.
 *
 * Chafa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chafa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Chafa.  If not, see <http://www.gnu.org/licenses/>. */

/* Terminal sequence definitions
 * -----------------------------
 *
 * This file is #included in various contexts with CHAFA_TERM_SEQ_DEF()
 * expanding to different things. It allows us to keep all the terminal
 * sequence metadata in one place.
 *
 * We process this file with 'cpp -CC' to let the docstrings through to
 * gtk-doc.
 *
 * The generator macro is invoked with the following arguments:
 *
 * CHAFA_TERM_SEQ_DEF (name, NAME, n_args, args_proc, args_type, ...)
 *
 * Sequences are grouped by the library version they became available in,
 * with CHAFA_TERM_SEQ_AVAILABILITY expanding to the appropriate version
 * macro in each case.
 *
 * The actual sequence strings are not defined here; they belong to the
 * individual terminal model definitions.
 *
 * References
 * ----------
 *
 * VT220 sequences: https://vt100.net/docs/vt220-rm/chapter4.html
 * Sixels: https://vt100.net/docs/vt3xx-gp/chapter14.html
 */

/* For zero-argument functions, we use "char" as the argument type instead
 * of the more appropriate "void", since we need to be able to use it with
 * sizeof() and -Wpointer-arith. */

/* __VA_OPT__ from C++2a would be nice, but it's too recent to rely on in
 * public headers just yet. So we have this exciting trick instead. */


/* --- Available in 1.6+ --- */



/**
 * chafa_term_info_emit_reset_terminal_soft:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_TERMINAL_SOFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_RESET_TERMINAL_SOFT,

/**
 * chafa_term_info_emit_reset_terminal_hard:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_TERMINAL_HARD.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_RESET_TERMINAL_HARD,

/**
 * chafa_term_info_emit_reset_attributes:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_ATTRIBUTES.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_RESET_ATTRIBUTES,

/**
 * chafa_term_info_emit_clear:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CLEAR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CLEAR,

/**
 * chafa_term_info_emit_invert_colors:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INVERT_COLORS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_INVERT_COLORS,

/* Cursor movement. Cursor stops at margins. */

/**
 * chafa_term_info_emit_cursor_to_top_left:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_TO_TOP_LEFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_TO_TOP_LEFT,

/**
 * chafa_term_info_emit_cursor_to_bottom_left:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_TO_BOTTOM_LEFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_TO_BOTTOM_LEFT,

/**
 * chafa_term_info_emit_cursor_to_pos:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @x: Offset from left edge of display, zero-indexed
 * @y: Offset from top edge of display, zero-indexed
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_TO_POS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_TO_POS,

/**
 * chafa_term_info_emit_cursor_up_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_UP_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_UP_1,

/**
 * chafa_term_info_emit_cursor_up:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_UP.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_UP,

/**
 * chafa_term_info_emit_cursor_down_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_DOWN_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_DOWN_1,

/**
 * chafa_term_info_emit_cursor_down:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_DOWN.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_DOWN,

/**
 * chafa_term_info_emit_cursor_left_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_LEFT_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_LEFT_1,

/**
 * chafa_term_info_emit_cursor_left:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_LEFT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_LEFT,

/**
 * chafa_term_info_emit_cursor_right_1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_RIGHT_1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_RIGHT_1,

/**
 * chafa_term_info_emit_cursor_right:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Distance to move the cursor
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_RIGHT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_RIGHT,

/* Cursor movement. Cursor crossing margin causes scrolling region to
 * scroll. */

/**
 * chafa_term_info_emit_cursor_up_scroll:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_UP_SCROLL.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_UP_SCROLL,

/**
 * chafa_term_info_emit_cursor_down_scroll:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_CURSOR_DOWN_SCROLL.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_CURSOR_DOWN_SCROLL,

/* Cells will shift on insert. Cells shifted off the edge will be lost. */

/**
 * chafa_term_info_emit_insert_cells:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of cells to insert
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_CELLS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_INSERT_CELLS,

/**
 * chafa_term_info_emit_delete_cells:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of cells to delete
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_CELLS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_DELETE_CELLS,

/* Cursor must be inside scrolling region. Rows are shifted inside the
 * scrolling region. Rows shifted off the edge will be lost. The cursor
 * position is reset to the first column. */

/**
 * chafa_term_info_emit_insert_rows:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of rows to insert
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_ROWS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_INSERT_ROWS,

/**
 * chafa_term_info_emit_delete_rows:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of rows to delete
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_ROWS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_DELETE_ROWS,

/* Defines the scrolling region. */

/**
 * chafa_term_info_emit_set_scrolling_rows:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @top: First row in scrolling area, zero-indexed
 * @bottom: Last row in scrolling area, zero-indexed
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_SCROLLING_ROWS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_SCROLLING_ROWS,

/* Indicates whether characters printed in the middle of a row should
 * cause subsequent cells to shift forwards. Cells shifted off the edge
 * will be lost. If disabled, cells at the cursor position will be
 * overwritten instead. */

/**
 * chafa_term_info_emit_enable_insert:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_INSERT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_ENABLE_INSERT,

/**
 * chafa_term_info_emit_disable_insert:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_INSERT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_DISABLE_INSERT,

/**
 * chafa_term_info_emit_enable_cursor:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_CURSOR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_ENABLE_CURSOR,

/**
 * chafa_term_info_emit_disable_cursor:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_CURSOR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_DISABLE_CURSOR,

/**
 * chafa_term_info_emit_enable_echo:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_ECHO.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_ENABLE_ECHO,

/**
 * chafa_term_info_emit_disable_echo:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_ECHO.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_DISABLE_ECHO,

/* When printing a character in the last column, indicates whether the
 * cursor should move to the next row and potentially cause scrolling. If
 * disabled, the cursor may still move to the first column. */

/**
 * chafa_term_info_emit_enable_wrap:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_WRAP.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_ENABLE_WRAP,

/**
 * chafa_term_info_emit_disable_wrap:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_WRAP.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_DISABLE_WRAP,

/**
 * chafa_term_info_emit_set_color_fg_direct:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component, 0-255
 * @g: Green component, 0-255
 * @b: Blue component, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_DIRECT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_FG_DIRECT,

/**
 * chafa_term_info_emit_set_color_bg_direct:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component, 0-255
 * @g: Green component, 0-255
 * @b: Blue component, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_DIRECT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_BG_DIRECT,

/**
 * chafa_term_info_emit_set_color_fgbg_direct:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_r: Foreground red component, 0-255
 * @fg_g: Foreground green component, 0-255
 * @fg_b: Foreground blue component, 0-255
 * @bg_r: Background red component, 0-255
 * @bg_g: Background green component, 0-255
 * @bg_b: Background blue component, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_DIRECT.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_FGBG_DIRECT,

/**
 * chafa_term_info_emit_set_color_fg_256:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_256.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_FG_256,

/**
 * chafa_term_info_emit_set_color_bg_256:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_256.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_BG_256,

/**
 * chafa_term_info_emit_set_color_fgbg_256:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_pen: Foreground pen number, 0-255
 * @bg_pen: Background pen number, 0-255
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_256.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_FGBG_256,

/**
 * chafa_term_info_emit_set_color_fg_16:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-15
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_16.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_FG_16,

/**
 * chafa_term_info_emit_set_color_bg_16:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-15
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_16.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_BG_16,

/**
 * chafa_term_info_emit_set_color_fgbg_16:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_pen: Foreground pen number, 0-15
 * @bg_pen: Background pen number, 0-15
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_16.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_SET_COLOR_FGBG_16,

/**
 * chafa_term_info_emit_begin_sixels:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @p1: Pixel aspect selector
 * @p2: Background color selector
 * @p3: Horizontal grid selector
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_SIXELS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * All three parameters (@p1, @p2 and @p3) can normally be set to 0.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_BEGIN_SIXELS,

/**
 * chafa_term_info_emit_end_sixels:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_SIXELS.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_END_SIXELS,

/**
 * chafa_term_info_emit_repeat_char:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @n: Number of repetitions
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_REPEAT_CHAR.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.6
 **/
CHAFA_TERM_SEQ_REPEAT_CHAR,

/* --- Available in 1.8+ --- */




/**
 * chafa_term_info_emit_begin_kitty_immediate_image_v1:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @bpp: Bits per pixel
 * @width_pixels: Image width in pixels
 * @height_pixels: Image height in pixels
 * @width_cells: Target width in cells
 * @height_cells: Target height in cells
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_KITTY_IMMEDIATE_IMAGE_V1.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * @bpp must be set to either 24 for RGB data, 32 for RGBA, or 100 to embed a
 * PNG file.
 *
 * This sequence must be followed by zero or more paired sequences of
 * type #CHAFA_TERM_SEQ_BEGIN_KITTY_IMAGE_CHUNK and #CHAFA_TERM_SEQ_END_KITTY_IMAGE_CHUNK
 * with base-64 encoded image data between them.
 *
 * When the image data has been transferred, #CHAFA_TERM_SEQ_END_KITTY_IMAGE must
 * be emitted.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
CHAFA_TERM_SEQ_BEGIN_KITTY_IMMEDIATE_IMAGE_V1,

/**
 * chafa_term_info_emit_end_kitty_image:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_KITTY_IMAGE.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
CHAFA_TERM_SEQ_END_KITTY_IMAGE,

/**
 * chafa_term_info_emit_begin_kitty_image_chunk:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_KITTY_IMAGE_CHUNK.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
CHAFA_TERM_SEQ_BEGIN_KITTY_IMAGE_CHUNK,

/**
 * chafa_term_info_emit_end_kitty_image_chunk:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_KITTY_IMAGE_CHUNK.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
CHAFA_TERM_SEQ_END_KITTY_IMAGE_CHUNK,

/**
 * chafa_term_info_emit_begin_iterm2_image:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @width: Image width in character cells
 * @height: Image height in character cells
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_BEGIN_ITERM2_IMAGE.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * This sequence must be followed by base64-encoded image file data. The image
 * can be any format supported by MacOS, e.g. PNG, JPEG, TIFF, GIF. When the
 * image data has been transferred, #CHAFA_TERM_SEQ_END_ITERM2_IMAGE must be
 * emitted.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
CHAFA_TERM_SEQ_BEGIN_ITERM2_IMAGE,

/**
 * chafa_term_info_emit_end_iterm2_image:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_ITERM2_IMAGE.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.8
 **/
CHAFA_TERM_SEQ_END_ITERM2_IMAGE,

/* --- Available in 1.10+ --- */




/**
 * chafa_term_info_emit_enable_sixel_scrolling:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_SIXEL_SCROLLING.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.10
 **/
CHAFA_TERM_SEQ_ENABLE_SIXEL_SCROLLING,

/**
 * chafa_term_info_emit_disable_sixel_scrolling:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DISABLE_SIXEL_SCROLLING.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.10
 **/
CHAFA_TERM_SEQ_DISABLE_SIXEL_SCROLLING,

/* --- Available in 1.12+ --- */




/**
 * chafa_term_info_emit_enable_bold:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_ENABLE_BOLD.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
CHAFA_TERM_SEQ_ENABLE_BOLD,

/**
 * chafa_term_info_emit_set_color_fg_8:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-7
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FG_8.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
CHAFA_TERM_SEQ_SET_COLOR_FG_8,

/**
 * chafa_term_info_emit_set_color_bg_8:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @pen: Pen number, 0-7
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_BG_8.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
CHAFA_TERM_SEQ_SET_COLOR_BG_8,

/**
 * chafa_term_info_emit_set_color_fgbg_8:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @fg_pen: Foreground pen number, 0-7
 * @bg_pen: Background pen number, 0-7
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_COLOR_FGBG_8.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.12
 **/
CHAFA_TERM_SEQ_SET_COLOR_FGBG_8,

/* --- Available in 1.14+ --- */




/**
 * chafa_term_info_emit_reset_default_fg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_DEFAULT_FG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_RESET_DEFAULT_FG,

/**
 * chafa_term_info_emit_set_default_fg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component (0-65535)
 * @g: Green component (0-65535)
 * @b: Blue component (0-65535)
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_DEFAULT_FG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_SET_DEFAULT_FG,

/**
 * chafa_term_info_emit_query_default_fg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_QUERY_DEFAULT_FG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_QUERY_DEFAULT_FG,

/**
 * chafa_term_info_emit_reset_default_bg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RESET_DEFAULT_BG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_RESET_DEFAULT_BG,

/**
 * chafa_term_info_emit_set_default_bg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 * @r: Red component (0-65535)
 * @g: Green component (0-65535)
 * @b: Blue component (0-65535)
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_SET_DEFAULT_BG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_SET_DEFAULT_BG,

/**
 * chafa_term_info_emit_query_default_bg:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_QUERY_DEFAULT_BG.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_QUERY_DEFAULT_BG,

/**
 * chafa_term_info_emit_tab_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_TAB_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_TAB_SHIFT_KEY,

/**
 * chafa_term_info_emit_up_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_UP_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_UP_KEY,

/**
 * chafa_term_info_emit_up_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_UP_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_UP_CTRL_KEY,

/**
 * chafa_term_info_emit_up_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_UP_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_UP_SHIFT_KEY,

/**
 * chafa_term_info_emit_down_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DOWN_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_DOWN_KEY,

/**
 * chafa_term_info_emit_down_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DOWN_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_DOWN_CTRL_KEY,

/**
 * chafa_term_info_emit_down_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DOWN_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_DOWN_SHIFT_KEY,

/**
 * chafa_term_info_emit_left_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_LEFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_LEFT_KEY,

/**
 * chafa_term_info_emit_left_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_LEFT_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_LEFT_CTRL_KEY,

/**
 * chafa_term_info_emit_left_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_LEFT_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_LEFT_SHIFT_KEY,

/**
 * chafa_term_info_emit_right_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RIGHT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_RIGHT_KEY,

/**
 * chafa_term_info_emit_right_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RIGHT_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_RIGHT_CTRL_KEY,

/**
 * chafa_term_info_emit_right_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_RIGHT_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_RIGHT_SHIFT_KEY,

/**
 * chafa_term_info_emit_page_up_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_UP_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_PAGE_UP_KEY,

/**
 * chafa_term_info_emit_page_up_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_UP_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_PAGE_UP_CTRL_KEY,

/**
 * chafa_term_info_emit_page_up_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_UP_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_PAGE_UP_SHIFT_KEY,

/**
 * chafa_term_info_emit_page_down_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_DOWN_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_PAGE_DOWN_KEY,

/**
 * chafa_term_info_emit_page_down_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_DOWN_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_PAGE_DOWN_CTRL_KEY,

/**
 * chafa_term_info_emit_page_down_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_PAGE_DOWN_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_PAGE_DOWN_SHIFT_KEY,

/**
 * chafa_term_info_emit_home_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_HOME_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_HOME_KEY,

/**
 * chafa_term_info_emit_home_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_HOME_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_HOME_CTRL_KEY,

/**
 * chafa_term_info_emit_home_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_HOME_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_HOME_SHIFT_KEY,

/**
 * chafa_term_info_emit_end_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_END_KEY,

/**
 * chafa_term_info_emit_end_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_END_CTRL_KEY,

/**
 * chafa_term_info_emit_end_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_END_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_END_SHIFT_KEY,

/**
 * chafa_term_info_emit_insert_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_INSERT_KEY,

/**
 * chafa_term_info_emit_insert_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_INSERT_CTRL_KEY,

/**
 * chafa_term_info_emit_insert_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_INSERT_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_INSERT_SHIFT_KEY,

/**
 * chafa_term_info_emit_delete_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_DELETE_KEY,

/**
 * chafa_term_info_emit_delete_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_DELETE_CTRL_KEY,

/**
 * chafa_term_info_emit_delete_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_DELETE_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_DELETE_SHIFT_KEY,

/**
 * chafa_term_info_emit_f1_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F1_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F1_KEY,

/**
 * chafa_term_info_emit_f1_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F1_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F1_CTRL_KEY,

/**
 * chafa_term_info_emit_f1_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F1_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F1_SHIFT_KEY,

/**
 * chafa_term_info_emit_f2_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F2_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F2_KEY,

/**
 * chafa_term_info_emit_f2_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F2_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F2_CTRL_KEY,

/**
 * chafa_term_info_emit_f2_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F2_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F2_SHIFT_KEY,


/**
 * chafa_term_info_emit_f3_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F3_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F3_KEY,

/**
 * chafa_term_info_emit_f3_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F3_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F3_CTRL_KEY,

/**
 * chafa_term_info_emit_f3_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F3_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F3_SHIFT_KEY,

/**
 * chafa_term_info_emit_f4_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F4_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F4_KEY,

/**
 * chafa_term_info_emit_f4_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F4_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F4_CTRL_KEY,

/**
 * chafa_term_info_emit_f4_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F4_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F4_SHIFT_KEY,

/**
 * chafa_term_info_emit_f5_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F5_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F5_KEY,

/**
 * chafa_term_info_emit_f5_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F5_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F5_CTRL_KEY,

/**
 * chafa_term_info_emit_f5_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F5_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F5_SHIFT_KEY,

/**
 * chafa_term_info_emit_f6_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F6_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F6_KEY,

/**
 * chafa_term_info_emit_f6_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F6_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F6_CTRL_KEY,

/**
 * chafa_term_info_emit_f6_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F6_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F6_SHIFT_KEY,

/**
 * chafa_term_info_emit_f7_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F7_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F7_KEY,

/**
 * chafa_term_info_emit_f7_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F7_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F7_CTRL_KEY,

/**
 * chafa_term_info_emit_f7_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F7_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F7_SHIFT_KEY,

/**
 * chafa_term_info_emit_f8_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F8_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F8_KEY,

/**
 * chafa_term_info_emit_f8_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F8_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F8_CTRL_KEY,

/**
 * chafa_term_info_emit_f8_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F8_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F8_SHIFT_KEY,

/**
 * chafa_term_info_emit_f9_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F9_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F9_KEY,

/**
 * chafa_term_info_emit_f9_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F9_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F9_CTRL_KEY,

/**
 * chafa_term_info_emit_f9_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F9_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F9_SHIFT_KEY,

/**
 * chafa_term_info_emit_f10_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F10_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F10_KEY,

/**
 * chafa_term_info_emit_f10_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F10_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F10_CTRL_KEY,

/**
 * chafa_term_info_emit_f10_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F10_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F10_SHIFT_KEY,

/**
 * chafa_term_info_emit_f11_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F11_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F11_KEY,

/**
 * chafa_term_info_emit_f11_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F11_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F11_CTRL_KEY,

/**
 * chafa_term_info_emit_f11_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F11_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F11_SHIFT_KEY,

/**
 * chafa_term_info_emit_f12_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F12_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F12_KEY,

/**
 * chafa_term_info_emit_f12_ctrl_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F12_CTRL_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F12_CTRL_KEY,

/**
 * chafa_term_info_emit_f12_shift_key:
 * @term_info: A #ChafaTermInfo
 * @dest: String destination
 *
 * Prints the control sequence for #CHAFA_TERM_SEQ_F12_SHIFT_KEY.
 *
 * @dest must have enough space to hold
 * #CHAFA_TERM_SEQ_LENGTH_MAX bytes, even if the emitted sequence is
 * shorter. The output will not be zero-terminated.
 *
 * Returns: Pointer to first byte after emitted string
 *
 * Since: 1.14
 **/
CHAFA_TERM_SEQ_F12_SHIFT_KEY,
# 29 "chafa-term-seq-doc-in.h" 2


    CHAFA_TERM_SEQ_MAX
}
ChafaTermSeq;
