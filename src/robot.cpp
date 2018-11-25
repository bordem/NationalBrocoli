#include "robot.h"

Robot::Robot(uchar port_gyro,uchar port_sound,uchar port_M1,uchar port_M2):
gyro(port_gyro,1),
ultra(port_sound,1),
move(port_M1,port_M2),
bras(SLOT_3),
pince(SLOT_4),
cam()
{}
void Robot::doPath(){

}
void Robot::findObject(){
	pince.open();
	float distanceBegin = ultra.readDistance(3);
	while(!ultra.obstacleAt(17)){
		static int i = 0;
		int j;
		uint16_t blocks;
		char buf[32];
		blocks = cam.getPixy().getBlocks();

		int tailleGrosObjet = 0;
		int indiceGrosObjet = 0;

		int indicePince1 = 0;
		int indicePince2 = 0;
		int nb_pinces = 0;

		if (blocks)
		{
		    i++;
		    // do this (print) every 50 frames because printing every
		    // frame would bog down the Arduino
		    if (i%2==0)
		    {
		      	for (j=0; j<blocks; j++)
		      	{
		        	if(cam.getPixy().blocks[j].signature==1);
					{
						if(cam.getPixy().blocks[j].width*cam.getPixy().blocks[j].height>tailleGrosObjet){
							tailleGrosObjet = cam.getPixy().blocks[j].width*cam.getPixy().blocks[j].height;
							indiceGrosObjet = j;
						}
					}
					if(cam.getPixy().blocks[j].signature==7);
					{
						if(nb_pinces==0){
							indicePince1 = j;
						}else{
							if(cam.getPixy().blocks[indicePince1].x<cam.getPixy().blocks[j].x){
								indicePince2 = j;
							}
							else{
								indicePince2=indicePince1;
								indicePince1=j;
							}
						}
						nb_pinces++;
					}
		      	}
				if(nb_pinces>1){
					if(cam.getPixy().blocks[indicePince1].x+cam.getPixy().blocks[indicePince1].width>cam.getPixy().blocks[indiceGrosObjet].x){
						move.goAt(90,150);
					}else if(cam.getPixy().blocks[indicePince2].x<cam.getPixy().blocks[indiceGrosObjet].x+cam.getPixy().blocks[indiceGrosObjet].width){
						move.goAt(150,90);
					}else{
						move.goAt(90,90);
					}
				}
				else{
					move.stop();
					bras.down(100);
				}
		    }
		}
	}
	move.stop();
	bras.down(200);
	pince.close(1000);
	bras.up(1000);
	move.backward(distanceBegin);
}
