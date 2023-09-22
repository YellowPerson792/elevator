# include <stdio.h>

int main()
{
	int t, totalnumber, tt[20], sp0[20], ep0[20], spog0[20], epog0[20],difference11[20],difference22[20];
	
	int move1, direction1, location1, number1, target1, change1, show1, overload1 = 0, recovery1 = 0,target11,special1,special11;
	int sp1[20], ep1[20], spog1[20], difference1[20], epog1[20], spc1[20], epc1[20];
	
	int move2, direction2, location2, number2, target2, change2, show2, overload2 = 0, recovery2 = 0,target22,special2,special22;
	int sp2[20], ep2[20], spog2[20], difference2[20], epog2[20] ,spc2[20], epc2[20];

	for (;;)
	{
		t = -1;
		move1 = 0, direction1 = 0, number1 = 0, change1 = 1, show1 = 0,special1=0,special11=1;
		move2 = 0, direction2 = 0, number2 = 0, change2 = 1, show2 = 0,special2=0,special22=1;		

		for (int i = 0; i < 20; ++i)
		{
			sp0[i] = 100, ep0[i] = 100, spog0[i] = 100, epog0[i] = 100;
			sp1[i] = 100, ep1[i] = 100, spog1[i] = 100, epog1[i] = 100;			
			sp2[i] = 100, ep2[i] = 100, spog2[i] = 100, epog2[i] = 100;
			tt[i] = 0;
		}

		printf("请输入两部电梯分别初始所在楼层：");
		scanf("%d %d", &location1, &location2);
		printf("请输入乘坐电梯的用户总数：");
		scanf("%d", &totalnumber);
		printf("请输入各乘客起始楼层和目的楼层：【起始层】 【目的层】 【时间】\n");
		for (int i = 0; i < totalnumber; ++i)
		{
			scanf("%d %d %d", &spog0[i], &epog0[i], &tt[i]);
		}
		printf("电梯运行结果：【楼层】 【人数】 【时间】\n");
		
		for (int i = 0; i < 200; ++i)
		{
			t = t + 1;
			for (int i = 0; i < 20; ++i)
				if (tt[i] == t)
					sp0[i] = spog0[i], ep0[i] = epog0[i];

			for (int i = 0; i < 20; ++i)
				difference11[i] = 100, difference22[i] = 100;
			
			if (direction1 == 0)
				for (int i = 0; i < 20; ++i)
					if (sp0[i] != 100 && ep0[i] != 100)
					{
						difference11[i] = abs(sp0[i] - location1);
					}
			if (direction1 == 1)
			{
				for (int i = 0; i < 20; ++i)
				{
					if (sp0[i] != 100 && ep0[i] != 100)
					{
						if (sp0[i] > location1)
							difference11[i] = sp0[i] - location1,special11=0;
					}
				}
				if (special11 == 0)
				{
					for (int i = 0, m = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && m <= sp0[i])
							m = sp0[i], target11 = i;
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] < location1)
							difference11[i] = 2 * sp0[target11] - sp0[i] - location1;
				}
				if (special11 == 1)
				{
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] < location1)
							difference11[i] = location1 - sp0[i];
				}
				special11 = 1;
			}
				
			if (direction1 == -1)
			{
				for (int i = 0; i < 20; ++i)
					if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] < location1)
						difference11[i] = location1 - sp0[i], special11 = 0;				
				if (special11 == 0)
				{
					for (int i = 0, m = 100; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && m >= sp0[i])
							m = sp0[i], target11 = i;
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] > location1)
							difference11[i] = sp0[i] + location1 - 2 * sp0[target11];
				}
				if(special11==1)
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] > location1)
							difference11[i] = sp0[i]-location1;
				special11 = 1;
			}
			
			if (direction2 == 0)
				for (int i = 0; i < 20; ++i)
					if (sp0[i] != 100 && ep0[i] != 100)
					{
						difference22[i] = abs(sp0[i] - location2);
					}
			if (direction2 == 1)
			{
				for (int i = 0; i < 20; ++i)
				{
					if (sp0[i] != 100 && ep0[i] != 100)
					{
						if (sp0[i] > location2)
							difference22[i] = sp0[i] - location2, special22 = 0;
					}
				}
				if (special22 == 0)
				{
					for (int i = 0, m = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && m <= sp0[i])
							m = sp0[i], target22 = i;
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] < location2)
							difference22[i] = 2 * sp0[target22] - sp0[i] - location2;
				}
				if (special22 == 1)
				{
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] < location2)
							difference22[i] = location2 - sp0[i];
				}
				special22 = 1;
			}

			if (direction2 == -1)
			{
				for (int i = 0; i < 20; ++i)
					if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] < location2)
						difference22[i] = location2 - sp0[i], special22 = 0;
				if (special22 == 0)
				{
					for (int i = 0, m = 100; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && m >= sp0[i])
							m = sp0[i], target22 = i;
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] > location2)
							difference22[i] = sp0[i] + location2 - 2 * sp0[target22];
				}
				if (special22 == 1)
					for (int i = 0; i < 20; ++i)
						if (sp0[i] != 100 && ep0[i] != 100 && sp0[i] > location2)
							difference22[i] = sp0[i] - location2;
				special22 = 1;
			}
			

			
			for (int i = 0; i < 20; ++i)
			{
				if ((difference11[i] <= difference22[i]) && (difference11[i] != 100) && (difference22[i] != 100))
					sp1[i] = sp0[i], ep1[i] = ep0[i], spog1[i] = spog0[i], epog1[i] = epog0[i];
				if ((difference11[i] > difference22[i]) && (difference11[i] != 100) && (difference22[i] != 100))
					sp2[i] = sp0[i], ep2[i] = ep0[i], spog2[i] = spog0[i], epog2[i] = epog0[i];
			}

			
																														
		back1:
			if (overload1 == 1)
			{
				for (int i = 0; i < 20; ++i)
					if (sp1[i] != 100 && ep1[i] != 100)
					{
						sp1[i] = 100, ep1[i] = 100;
					}
			}

			change1 = 1;
			if ((move1 == 1) && (direction1 == -1))
			{
				for (int i = 0; i < 20; ++i)
				{
					if (sp1[i] != 100 && sp1[i] < location1)
					{
						location1 = location1 - 1, change1 = 0;
						break;
					}
				}
				if (change1 == 1)
				{
					for (int i = 0; i < 20; ++i)
					{
						if (sp1[i] != 100 && sp1[i] > location1)
							direction1 = 1;
					}
				}
			}
			if ((move1 == 1) && (direction1 == 1))
			{
				for (int i = 0; i < 20; ++i)
				{

					if (sp1[i] != 100 && sp1[i] > location1)
					{
						location1 = location1 + 1, change1 = 0;
						break;
					}
				}
				if (change1 == 1)
				{
					for (int i = 0; i < 20; ++i)
					{
						if (sp1[i] != 100 && sp1[i] < location1)
						{
							direction1 = -1;
							goto back1;
						}
					}
				}
			}
			if (move1 == 1 && direction1 == 0)
			{
				change1 = 0, direction1 = 1;
			}

			if (change1 == 0)
			{
				for (int i = 0; i < 20; ++i)
				{
					if (location1 == epog1[i] && sp1[i] != 100 && ep1[i] == 100)
					{
						number1--;
						overload1 = 0;
						continue;
					}
				}
				for (int i = 0; i < 20; ++i)
				{
					if (location1 == spog1[i] && ep1[i] != 100)
					{
						number1++;
						continue;
					}
				}

				if (overload1 == 0 && recovery1 == 1)
					for (int i = 0; i < 20; ++i)
						sp1[i] = spc1[i], ep1[i] = epc1[i], recovery1 = 0;

				for (int i = 0; i < 20; ++i)
				{
					if (location1 == sp1[i])
					{
						show1 = 1;
						sp1[i] = ep1[i];
						ep1[i] = 100;
					}
				}
				if (show1 == 1)
				{
					printf("电梯1：%d %d %d\n", location1, number1,t);
					show1 = 0;
					
				}
			}

			if (overload1 == 0)
			{
				for (int i = 0; i < 20; ++i)
					spc1[i] = sp1[i], epc1[i] = ep1[i];
			}
			if (number1 == 4)
				overload1 = 1, recovery1 = 1;

			for (int i = 0; i < 20; ++i)
				difference1[i] = abs(sp1[i] - location1);
			for (int i = 0, m = 100; i < 20; ++i)
			{
				if (m >= difference1[i])
					m = difference1[i], target1 = i;
				if (m == 0)
					special1 = 1;
			}
			if ((move1 == 0) && (sp1[target1] != 100))
			{
				if (sp1[target1] < location1)
					direction1 = -1;
				if (sp1[target1] == location1)
					direction1 = 0;
				if (sp1[target1] > location1)
					direction1 = 1;
			}
			if (sp1[target1] == 100)
				move1 = 0, direction1 = 0;
			if ((sp1[target1] != 100)&&(special1==0))
				move1 = 1;
			if ((sp1[target1] != 100)&& (special1 == 1))
			{
				move1 = 1;
				special1 = 0;
				goto back1;
			}
			

			
			back2:
			if (overload2 == 1)
			{
				for (int i = 0; i < 20; ++i)
					if (sp2[i] != 100 && ep2[i] != 100)
					{
						sp2[i] = 100, ep2[i] = 100;
					}
			}

			change2 = 1;
			if ((move2 == 1) && (direction2 == -1))
			{
				for (int i = 0; i < 20; ++i)
				{
					if (sp2[i] != 100 && sp2[i] < location2)
					{
						location2 = location2 - 1, change2 = 0;
						break;
					}
				}
				if (change2 == 1)
				{
					for (int i = 0; i < 20; ++i)
					{
						if (sp2[i] != 100 && sp2[i] > location2)
							direction2 = 1;
					}
				}
			}
			if ((move2 == 1) && (direction2 == 1))
			{
				for (int i = 0; i < 20; ++i)
				{

					if (sp2[i] != 100 && sp2[i] > location2)
					{
						location2 = location2 + 1, change2 = 0;
						break;
					}
				}
				if (change2 == 1)
				{
					for (int i = 0; i < 20; ++i)
					{
						if (sp2[i] != 100 && sp2[i] < location2)
						{
							direction2 = -1;
							goto back2;
						}
					}
				}
			}
			if (move2 == 1 && direction2 == 0)
			{
				change2 = 0, direction2 = 1;
			}

			if (change2 == 0)
			{
				for (int i = 0; i < 20; ++i)
				{
					if (location2 == epog2[i] && sp2[i] != 100 && ep2[i] == 100)
					{
						number2--;
						overload2 = 0;
						continue;
					}
				}
				for (int i = 0; i < 20; ++i)
				{
					if (location2 == spog2[i] && ep2[i] != 100)
					{
						number2++;
						continue;
					}
				}

				if (overload2 == 0 && recovery2 == 1)
					for (int i = 0; i < 20; ++i)
						sp2[i] = spc2[i], ep2[i] = epc2[i], recovery2 = 0;

				for (int i = 0; i < 20; ++i)
				{
					if (location2 == sp2[i])
					{
						show2 = 1;
						sp2[i] = ep2[i];
						ep2[i] = 100;
					}
				}
				if (show2 == 1)
				{
					printf("电梯2：%d %d %d\n", location2, number2,t);
					
					show2 = 0;
					
				}
			}

			if (overload2 == 0)
			{
				for (int i = 0; i < 20; ++i)
					spc2[i] = sp2[i], epc2[i] = ep2[i];
			}
			if (number2 == 4)
				overload2 = 1, recovery2 = 1;

			for (int i = 0; i < 20; ++i)
				difference2[i] = abs(sp2[i] - location2);
			for (int i = 0, m = 100; i < 20; ++i)
			{
				if (m >= difference2[i])
					m = difference2[i], target2 = i;
				if (m == 0)
					special2 = 1;
			}
			if ((move2 == 0) && (sp2[target2] != 100))
			{
				if (sp2[target2] < location2)
					direction2 = -1;
				if (sp2[target2] == location2)
					direction2 = 0;
				if (sp2[target2] > location2)
					direction2 = 1;
			}
			if (sp2[target2] == 100)
				move2 = 0, direction2 = 0;
			if ((sp2[target2] != 100) && (special2 == 0))
				move2 = 1;
			if ((sp2[target2] != 100) && (special2 == 1))
			{
				move2 = 1;
				special2 = 0;
				goto back2;
			}


		
			for (int i = 0; i < 20; ++i)
				sp0[i] = 100, ep0[i] = 100;
			for (int i = 0; i < 20; ++i)
			{
				if (sp1[i] != 100 && ep1[i] != 100)
					sp0[i] = sp1[i], sp1[i] = 100, ep0[i] = ep1[i], ep1[i] = 100, spog0[i] = spog1[i], spog1[i] = 100, epog0[i] = epog1[i], epog1[i] = 100;
				if (sp2[i] != 100 && ep2[i] != 100)
					sp0[i] = sp2[i], sp2[i] = 100, ep0[i] = ep2[i], ep2[i] = 100, spog0[i] = spog2[i], spog2[i] = 100, epog0[i] = epog2[i], epog2[i] = 100;				
			}			
		}
	}
}
