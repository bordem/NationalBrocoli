#include "header/robot.h"

Robot::Robot(Gyroscope gyro, Movements move, Ultrason sound):
	gyro_group(gyro),
	move(move),
	sound(sound)
{
	Camera cam();
}
Robot::~Robot(){}

void Robot::followObject(){
	while (true)
	{
		static int i = 0;
		int j;
		uint16_t blocks;
		char buf[32];

		// grab blocks!
		blocks = cam.getPixy().getBlocks();
		int GROS=0;
		float tab[100]={0};
		// If there are detect blocks, print them!
		if (blocks)
		{
			i++;
			// do this (print) every 50 frames because printing every
			// frame would bog down the Arduino
			if (i%50==0)
			{
				sprintf(buf, "Detected %d:\n", blocks);
				Serial.print(buf);
				for (j=0; j<blocks; j++)
				{
					sprintf(buf, "	block %d: ", j);
					//Serial.print(buf);
					//Serial.print(pixy.blocks[j].x);
					//Serial.print(pixy.blocks[j].y);
					if(cam.getPixy().blocks[j].signature == 3){
						tab[j] = cam.getPixy().blocks[j].width*cam.getPixy().blocks[j].height;
					}
				}
				for(int k=0;k<100;k++)
				{
					if(tab[k]>GROS){
						GROS = k;
					}
				}
				//PIXY.BLOCK[GROS].OBJET A SUIVRE

				int x = cam.getPixy().blocks[GROS].x;
				int y = cam.getPixy().blocks[GROS].y;
				int width = cam.getPixy().blocks[GROS].width;
				int hight = cam.getPixy().blocks[GROS].height;

				int centreHorizontalObjet = x+(width/2);
				int centreVerticalObjet = y+(hight/2);

				int numeroCase = centreHorizontalObjet / (cam.getTAILLE_X()/8);

				switch(numeroCase){
					case 0:
						move.goAt(200,200);
						delay(100);
						move.goAt(0,0);
						break;
					case 1:
						move.goAt(200,-160);
						break;
					case 2:
						move.goAt(200,-180);
						break;
					case 3:
					case 4:
						move.goAt(200,-200);
						break;
					case 5:
						move.goAt(180,-200);
						break;
					case 6:
						move.goAt(160,-200);
						break;
					case 7:
						move.goAt(-200,-200);
						delay(100);
						move.goAt(0,0);
						break;
				}
			}
			delay(10);
		}
	}
}
