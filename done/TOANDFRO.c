#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	
	int col, len, row, i, j, k;
	char clave[200], ans[200];
	char **matrix;

	while (1){

		scanf("%d", &col);

		if (!col)
			return 0;

		scanf("%s", clave);

		len = strlen(clave);
		ans[len] = '\0';
		row = len/col;

		matrix = (char **) malloc(sizeof(char *) * row);
		for (i = 0; i < row; i++)
			matrix[i] = (char *) malloc(sizeof(char) * col);

		k = 0;

		for (i = 0; i < row; i++) {
			if (i % 2 == 0) {
				for (j = 0; j < col; j++) {
					matrix[i][j] = clave[k++];
				}
			} else {
				for (j = col - 1; j >=0; j--) {
					matrix[i][j] = clave[k++];
				}
			}
		}

		/*for (i = 0; i < row; i++){
			printf("| ");
			for (j = 0; j < col; j++)
				printf("%c | ", matrix[i][j]);
			printf("\n");
		}*/

		k = 0;
		for (i = 0; i < col; i++) {
			for (j = 0; j < row; j++) {
				ans[k++] = matrix[j][i];
			}
		}
		for (i = 0; i < row; i++)
			free(matrix[i]);
		free(matrix);
		printf("%s\n", ans);
	}
}