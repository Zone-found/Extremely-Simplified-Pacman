#include "../include/gameresult.h"
#include "../include/main.h"
#include <sstream>
//游戏结果
void resultsDisplay() {
	if (points == 106) {
		//胜利
		string message = "*************************************";
		string::iterator it = message.begin();
		glRasterPos2f(140, 260);
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "CONGRATULATIONS, YOU WON! ";
		glColor3f(1, 1, 1);
		glRasterPos2f(173, 316);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "*************************************";
		glRasterPos2f(140, 380);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "To restart the game, press the space key.";
		glRasterPos2f(209, 500);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
		message = "To go back to the menu, press the enter key.";
		glRasterPos2f(195, 540);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
		//彩蛋 比心
		message = "****    ****";
		glColor3f(1, 1, 1);
		glRasterPos2f(613, 601);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it++);
		message = "*******  *******";
		glColor3f(1, 1, 1);
		glRasterPos2f(602, 616);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it++);
		message = "************";
		glColor3f(1, 1, 1);
		glRasterPos2f(610, 631);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it++);
		message = "********";
		glColor3f(1, 1, 1);
		glRasterPos2f(620, 646);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it++);
		message = "****";
		glColor3f(1, 1, 1);
		glRasterPos2f(630, 661);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it++);
		message = "*";
		glColor3f(1, 1, 1);
		glRasterPos2f(638, 676);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it++);
		//署名
		message = "Zone & Little Cutie & Aglaia";
		glColor3f(1, 1, 1);
		glRasterPos2f(560, 720);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *it++);
		//鸣谢  Saturn&Eric
		message = "Saturn&Eric";
		glColor3f(1, 1, 1);
		glRasterPos2f(593, 695);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	}
	else {
		//失败
		string message = "*************************************";
		string::iterator it = message.begin();
		glRasterPos2f(160, 250);
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "SORRY, YOU LOST ... ";
		glColor3f(1, 1, 1);
		glRasterPos2f(255, 300);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "*************************************";
		glRasterPos2f(160, 350);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "You got: ";
		glRasterPos2f(260, 400);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		stringstream ss;
		ss << points;
		string result = ss.str();
		message = (char*)result.c_str();
		glRasterPos2f(350, 400);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = " points!";
		glRasterPos2f(385, 400);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		message = "To restart the game, press the space key.";
		glRasterPos2f(209, 520);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
		message = "To go back to the menu, press the enter key.";
		glRasterPos2f(195, 565);
		it = message.begin();
		while (it != message.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	}
}
