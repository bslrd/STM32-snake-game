int M0[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M1[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,0,0,0,0,0},
				{0,0,1,0,0,0,0,0},
				{0,0,1,0,0,0,0,0},
				{0,0,1,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M2[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M3[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M4[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M5[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M6[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M7[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M8[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

int M9[8][8] = {{0,0,0,0,0,0,0,0},
				{0,0,0,0,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,1,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,1,0,0,0,0},
				{0,1,1,1,0,0,0,0},
				{0,0,0,0,0,0,0,0}};

void led_digits(int digit1, int digit2, int Rb, int Gb, int Bb, int Rd, int Gd, int Bd)
{
for(int i = 0; i < WS2812B_LEDS; i++)
	  	  {
	  	      WS2812B_SetDiodeRGB(i,Rb,Gb,Bb);
	  	  }



switch(digit1)
{
case 0:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M0[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 1:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M1[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 2:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M2[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 3:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M3[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 4:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M4[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 5:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M5[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 6:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M6[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 7:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M7[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 8:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M8[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 9:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M9[i][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

}

switch(digit2)
{
case 0:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M0[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 1:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M1[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 2:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M2[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 3:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M3[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 4:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M4[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 5:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M5[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 6:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M6[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 7:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M7[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 8:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M8[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

case 9:

	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(M9[i+4][j] == 1)
			{
				SetDiodeCoord(i,j,Rd,Gd,Bd);
			}
		}
	}
	break;

}

}
