/* Diacritics processing for a few character codes.
   Copyright (C) 1990, 1991, 1992, 1993 Free Software Foundation, Inc.
   Fran�ois Pinard <pinard@iro.umontreal.ca>, 1988.

   All this file is a temporary hack, waiting for locales in GNU.
*/

extern const char diacrit_base[]; /* characters without diacritics */
extern const char diacrit_diac[]; /* diacritic code for each character */

/* Returns CHAR without its diacritic.  CHAR is known to be alphabetic.  */
#define tobase(Char) (diacrit_base[(unsigned char) (Char)])

/* Returns a diacritic code for CHAR.  CHAR is known to be alphabetic.  */
#define todiac(Char) (diacrit_diac[(unsigned char) (Char)])
