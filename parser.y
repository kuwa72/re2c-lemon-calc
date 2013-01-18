//--------------------------------------------------------- ./parser.y

%include {

	#include <stdio.h>
	#include <stdlib.h>
	#include <assert.h>
	#include "scanner.h"
	#include "parser.h"
	#include "lemon_parser.h"
}

%token_type {scanner_token}
%default_type {scanner_token}
%type expr {scanner_token}
%type OP_INTEGER {scanner_token}
%left OP_ADD OP_SUB.
%left OP_MUL OP_DIV.
%syntax_error {printf("syntax error\n");}

//%extra_argument { int *state }

in ::= expr(A). { /**state = A.n;*/printf("in expr(%d):\n", A.n);}
expr(A) ::= expr(B) OP_ADD expr(C). {A.n = B.n + C.n;}
expr(A) ::= expr(B) OP_SUB expr(C). {A.n = B.n - C.n;}
expr(A) ::= expr(B) OP_MUL expr(C). {A.n = B.n * C.n;}
expr(A) ::= expr(B) OP_DIV expr(C). {/* TODO: fix division by 0 */ 
	A.n = B.n / C.n;}
expr(A) ::= OP_INTEGER(B). { A = B; }
