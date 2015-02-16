#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct e{

	char op;
	struct e *next;
	
} nodo;

nodo *push (char c, nodo *stack) {

	nodo *elem;

	elem = (nodo *) malloc(sizeof(nodo));

	elem->op = c;
	elem->next = stack;
	
	return elem;
}

char pop (nodo **stack) {

	nodo *elem;
	char c;

	if (*stack == NULL)
		return '0';

	elem = *stack;
	*stack = elem->next;

	c = elem->op;
	free(elem);

	return c;
}

int empty (nodo *list) {

	return (list == NULL);
}

int main(int argc, char const *argv[]) {
	int t, l, i, p = 0;
	char e[400], out[400];
	char op;
	nodo *stack = NULL;

	scanf("%d", &t);

	while (t--) {

		scanf("%s", e);
		l = strlen(e);

		for (i = 0; i < l; i++) {
			/*si es una variable*/
			if ((e[i] >= 'a') && (e[i] <= 'z')) {
				out[p] = e[i];
				p++;

			/*si es un operador*/
			} else {
				if (e[i] == ')') {

					while ((op = pop(&stack)) != '(') {

						out[p] = op;
						p++;
					}
				} else
					stack = push(e[i], stack);
			}
		}

		while (!empty(stack)) {

			op = pop(&stack);
			out[p] = op;
			p++;
		}

		out[p] = '\0';
		p = 0;
		printf("%s\n", out);
	}

	return 0;
}