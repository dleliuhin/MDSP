#include <stdio.h>

#define H_ROW 7
#define H_COL 7
#define X_ROW 8
#define X_COL 7
#define Y_ROW (H_ROW + X_ROW - 1)
#define Y_COL (H_COL + X_COL - 1)

void PrintMatrix(FILE* file, int* matrix[], const char* type)
{
	int row, col;

	if (type == "H")
	{
		row = H_ROW;
		col = H_COL;
	} // (type == "H")
	else if (type == "X")
	{
		row = X_ROW;
		col = X_COL;
	} // (type == "X")
	else
	{
		row = Y_ROW;
		col = Y_COL;
	} // (type != "X") && (type != "H")

	fprintf(file, "======= Matrix %s(%d, %d)=======\n", type, row, col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fprintf(file, "%d\t", matrix[i*col + j]);
		} // for (int j = 0; j < col; j++)
		
		fprintf(file, "\n");
	} // for (int i = 0; i < row; i++)
	
	fprintf(file, "\n\n");
}

int main(void)
{
	int h[H_ROW][H_COL] = { { 3, 3, 2, 2, 1, 1, 2 },
							{ 1, 1, 4, 3, 3, 2, 0 },
							{ 2, 2, 3, 4, 0, 5, 4 },
							{ 2, 4, 3, 3, 2, 1, 0 },
							{ 0, 4, 2, 0, 3, 6, 5 },
							{ 0, 3, 2, 4, 0, 5, 7 },
							{ 0, 3, 3, 0, 4, 4, 7 } };

	int x[X_ROW][X_COL] = { { 0, 3, 3, 0, 5, 0, 0 },
							{ 4, 2, 2, 4, 0, 4, 4 },
							{ 5, 3, 2, 5, 3, 4, 7 },
							{ 5, 4, 2, 0, 0, 4, 0 },
							{ 0, 4, 1, 4, 0, 0, 8 },
							{ 3, 3, 2, 0, 2, 4, 5 },
							{ 0, 1, 3, 4, 0, 4, 6 },
							{ 0, 4, 0, 5, 5, 0, 0 } };

	int temp[Y_ROW][Y_COL];
	int y[Y_ROW][Y_COL];

	for (int i = 0; i < Y_ROW; i++)
	{
		for (int j = 0; j < Y_COL; j++)
		{
			y[i][j] = 0;
		} // (int j = 0; j < Y_COL; j++)
	} // (int i = 0; i < Y_ROW; i++)

	FILE* file = fopen("method_2.xls", "w");

	PrintMatrix(file, (int**)h, "H");
	PrintMatrix(file, (int**)x, "X");

	for (int k1 = 0; k1 < X_ROW; k1++)
	{
		for (int k2 = 0; k2 < X_COL; k2++)
		{
			for (int i = 0; i < Y_ROW; i++)
			{
				for (int j = 0; j < Y_COL; j++)
				{
					temp[i][j] = 0;
				} // for (int j = 0; j < Y_COL; j++)
			} // (int i = 0; i < Y_ROW; i++)

			for (int m1 = 0; m1 < H_ROW; m1++)
			{
				for (int m2 = 0; m2 < H_COL; m2++)
				{
					temp[m1 + k1][m2 + k2] = h[m1][m2] * x[k1][k2];
				} // (int m2 = 0; m2 < H_COL; m2++)
			} // (int m1 = 0; m1 < H_ROW; m1++)

			char matr[12] = "";
			sprintf(matr, "Temp_%d_%d", k1 + 1, k2 + 1);
			
			PrintMatrix(file, (int**)temp, matr);

			for (int i = 0; i < Y_ROW; i++)
			{
				for (int j = 0; j < Y_COL; j++)
				{
					y[i][j] += temp[i][j];
				} // (int j = 0; j < Y_COL; j++)
			} // (int i = 0; i < Y_ROW; i++)
		} // (int k2 = 0; k2 < X_COL; k2++)
	} // (int k1 = 0; k1 < X_ROW; k1++)

	PrintMatrix(file, (int**)y, "Y");

	fclose(file);
}