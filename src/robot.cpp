#include "header/robot.h"

Robot::Robot(Gyroscop& gyro, Movements& move, Ultrasound& ultra):
	gyro(gyro),
	move(move),
	ultra(ultra)
{
	Camera cam();
	Pince pince(SLOT_4);
	Arm bras(SLOT_3);
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
	while (true){

		static int i = 0;
		uint16_t blocks;
		char buf[32];
		// grab blocks!
		blocks = cam.getPixy().getBlocks();
		int indiceGROS = 0;
		int GROS=0;
		float tabTailleObjets[100]={0};
		int tabDePince[2]={0};
		int p = 0;
		int PINCEGAUCHE=0;
		int PINCEDROITE=0;
		// If there are detect blocks, print them!
		if (blocks){
			p=0;
			i++;
			// do this (print) every 50 frames because printing every
			// frame would bog down the Arduino
			if (i%50==0){
				//sprintf(buf, "Detected %d:\n", blocks);
				Serial.print(buf);
				for (uint8_t j=0; j<blocks; j++){
					sprintf(buf, "	block %d: ", j);
					//Serial.print(buf);
					//Serial.print(pixy.blocks[j].x);
					//Serial.print(pixy.blocks[j].y);
					if(cam.getPixy().blocks[j].signature == 1 || cam.getPixy().blocks[j].signature == 2 || cam.getPixy().blocks[j].signature == 3){
						tabTailleObjets[j] = cam.getPixy().blocks[j].width*cam.getPixy().blocks[j].height;
					}
					if(cam.getPixy().blocks[j].signature == 7)
					{
						tabDePince[p]=j;
						p++;
						if(p==2){
							//Serial.print("Toutes les pinces ont bien été répertorié" );
						}
					}
				}
				//TRI POUR TROUVER L'OBJET LE PLUS GROS, CELUI QUI NOUS INTERESSE
				if(p==2){
					Serial.print("j'ai mes pinces en vue" );
					for(int k=0;k<100;k++)
					{
						if(tabTailleObjets[k]>GROS){
							GROS=tabTailleObjets[k];
							indiceGROS = k;
						}
					}
					//TRI DES PINCES
					 if(cam.getPixy().blocks[tabDePince[0]].x > cam.getPixy().blocks[tabDePince[1]].x){
						 PINCEDROITE=tabDePince[0];
						 PINCEGAUCHE=tabDePince[1];
					 }else{
						 PINCEDROITE=tabDePince[1];
						 PINCEGAUCHE=tabDePince[0];
					 }
					//PIXY.BLOCK[GROS].OBJET A SUIVRE

					//Objet
					int xTresor = cam.getPixy().blocks[indiceGROS].x;
					int yTresor = cam.getPixy().blocks[indiceGROS].y;
					int widthTresor = cam.getPixy().blocks[indiceGROS].width;
					int hightTresor = cam.getPixy().blocks[indiceGROS].height;

					int centreHorizontalTresor = xTresor+(widthTresor/2);
					int centreVerticalTresor = yTresor+(hightTresor/2);

					if(!ultra.obstacleAt(9)){
						if( xTresor < cam.getPixy().blocks[PINCEGAUCHE].x ){
							Serial.print("Il faut tourner a gauche ");
							move.goAt(90,110);
						}
						else if((xTresor+widthTresor)>(cam.getPixy().blocks[PINCEDROITE].x+cam.getPixy().blocks[PINCEDROITE].width)){
							Serial.print("Il faut tourner a droite ");
							move.goAt(110,90);
						}
						else{
							Serial.print("Tout droit ");
							move.goAt(90,90);
						}
					}else{
						Serial.println(" Fermer la pince");
						move.goAt(0,0);
						pince.close();
						delay(10000);
						bras.up();
					}
				}else{
					bras.down(100);
					Serial.print("Descend le bras");
				}
			}
		}
	}
}
