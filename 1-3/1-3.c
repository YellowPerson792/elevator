#include <stdio.h>
#include <stdlib.h>

int main() {
	int init, tar = 0, num, nolt = 0, ol = 0, drt, t = 0;
	int sp[10] = { 0 }, spd[10], ep[10] = { 0 }, epd[10], spog[10] = { 0 }, epog[10] = { 0 }, dif[10] = { 0 }, spc[10] = { 0 };
	for (;;)
	{
		printf("请输入电梯初始楼层:");
		scanf("%d", &init);
		printf("请输入乘坐电梯的乘客总数:");
		scanf("%d", &num);
		printf("请输入各乘客起始楼层和目的楼层:");
		for (int i = 0; i < num; ++i)
		{
			scanf("%d %d", &sp[i], &ep[i]);
			spog[i] = sp[i], epog[i] = ep[i];
		}
		for (int i = 0; i < num; ++i)
			dif[i] = abs(sp[i] - init);
		for (int i = 0, m = 100; i < num; ++i)
			if (m >= dif[i])
				m = dif[i], tar = i;//输入信息，求出最近
		if (sp[tar] < ep[tar])
		{
			drt = 1;
			nolt = 1;
			t = abs(sp[tar] - init);
			printf("%d %d %d\n", sp[tar], nolt, t);
			init = sp[tar];
			sp[tar] = ep[tar];
			ep[tar] = 100;
			for (int i = 0; i < 10; ++i)
				if (sp[i] > spog[tar])
				{
					spd[i] = sp[i];
					epd[i] = ep[i];
				}
		}
		else
		{
			drt = 0;
			nolt = 1;
			t = abs(sp[tar] - init);
			printf("%d %d %d\n", sp[tar], nolt, t);
			init = sp[tar];
			sp[tar] = ep[tar];
			ep[tar] = 100;
			for (int i = 0; i < 10; ++i)
				if (sp[i] < spog[tar])
				{
					spd[i] = sp[i];
					epd[i] = ep[i];
				}

		}




		for (int i = 0; i < 100; ++i)//以每次到达目的楼层为电梯运行的最小单位
		{
			for (int i = 0; i < 10; ++i)
			{
				spd[i] = 100;
			}
			if (drt == 1)
			{
				for (int i = 0; i < 10; ++i)
				{
					if (sp[i] >= init)
					{
						spd[i] = sp[i];
						epd[i] = ep[i];//提取出在电梯运行方向上的待接乘客
					}
				}
				for (int i = 0; i < num; ++i)
					dif[i] = abs(spd[i] - init);
				for (int i = 0, m = 100; i < num; ++i)
					if (m >= dif[i])
						m = dif[i], tar = i;//找最近
				if (spd[tar] != 100)//上下人
				{
					if (!(sp[tar] == spog[tar] && sp[tar] != epog[tar] && nolt == 4))
					{
						if (sp[tar] == spog[tar])
						{
							nolt++;
						}
						if (sp[tar] == epog[tar])
						{
							nolt--;
						}
						t = t + abs(sp[tar] - init);//求时间
						printf("%d %d %d\n", sp[tar], nolt, t);
						init = sp[tar];
						if (ol == 1)//超载系统
						{
							for (int i = 0; i < 10; ++i)
							{
								sp[i] = spc[i];
							}
						}
						ol = 0;
						spd[tar] = ep[tar];
						sp[tar] = ep[tar];
						epd[tar] = 100;
						ep[tar] = 100;
						for (int i = 0; i < 10; ++i)
							spc[i] = sp[i];

					}
					else
					{
						spd[tar] = 200;
						sp[tar] = 200;
						ol = 1;
					}


				}
				else
				{
					drt = 0;

				}
			}
			if (drt == 0)//电梯由静转动时的运动方式
			{
				for (int i = 0; i < 10; ++i)
				{
					if (sp[i] <= init)
					{
						spd[i] = sp[i];
						epd[i] = ep[i];
					}
				}
				for (int i = 0; i < num; ++i)
					dif[i] = abs(spd[i] - init);
				for (int i = 0, m = 100; i < num; ++i)
					if (m >= dif[i])
						m = dif[i], tar = i;
				if (spd[tar] != 100)
				{
					if (!(sp[tar] == spog[tar] && sp[tar] != epog[tar] && nolt == 4))
					{
						if (sp[tar] == spog[tar])
						{
							nolt++;
						}
						if (sp[tar] == epog[tar])
						{
							nolt--;
						}
						t = t + abs(sp[tar] - init);
						printf("%d %d %d\n", sp[tar], nolt, t);
						init = sp[tar];
						if (ol == 1)
						{
							for (int i = 0; i < 10; ++i)
							{
								sp[i] = spc[i];
							}
						}
						ol = 0;
						spd[tar] = epd[tar];
						sp[tar] = ep[tar];
						epd[tar] = 100;
						ep[tar] = 100;
						for (int i = 0; i < 10; ++i)
							spc[i] = sp[i];

					}
					else
					{
						spd[tar] = 200;
						sp[tar] = 200;
						ol = 1;
					}

				}
				else
				{
					drt = 1;
				}
			}
		}
	}



}
