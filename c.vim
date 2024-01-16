" Vim syntax file
" Language:	C Additions
" Maintainer:	Mikhail Wolfson <mywolfson@gmail.com>
" URL: http://web.mit.edu/wolfsonm
" Last Change:	2010 Dec. 3
" Version: 0.4
"
" Changelog:
"   0.4 - updates and fixes to cDelimiter to fix break with foldmethod=syntax,
"         entirely suggested and solved by Ivan Freitas
"         <ivansichfreitas@gmail.com>
"   0.3 - updates and fixes to cUserFunctionPointer, thanks to 
"         Alexei <lxmzhv@gmail.com>
"   0.2 - change [] to operator
"   0.1 - initial upload, modification from vimscript#1201, Extended c.vim


" Common ANSI-standard functions
syn keyword cAnsiFunction	main typeof
syn keyword cAnsiFunction	open close read write lseek dup dup2
syn keyword cAnsiFunction	strerror memset strtok
" Malloc
syn keyword cMalloc		realloc malloc free ft_calloc
" Return
syn keyword cReturn		return
" Libft
syn keyword LibftFunction	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint
syn keyword LibftFunction	ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy
syn keyword LibftFunction	ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp
syn keyword LibftFunction	ft_memchr ft_memcmp ft_strnstr ft_atoi
syn keyword LibftFunction	ft_strdup ft_strjoin ft_substr ft_strtrim ft_split
syn keyword LibftFunction	ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd
syn keyword LibftFunction	ft_putendl_fd ft_putnbr_fd
syn keyword LibftFunction	ft_printf get_next_line
" Negadores
syn keyword cTerminator		NULL exit atexit abort
" Operadores
syn match cOperador		"!"
" Numeros
syn match cNums			/\v\d+/
" Operators
syn match cOperator	"\(<<\|>>\|[-+*/%&^|<>!=]\)="
syn match cOperator	"<<\|>>\|&&\|||\|++\|--\|->"
syn match cOperator	"[.~*&%<>^|=,+-]"
syn match cOperator	"/[^/*=]"me=e-1
syn match cOperator	"/$"
syn match cOperator	"&&\|||"
syn match cOperator	"[][]"
" Functions
syn match cUserFunction "\<\h\w*\>\(\s\|\n\)*("me=e-1 contains=cType,cDelimiter,cDefine
syn match cUserFunctionPointer "(\s*\*\s*\h\w*\s*)\(\s\|\n\)*(" contains=cDelimiter,cOperator
" Delimiters
syn match cDelimiter    "[();\\]"
" foldmethod=syntax fix, courtesy of Ivan Freitas
syn match cBraces display "[{}]"
" Booleans
syn keyword cBoolean true false TRUE FALSE

" Fondo
"highlight Normal ctermbg=232 guibg=#1E1E1E
" Colores
highlight cAnsiFunction ctermfg=41 guifg=#5BFF6A
highlight cMalloc	cterm=bold ctermfg=41 guifg=#5BFF6A
highlight cReturn	ctermfg=184 guifg=#d7d700
highlight LibftFunction ctermfg=81 guifg=#01BABC
highlight cTerminator	ctermfg=124 guifg=#FF0000
hi def link cOperador	cTerminator
"highlight cNums		ctermfg=16 guifg=#000000
" Links

"hi def link cDelimiter Delimiter
"hi def link cBraces Delimiter
"hi def link cBoolean Boolean
"hi def link cAnsiFunction cFunction
"hi def link cUserFunction cDarkBlue
hi def link cUserFunctionPointer cFunction
