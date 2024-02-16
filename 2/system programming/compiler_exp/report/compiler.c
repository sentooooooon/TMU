// global.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BSIZE 128
#define NONE  -1
#define EOS   '\0'

#define ASSIGN 261
#define NUM   256
#define DIV   257
#define MOD   258
#define ID    259
#define DONE  260
#define WHILE 261
#define DO 262
#define BEGIN 263
#define END 264

int tokenval;
int lineno;

struct entry {
	char *lexptr;
	int token;
};

struct entry symtable[];

int lexan();
void parse();
void parse();
void expr();
void stmt();
void term();
void cond();
void factor();
void match(int);
void emit(int, int);
int lookup(char[]);
int insert(char[], int);
void init();
void error(char*);


// lexer.c
char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

int lexan()
{
	int t;
	while(1) {
		t = getchar();
		if (t == ' ' || t == '\t')
			;
		else if ( t == '\n')
			lineno = lineno + 1;
		else if (t==':'){
		t=getchar();
		if (t=='='){
		return ASSIGN;}
		}
		else if (isdigit(t)) {
			ungetc(t, stdin);
			scanf("%d", &tokenval);    // for gcc
			//scanf_s("%d", &tokenval);    // for Visual Studio
			return NUM;
		}
		else if (isalpha(t)) {
			int p,b = 0;
			while (isalnum(t)) {
				lexbuf[b] = t;
				t = getchar();
				b = b + 1;
				if (b >= BSIZE)
					error("compiler error");
			}
			lexbuf[b] = EOS;
			if (t !=EOF)
				ungetc(t, stdin);
			p = lookup(lexbuf);
			if (p == 0)
				p = insert(lexbuf, ID);
			tokenval = p;
			return symtable[p].token;
		}
		else if (t == EOF)
			return DONE;
		else {
			tokenval = NONE;
			return t;
		}
	}
}



// parser.c
int lookahead;

void parse()
{
	lookahead = lexan();
	while (lookahead != DONE) {
		stmt(); match(';');
	}
}

void expr()
{
	int t;
	//printf("expr naka\n");
	term();
	while(1)
		switch (lookahead) {
		case '+': case '-':
			t = lookahead;
			match(lookahead); term(); emit(t, NONE);
			continue;
		default:
			return;
		}
}

void stmt(){
	if(lookahead == ID){
		printf("lvalue ");
		emit(ID,tokenval);
		match(lookahead);
		if(lookahead == ASSIGN){
			match(lookahead);
			expr();
			printf(":=\n");
		}
	}
	else if(lookahead == WHILE){
		match(lookahead);
		printf("label test\n");
		cond();
		printf("go false\n");
		if(lookahead == DO){
			match(lookahead);
			stmt();
			printf("goto test\n");
			printf("label out");
		}
	}
	else if(lookahead == BEGIN){
		while(1){
			if(lookahead == END){
				break;
			}
			if(lookahead != END){
			match(lookahead);
			stmt();}
		}
	}
}

void term()
{
	int t;
	//printf("term naka\n");
	factor();
	while(1)
		switch (lookahead) {
		case '*': case '/': case DIV: case MOD:
			t = lookahead;
			match(lookahead); factor(); emit(t, NONE);
			continue;
		default:
			return;
		}
}

void cond()
{
	int t;
	//printf("cond yobareta");
	expr();
	//printf("expr success");
	while(1)
		switch (lookahead) {
		/*case '*': case '/': case DIV: case MOD:
			t = lookahead;
			match(lookahead); factor(); emit(t, NONE);
			continue;*/
		case '<':
			t = lookahead;
			match(lookahead); expr();emit(t,NONE);
			//printf("rmit owari\n");
			break;
		case '>':
			t = lookahead;
			match(lookahead); expr();emit(t,NONE);
			break;
			//printf(">\n");
		case '=':
			t = lookahead;
			match(lookahead); expr(); emit(t,NONE);	
			break;		//printf("=\n");
		default:
			return;
		//printf("cond seikou");
		}
}

void factor()
{
	switch(lookahead) {
		case '(':
			match('('); expr(); match(')'); break;
		case NUM:
			printf("push ");emit(NUM, tokenval); match(NUM); break;
		case ID:
			printf("rvalue ");emit(ID, tokenval); match(ID); break;
		default:
			error("syntax error"); break;
	}
	//printf("factor finished\n");
}

void match(t)
	int t;
{
	if (lookahead == t)
		lookahead = lexan();
	else error("syntax error");
}


// emitter.c
void emit(t, tval)
	int t, tval;
{
	switch(t) {
		case '+': case '-': case '*': case '/': case '>': case '<' : case '=':
			printf("%c\n", t); break;
		case DIV:
			printf("DIV\n"); break;
		case MOD:
			printf("MOD\n"); break;
		case NUM:
			printf("%d\n", tval); break;
		case ID:
			printf("%s\n", symtable[tval].lexptr); break;
		default:
			printf("token %d, tokenval %d\n", t, tval); break;
	}
}


// symbol.c
#define STRMAX	999
#define SYMMAX	100

char lexemes[STRMAX];
int lastchar = -1;
struct entry symtable[SYMMAX];
int lastentry = 0;

int lookup(s)
	char s[];
{
	int p;
	for (p = lastentry; p > 0; p = p -1)
		if (strcmp(symtable[p].lexptr, s) == 0)
			return p;
	return 0;
}

int insert(s, tok)
	char s[];
	int tok;
{
	int len;
	len = strlen(s);
	if (lastentry +1 >= SYMMAX)
		error("symbol table full");
	if (lastchar + len +1 >= STRMAX)
		error("lexemes array full");
	lastentry = lastentry +1;
	symtable[lastentry].token = tok;
	symtable[lastentry].lexptr = &lexemes[lastchar + 1];
	lastchar = lastchar + len + 1;
	strcpy(symtable[lastentry].lexptr, s);
	return lastentry;
}


// init.c
struct entry keywords[] = {
	"div", DIV,
	"mod", MOD,
	"while", WHILE,
	"do", DO,
	"begin", BEGIN,
	"end", END,
	0, 0
};

void init()
{
	struct entry *p;
	for (p = keywords; p -> token; p++)
		insert(p -> lexptr, p -> token);
}


// error.c
void error(m)
	char *m;
{
	fprintf(stderr, "line %d: %s\n", lineno, m);
	exit(1);
}


// main.c
void main()
{
	init();
	parse();
	exit(0);
}
