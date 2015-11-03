" Vim color file
" Maintainer: Peter Most <PMost@PERA-Software.com>

"{{{=============================== Color options ================================
highlight clear
if exists("syntax_on")
	syntax reset
endif

let g:colors_name = "peter_most_minimal"

highlight Normal     guifg=White       ctermfg=White    guibg=Black
highlight Search     guifg=Black       ctermfg=Black    guibg=Orange
highlight NonText    guifg=DarkGray    ctermfg=DarkGray term=None gui=None
highlight SpecialKey guifg=DarkGray    ctermfg=DarkGray

highlight Folded     guifg=Blue        ctermfg=Blue     guibg=DarkGray
highlight FoldColumn guifg=Blue        ctermfg=Blue     guibg=DarkGray

highlight Comment    guifg=Green       ctermfg=Green
highlight PreProc    guifg=Magenta     ctermfg=Magenta
highlight String     guifg=Cyan        ctermfg=Cyan
highlight Constant   guifg=Cyan        ctermfg=Cyan
highlight Number     guifg=Cyan        ctermfg=Cyan
highlight Statement  guifg=White       ctermfg=White
highlight Operator   guifg=Yellow      ctermfg=Yellow
highlight Type       guifg=White       ctermfg=White
"}}}
