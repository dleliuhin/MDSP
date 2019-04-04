#include <stdio.h>
#include <math.h>
#define ROW 14 // n2 = ROW - i
#define COL 13 // n1 = j + 1
#define WINDOW_SIZE 3

void PrintMatrix(FILE* file, int* matrix[], const char* name)
{
	fprintf(file, "======= Matrix %s =======\n", name);
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			fprintf(file, "%d\t", matrix[i * COL + j]);
		}
		
		fprintf(file, "\n");
	}
	
	fprintf(file, "\n\n");
}

void main(void)
{
// [n1][n2] [n1][n2]
// in signal without noise: [5][4] = 162, [7][8] = 242
const int signal_noise[14][13] =
		{{ 0, 9, 18, 15, 27, 24, 16, 19, 11, 5, 10, 0, 0 },
		 { 12, 21, 26, 45, 50, 53, 79, 51, 39, 30, 8, 12, 8 },
		 { 19, 36, 57, 78, 100, 105, 124, 131, 82, 80, 57, 23, 14 },
		 { 28, 53, 91, 113, 107, 160, 160, 125, 137, 80, 53, 58, 16 },
		 { 23, 57, 102, 151, 133, 171, 220, 188, 162, 149, 85, 63, 44 },
		 { 29, 82, 109, 144, 400, 217, 261, 270, 195, 129, 146, 96, 30 },
		 { 13, 77, 119, 161, 175, 221, 323, 272, 290, 230, 152, 174, 107 },
		 { 6, 80, 116, 143, 194, 249, 357, 330, 450, 233, 177, 188, 97 },
		 { 6, 54, 99, 125, 147, 209, 293, 311, 264, 158, 143, 183, 113 },
		 { 0, 37, 75, 88, 133, 139, 268, 243, 142, 171, 101, 124, 81 },
		 { 0, 17, 47, 75, 95, 111, 137, 226, 153, 95, 108, 141, 121 },
		 { 0, 9, 37, 34, 60, 92, 126, 139, 151, 131, 95, 106, 77 },
		 { 0, 0, 15, 20, 52, 41, 78, 113, 80, 104, 75, 52, 42 },
		 { 0, 0, 12, 12, 15, 46, 31, 48, 40, 55, 35, 0, 0 }};

	int filter[3][3] = {{2, 3, 2},
						{2, 4, 2},
						{2, 3, 2}};

	const int amount = 22;
	const double m = 1.25;
	double nu = 0.0;
	int signal[14][13];
	int delta[14][13];

	FILE* file = fopen("../results/rash3.xls", "w");
	// anisotropic filter

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			signal[i][j] = 0;
			delta[i][j] = 0;
		}
	}
	
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			if(i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
			{
				signal[i][j] = signal_noise[i][j];
			}
			else
			{
				int sg = 0;
				
				for(int k1 = 0; k1 < WINDOW_SIZE; k1++)
				{
					for(int k2 = 0; k2 < WINDOW_SIZE; k2++)
					{
						sg += filter[k1][k2] * signal_noise[i - 1 + k1][j - 1 + k2];
					}
				}
				
				signal[i][j] = sg / amount;
			}
		}
	}
	
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			delta[i][j] = signal_noise[i][j] - signal[i][j];
		}
	}
	
	fprintf(file, "Anisotropic filter\n\n");
	PrintMatrix(file, (int**)signal_noise, "Signal-noise");
	PrintMatrix(file, (int**)signal, "Signal");
	PrintMatrix(file, (int**)delta, "Delta (Signal-noise - Signal)");
	fprintf(file, "\n\n");
	// statistic filter (nu = m * sigma)
	
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			signal[i][j] = 0;
			delta[i][j] = 0;
		}
	}
	
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			int sum1 = 0;
			double sum2 = 0.0;
			
			for(int k1 = 0; k1 < WINDOW_SIZE; k1++)
			{
				for(int k2 = 0; k2 < WINDOW_SIZE; k2++)
				{
					sum1 += signal_noise[i - 1 + k1][j - 1 + k2];
				}
			}
			
			double G = (double)sum1 / pow((double)WINDOW_SIZE, 2);
			
			for(int k1 = 0; k1 < WINDOW_SIZE; k1++)
			{
				for(int k2 = 0; k2 < WINDOW_SIZE; k2++)
				{
					sum2 += pow((double)signal_noise[i - 1 + k1][j - 1 + k2] - G, 2);
				}
			}
			
			double D = sum2 / (pow((double)WINDOW_SIZE, 2) - 1);
			nu = m * sqrt(D);
			signal[i][j] = (signal_noise[i][j] - G) < nu ? signal_noise[i][j] : (int)G;
		}
	}	
	
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < COL; j++)
		{
			delta[i][j] = signal_noise[i][j] - signal[i][j];
		}
	}
	
	fprintf(file, "Statistic filter\n\n");
	PrintMatrix(file, (int**)signal_noise, "Signal-noise");
	PrintMatrix(file, (int**)signal, "Signal");
	PrintMatrix(file, (int**)delta, "Delta (Signal-noise - Signal)");
	fprintf(file, "\n\n");
	
	fclose(file);
}