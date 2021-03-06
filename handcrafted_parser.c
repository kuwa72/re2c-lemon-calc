//--------------------------------------------------------- ./handcrafted_parser.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char **argv) {

	int r;
	scanner_state *state;
	scanner_token *token;

	if(argc>1) {
	
		state = malloc(sizeof(scanner_state));
		token = malloc(sizeof(scanner_token));
	
		if(NULL == state || NULL == token) {return EXIT_FAILURE;}
	
		state->start = argv[1];

		//it's here, but not used:
		state->end = state->start;
	
		while(0 <= (r = scan(state, token))) {

			switch(token->opcode) {
				case TOKEN_INTEGER: printf("\tscanner: %d\n",token->n); break;
				case TOKEN_ADD:
				case TOKEN_SUB:
				case TOKEN_MUL:
				case TOKEN_DIV:
				case TOKEN_ROUND_BRACKET_OPEN:
				case TOKEN_ROUND_BRACKET_CLOSE: printf("\tscanner: %c\n",token->opcode); break;
				default: printf("\tscanner: unknown opcode\n"); break;
			}

			//it's here, but not used:
			state->end = state->start;
		}
	
		printf("\nend of scanning with code: %d\n",r);
		free(state);
		free(token);

		return SCANNER_RETCODE_EOF==r ? EXIT_SUCCESS:EXIT_FAILURE;
	}
	else {return EXIT_FAILURE;}
	
	return EXIT_SUCCESS;
}

