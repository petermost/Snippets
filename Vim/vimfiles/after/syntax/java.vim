"*****************************************************************************
"** Name:      c.vim                                                        **
"**                                                                         **
"** Type:      vim syntax highlighting expansion                            **
"**                                                                         **
"** Author:    Christian Habermann                                          **
"**            christian (at) habermann-net (point) de                      **
"**                                                                         **
"** Copyright: (c) 2002-2003 by Christian Habermann                         **
"**            Permission is hereby granted to use and distribute this code,**
"**            with or without modifications, provided that this copyright  **
"**            notice is copied with it. This code is provided *as is* and  **
"**            comes with no warranty of any kind, either expressed or      **
"**            implied. The copyright holder will not be liable for any     **
"**            damamges resulting from the use of this software.            **
"**                                                                         **
"** VIM:       tested with VIM 6.2                                          **
"**                                                                         **
"** Versions:  V 1.0.1, 9. Oct. 2003                                        **
"**              - new email-address                                        **
"**              - improved description                                     **
"**                                                                         **
"**            V 1.0.0, 3. Jan. 2002                                        **
"**              first release                                              **
"**                                                                         **
"*****************************************************************************
"** Description:                                                            **
"**   This file expands VIM's C and C++ syntax-highlighting.                **
"**     - add KDE/qt-keywords: i18n, SLOT, SIGNAL                           **
"**     - add C/C++ operators: +,-,*,&.....                                 **
"**                                                                         **
"**   How to use it:                                                        **
"**     Store c.vim in                                                      **
"**        Unix:     ~/.vim/after/syntax/                                   **
"**        Windows:  c:\vimfiles\after\syntax                               **
"**                                                                         **
"**     Two new highlight groups will then be available:                    **
"**       - KDE                                                             **
"**       - mySpecialCSymbols                                                **
"**     Add colors to this groups by adding the following to your           **
"**     highlighting:                                                       **
"**       highlight KDE              guifg=magenta gui=NONE                 **
"**       highlight mySpecialCSymbols guifg=yellow  gui=NONE                 **
"**     Perhaps you have to adapt colors to your needs.                     **
"**                                                                         **
"**                                                                         **
"*****************************************************************************

"disabled: syntax keyword KDE i18n SLOT SIGNAL
syntax match   cjOperators "+\|-\|\*\|;\|:\|,\|<\|>\|&\||\|!\|\~\|%\|=\|)\|(\|{\|}\|\.\|\[\|\]"
highligh def link cjOperators		Operator

