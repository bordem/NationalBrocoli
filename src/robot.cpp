#include "header/robot.h"

Robot::Robot(Gyroscop& gyro, Movements& move, Ultrasound& ultra):
	gyro(gyro),
	move(move),
	ultra(ultra),
	cam(),
	pince(SLOT_4),
	bras(SLOT3)
{
	//bras.up();
}
Robot::~Robot(){}

void Robot::turn90(enum Pos direction){
	move.stop();
	gyro.begin();
	delay(10);
	move.turn(direction);
	float ag;
	if ( direction == LEFT ){
		while ( (ag=gyro.getAngle()) < 89 )
		{
			Serial.println(ag);
		}/**/
	}
	else {
		while ( (ag=gyro.getAngle()) > -89 )
		{
			Serial.println(ag);
		}/**/
	}
	move.stop();
}

void Robot::findObject(){
	Serial.print("Je commence le reperage");
	pince.open();
	int i = 0;
	while (!ultra.obstacleAt(17)){	
		uint16_t blocks;
		char buf[32];
		// grab blocks!
		blocks = cam.getPixy().getBlocks();
		int indiceGROS = 0;
		int GROS=0;
		float tabTailleObjets[100]={0};
		int tabDePince[2]={0};
		int idPINCEGAUCHE=0;
		int idPINCEDROITE=0;
		// If there are detect blocks, print them!
		if (blocks){
			int nb_p=0;
			i++;
			// do this (print) every 50 frames because printing every
			// frame would bog down the Arduino
			if (i%2==0){
				//sprintf(buf, "Detected %d:\n", blocks);
				//Serial.print(buf);
				for (uint8_t j=0; j<blocks; j++){
					//sprintf(buf, "	block %d: ", j);
					//Serial.print(buf);
					//Serial.print(pixy.blocks[j].x);
					//Serial.print(pixy.blocks[j].y);
					if(cam.getPixy().blocks[j].signature == 1 || cam.getPixy().blocks[j].signature == 2 || cam.getPixy().blocks[j].signature == 3){
						tabTailleObjets[j] = cam.getPixy().blocks[j].width*cam.getPixy().blocks[j].height;
					}
					if(cam.getPixy().blocks[j].signature == 7)
					{
						tabDePince[nb_p]=j;
						nb_p++;
					}
				}
				//TRI POUR TROUVER L'OBJET LE PLUS GROS, CELUI QUI NOUS INTERESSE
				if(nb_p>1){
					//Serial.print("j'ai mes pinces en vue" );
					for(int k=0;k<100;k++)
					{
						if(tabTailleObjets[k]>GROS){
							GROS=tabTailleObjets[k];
							indiceGROS = k;
						}
					}
					//TRI DES PINCES
					 if(cam.getPixy().blocks[tabDePince[0]].x > cam.getPixy().blocks[tabDePince[1]].x){
						 idPINCEDROITE=tabDePince[0];
						 idPINCEGAUCHE=tabDePince[1];
					 }else{
						 idPINCEDROITE=tabDePince[1];
						 idPINCEGAUCHE=tabDePince[0];
					 }
					//PIXY.BLOCK[GROS].OBJET A SUIVRE

					//Objet
					int xTresor = cam.getPixy().blocks[indiceGROS].x;
					//int yTresor = cam.getPixy().blocks[indiceGROS].y;
					int widthTresor = cam.getPixy().blocks[indiceGROS].width;
					//int hightTresor = cam.getPixy().blocks[indiceGROS].height;

					//int centreHorizontalTresor = xTresor+(widthTresor/2);
					//int centreVerticalTresor = yTresor+(hightTresor/2);

						if( xTresor < cam.getPixy().blocks[idPINCEGAUCHE].x+cam.getPixy().blocks[idPINCEGAUCHE].width+5){
							Serial.print("Il faut tourner a gauche ");
							move.goAt(70,150);
						}
						else if((xTresor+widthTresor)>(cam.getPixy().blocks[idPINCEDROITE].x-5)){
							Serial.print("Il faut tourner a droite ");
							move.goAt(150,70);
						}
						else{
							Serial.print("Tout droit ");
							move.goAt(90,90);
						}
				}else{
					move.stop();
					bras.down(100);
					//Serial.println("Descendre le bras");
				}
			}
		}
	}
	//Serial.println("Fermer la pince");
	move.stop();

	// int xTresor;
	// int yTresor;
	// int widthTresor;
	// int hightTresor;
	//
	// int centreHorizontalTresor;
	// int centreVerticalTresor;
	// for(int k=0;k<1;k++){
	// 	uint16_t blocks;
	// 	char buf[32];
	// 	static int i=0;
	// 	// grab blocks!
	// 	blocks = cam.getPixy().getBlocks();
	// 	int indiceGROS = 0;
	// 	int GROS=0;
	// 	float tabTailleObjets[100]={0};
	// 	int tabDePince[2]={0};
	// 	if (blocks){
	// 		int nb_p=0;
	// 		i++;
	// 		// do this (print) every 50 frames because printing every
	// 		// frame would bog down the Arduino
	// 		if (i%50==0){
	// 			//sprintf(buf, "Detected %d:\n", blocks);
	// 			//Serial.print(buf);
	// 			for (uint8_t j=0; j<blocks; j++){
	// 				if(cam.getPixy().blocks[j].signature == 1 || cam.getPixy().blocks[j].signature == 2 || cam.getPixy().blocks[j].signature == 3){
	// 					tabTailleObjets[j] = cam.getPixy().blocks[j].width*cam.getPixy().blocks[j].height;
	// 				}
	// 			}
	// 			//TRI POUR TROUVER L'OBJET LE PLUS GROS, CELUI QUI NOUS INTERESSE
	// 			//Serial.print("j'ai mes pinces en vue" );
	// 			for(int k=0;k<100;k++)
	// 			{
	// 				if(tabTailleObjets[k]>GROS){
	// 					GROS=tabTailleObjets[k];
	// 					xTresor = cam.getPixy().blocks[indiceGROS].x;
	// 					yTresor = cam.getPixy().blocks[indiceGROS].y;
	// 					widthTresor = cam.getPixy().blocks[indiceGROS].width;
	// 					hightTresor = cam.getPixy().blocks[indiceGROS].height;
	// 					centreHorizontalTresor = xTresor+(widthTresor/2);
	// 					centreVerticalTresor = yTresor+(hightTresor/2);
	// 					}
	// 			}
	// 		}
	// 	}
	// }
	// int yPince = 0;
	// while(centreVerticalTresor>yPince){
	//
	// 	static int i = 0;
	// 	uint16_t blocks;
	// 	char buf[32];
	// 	// grab blocks!
	// 	blocks = cam.getPixy().getBlocks();
	// 	int indiceGROS = 0;
	// 	int GROS=0;
	// 	float tabTailleObjets[100]={0};
	// 	int tabDePince[2]={0};
	// 	if (blocks){
	// 		int nb_p=0;
	// 		i++;
	// 		// do this (print) every 50 frames because printing every
	// 		// frame would bog down the Arduino
	// 		if (i%50==0){
	// 			//sprintf(buf, "Detected %d:\n", blocks);
	// 			//Serial.print(buf);
	// 			for (uint8_t j=0; j<blocks; j++){
	// 				if(cam.getPixy().blocks[j].signature == 7)
	// 				{
	// 					tabDePince[nb_p]=j;
	// 					nb_p++;
	// 				}
	// 			}
	// 			//TRI POUR TROUVER L'OBJET LE PLUS GROS, CELUI QUI NOUS INTERESSE
	// 			//Serial.print("j'ai mes pinces en vue" );
	// 			bras.down(100);
	// 			yPince =cam.getPixy().blocks[tabDePince[0]].y;
	// 		}
	// 	}
	// }
	bras.down(200);
	pince.close();
	delay(1000);
	bras.up(1000);
}
