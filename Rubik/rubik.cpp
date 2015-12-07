#include "rubik.h"

using namespace std;

char ch;

//FBLRUD
//012345

inline void LayerOneCross(RUBIK &rubik)
{
	printf("第一层十字: ");
	for (int k = 1; k <= 4; k++)
	{
		int ec1 = rubik.color[5][2][2] * 10 + rubik.color[1][2][2];
		int ec2 = rubik.color[1][2][2] * 10 + rubik.color[5][2][2];
		int ec;
		
		ec = rubik.color[5][1][2] * 10 + rubik.color[2][3][2];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(6, "BBDDFF"), rubik);
		}
		
		ec = rubik.color[5][2][1] * 10 + rubik.color[3][1][2];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(5, "LLDFF"), rubik);
		}
		
		ec = rubik.color[5][2][3] * 10 + rubik.color[4][1][2];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(5, "RRdFF"), rubik);
		}
		
		ec = rubik.color[1][2][3] * 10 + rubik.color[4][2][1];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(1, "f"), rubik);
		}
		
		ec = rubik.color[4][2][3] * 10 + rubik.color[2][2][3];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(5, "RdFFr"), rubik);
		}
		
		ec = rubik.color[2][2][1] * 10 + rubik.color[3][2][1];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(6, "lDFFL"), rubik);
		}
		
		ec = rubik.color[3][2][3] * 10 + rubik.color[1][2][1];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(1, "F"), rubik);
		}
		
		ec = rubik.color[6][1][2] * 10 + rubik.color[1][3][2];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(2, "FF"), rubik);
		}
		
		ec = rubik.color[6][2][1] * 10 + rubik.color[3][3][2];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(3, "DFF"), rubik);
		}
		
		ec = rubik.color[6][2][3] * 10 + rubik.color[4][3][2];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(3, "dFF"), rubik);
		}
		
		ec = rubik.color[6][3][2] * 10 + rubik.color[2][1][2];
		if (ec == ec1 || ec == ec2)
		{
			Operation(COMMAND(4, "DDFF"), rubik);
		}
		
		ec = rubik.color[5][3][2] * 10 + rubik.color[1][1][2];
		if (ec == ec2)
		{
			Operation(COMMAND(4, "fUlu"), rubik);
		}

		Operation(COMMAND(1, "H"), rubik);
	}
	printf("\n");
}

inline void LayerOneCover(RUBIK &rubik)
{
	printf("第一层完成: ");
	for (int k = 1; k <= 4; k++)
	{
		int ec1 = Translate(rubik.color[5][2][2], rubik.color[1][1][2], rubik.color[4][1][2]);
		
		int ec;
		
		ec = Translate(rubik.color[5][3][3], rubik.color[1][1][3], rubik.color[4][1][1]);
		if (ec == ec1)
		{
			Operation(COMMAND(4, "rdRD"), rubik);
		}
		
		ec = Translate(rubik.color[5][1][3], rubik.color[4][1][3], rubik.color[2][3][3]);
		if (ec == ec1)
		{
			Operation(COMMAND(3, "Rdr"), rubik);
		}
		
		ec = Translate(rubik.color[5][1][1], rubik.color[2][3][1], rubik.color[3][1][1]);
		if (ec == ec1)
		{
			Operation(COMMAND(4, "lDLD"), rubik);
		}
		
		ec = Translate(rubik.color[5][3][1], rubik.color[3][1][3], rubik.color[1][1][1]);
		if (ec == ec1)
		{
			Operation(COMMAND(3, "LDl"), rubik);
		}
		
		ec = Translate(rubik.color[6][1][1], rubik.color[3][3][3], rubik.color[1][3][1]);
		if (ec == ec1)
		{
			Operation(COMMAND(1, "D"), rubik);
		}
		
		ec = Translate(rubik.color[6][3][3], rubik.color[4][3][3], rubik.color[2][1][3]);
		if (ec == ec1)
		{
			Operation(COMMAND(1, "d"), rubik);
		}
		
		ec = Translate(rubik.color[6][3][1], rubik.color[2][1][1], rubik.color[3][3][1]);
		if (ec == ec1)
		{
			Operation(COMMAND(2, "DD"), rubik);
		}
		
		while (rubik.color[5][2][2] != rubik.color[5][3][3] ||
			   rubik.color[1][2][2] != rubik.color[1][1][3] ||
			   rubik.color[4][2][2] != rubik.color[4][1][1])
		{
			Operation(COMMAND(4, "rdRD"), rubik);
		}
		Operation(COMMAND(1, "H"), rubik);
	}
	printf("\n");
}

inline void ToptoBottom(RUBIK &rubik)
{
	printf("将魔方垂直旋转180°: ");
	Operation(COMMAND(2, "VV"), rubik);
	printf("\n");
}

inline void LayerTwoCover(RUBIK &rubik)
{
	printf("第二层完成: ");
	for (int k = 1; k <= 4; k++)
	{
		int ec1 = Translate(rubik.color[1][2][2], rubik.color[4][2][2]);
		for (int i = 1; i <= 4; i++)
		{
			int ec = Translate(rubik.color[1][2][3], rubik.color[4][2][1]);
			if (ec1 == ec) Operation(COMMAND(8, "URurufUF"), rubik);
			Operation(COMMAND(1, "H"), rubik);
		}
		for (int i = 1; i <= 4; i++)
		{
			if (rubik.color[1][2][2] == rubik.color[1][1][2] &&
				rubik.color[4][2][2] == rubik.color[5][3][2])
			{
				Operation(COMMAND(8, "URurufUF"), rubik);
				break;
			}
			if (rubik.color[4][2][2] == rubik.color[4][1][2] &&
				rubik.color[1][2][2] == rubik.color[5][2][3])
			{
				Operation(COMMAND(8, "ufUFURur"), rubik);
				break;
			}
			Operation(COMMAND(1, "U"), rubik);
		}
		Operation(COMMAND(1, "H"), rubik);
	}
	printf("\n");
}

inline void LayerThreeCross(RUBIK &rubik)
{
	printf("第三层十字: ");
	int topcolor = rubik.color[5][2][2];
	while (1)
	{
		int topcnt = 0;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
			{
				if ((i + j) % 2 == 1)
				{
					topcnt += (rubik.color[5][i][j] == topcolor);
				}
			}
		if (topcnt == 4) break;
		if (topcnt == 0)
		{
			while ((rubik.color[1][1][2] == topcolor) + (rubik.color[4][1][2] == topcolor) != 2)
			{
				Operation(COMMAND(1, "U"), rubik);
			}
		}
		else if (topcnt == 2)
		{
			for (int i = 1; i <= 4; i++)
			{
				if ((rubik.color[5][2][3] == topcolor) + (rubik.color[5][3][2] == topcolor) == 2) break;
				Operation(COMMAND(1, "U"), rubik);
			}
			if ((rubik.color[5][2][3] == topcolor) + (rubik.color[5][3][2] == topcolor) != 2)
			{
				for (int i = 1; i <= 4; i++)
				{
					if ((rubik.color[5][2][1] == topcolor) + (rubik.color[5][2][3] == topcolor) + (rubik.color[1][1][2] == topcolor) == 3) break;
					Operation(COMMAND(1, "U"), rubik);
				}
			}
		}
		Operation(COMMAND(6, "FRUruf"), rubik);
	}
	printf("\n");
}

inline void LayerThreeCover(RUBIK &rubik)
{
	printf("第三层完成: ");
	int topcolor = rubik.color[5][2][2];
	while (1)
	{
		int topcnt = 0;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
			{
				topcnt += (rubik.color[5][i][j] == topcolor);
			}
		if (topcnt == 9) break;
		if (topcnt == 5)
		{
			while (rubik.color[3][1][3] != topcolor)
			{
				Operation(COMMAND(1, "U"), rubik);
			}
		}
		else if (topcnt == 6)
		{
			while (rubik.color[5][3][1] != topcolor)
			{
				Operation(COMMAND(1, "U"), rubik);
			}
		}
		else if (topcnt == 7)
		{
			while (rubik.color[1][1][1] != topcolor)
			{
				Operation(COMMAND(1, "U"), rubik);
			}
		}
		Operation(COMMAND(8, "RUrURUUr"), rubik);
	}
	printf("\n");
}

inline void CornerAdjustment(RUBIK &rubik)
{
	printf("角块调整: ");
	while (1)
	{
		bool flag = false;
		for (int i = 1; i <= 4; i++)
		{
			int p1 = (rubik.color[1][2][2] == rubik.color[1][1][1]) + (rubik.color[1][2][2] == rubik.color[1][1][3]);
			int p2 = (rubik.color[4][2][2] == rubik.color[4][1][1]) + (rubik.color[4][2][2] == rubik.color[4][1][3]);
			int p3 = (rubik.color[2][2][2] == rubik.color[2][3][3]) + (rubik.color[2][2][2] == rubik.color[2][3][1]);
			int p4 = (rubik.color[3][2][2] == rubik.color[3][1][1]) + (rubik.color[3][2][2] == rubik.color[3][1][3]);
			if (p1 + p2 + p3 + p4 == 8)
			{
				flag = true;
				break;
			}
			Operation(COMMAND(1, "U"), rubik);
		}
		if (flag) break;
		if (!flag)
		{
			for (int i = 1; i <= 4; i++)
			{
				if (rubik.color[1][1][1] == rubik.color[1][1][3])
				{
					int cornercolor = rubik.color[1][1][1];
					for (int j = 1; j <= 4; j++)
					{
						if (rubik.color[1][2][2] == cornercolor)
						{
							for (int k = 1; k < j; k++)
							{
								Operation(COMMAND(1, "u"), rubik);
							}
							break;
						}
						Operation(COMMAND(1, "H"), rubik);
					}
					break;
				}
				Operation(COMMAND(1, "U"), rubik);
			}
			Operation(COMMAND(12, "RbRFFrBRFFrr"), rubik);
		}
	}
	printf("\n");
}

inline void EdgeAdjustment(RUBIK &rubik)
{
	printf("边块调整: ");
	while (1)
	{
		if (Complete(rubik)) break;
		for (int i = 1; i <= 4; i++)
		{
			if (Complete(rubik, 1))
			{
				Operation(COMMAND(2, "HH"), rubik);
				break;
			}
			if (Complete(rubik, 2))
			{
				break;
			}
			if (Complete(rubik, 3))
			{
				Operation(COMMAND(3, "HHH"), rubik);
				break;
			}
			if (Complete(rubik, 4))
			{
				Operation(COMMAND(1, "H"), rubik);
				break;
			}
			Operation(COMMAND(1, "U"), rubik);
		}
		Operation(COMMAND(12, "RuRURURururr"), rubik);
	}
	printf("\n");
}

int main()
{
	freopen("rubik.in", "r", stdin);
	freopen("rubik.out", "w", stdout);
	
	RUBIK rubik;
	
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++)
			{
				scanf(" %c", &ch);
				rubik.color[i][j][k] = ch - 48;
			}
	}
	
	printf("魔方初始状态:\n");
	rubik.Print();
	printf("魔方操作解释：\n");
	printf("F/B/L/R/U/D表示将魔方的前/后/左/右/上/下面顺时针旋转90°\n");
	printf("f/b/l/r/u/d表示将魔方的前/后/左/右/上/下面逆时针旋转90°\n");
	printf("H表示将魔方沿U/D方向整体旋转180°\n");
	printf("V表示将魔方沿L/R方向整体旋转180°\n\n");
	LayerOneCross(rubik);
	//rubik.Print();
	LayerOneCover(rubik);
	//rubik.Print();
	ToptoBottom(rubik);
	//rubik.Print();
	LayerTwoCover(rubik);
	//rubik.Print();
	LayerThreeCross(rubik);
	//rubik.Print();
	LayerThreeCover(rubik);
	//rubik.Print();
	CornerAdjustment(rubik);
	//rubik.Print();
	EdgeAdjustment(rubik);
	printf("\n魔方最终状态:\n");
	rubik.Print();
	return 0;
}
