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

int main()
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

	int y[Y_ROW][Y_COL];

	for (int i = 0; i < Y_ROW; i++)
	{
		for (int j = 0; j < Y_COL; j++)
		{
			y[i][j] = 0;
		} // for(int j = 0; j < Y_COL; j++)
	} // for(int i = 0; i < Y_ROW; i++)

	for (int i = 0; i < Y_ROW; i++)
	{
		for (int j = 0; j < Y_COL; j++)
		{
			for (int k1 = 0; k1 < H_ROW; k1++)
			{
				for (int k2 = 0; k2 < H_COL; k2++)
				{
					if ((i - k1 >= 0) && (i - k1 < X_ROW) && (j - k2 < X_COL) && (j - k2 >= 0))
					{
						y[i][j] += h[k1][k2] * x[i - k1][j - k2];
						
					} // if((i-k1 >= 0)&&(i-k1 < X_ROW)&&(j-k2 < X_COL)&&(j-k2 >= 0))
				} // for(int k2 = 0; k2 < H_COL; k2++)
			} // for(int k1 = 0; k1 < H_ROW; k1++)
		} // for(int j = 0; j < Y_COL; j++)
	} // for(int i = 0; i < Y_ROW; i++)

	FILE* file = fopen("../method_1.xls", "w");

	if (file != NULL)
	{
		PrintMatrix(file, (int**)h, "H");
		PrintMatrix(file, (int**)x, "X");
		PrintMatrix(file, (int**)y, "Y");

		fclose(file);
	} // if(file != NULL)

	return 0;
}
