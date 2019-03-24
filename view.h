//
//  view.h
//  Spanner
//
//  Created by Saturn&Eric on 2018/12/30.
//  Copyright © 2018年 Bakantu. All rights reserved.
//
//  胡大佬深夜拔刀相助，小生没齿难忘 /斜眼笑

/*********************************
 *
 *窗体控件类定义头文件
 *
 ***/

#ifndef view_h
#define view_h
#include <vector>

using std::vector;
using std::string;

typedef vector<GLfloat> Color;

class Button {
	vector<GLfloat> points;

	vector<Color> colors;

public:
	string text;
	bool press;
	void(*func)(void);

	void draw(void) {
		if (!press)
			glColor3f(colors[0][1], colors[0][1], colors[0][2]);
		else glColor3f(colors[1][1], colors[1][1], colors[1][2]);
		glBegin(GL_POLYGON);
		glVertex2f(points[0], points[1]);
		glVertex2f(points[2], points[1]);
		glVertex2f(points[2], points[3]);
		glVertex2f(points[0], points[3]);
		glEnd();
		glColor3f(1, 1, 1);
		GLfloat width = points[2] - points[0], twidth = text.size() * 8;
		glRasterPos2f(points[0] + (width - twidth) / 2, (points[1] + points[3]) / 1.97);
		string::iterator it = text.begin();
		it = text.begin();
		while (it != text.end())
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);


	}
	Button(vector<GLfloat> m_points, string m_text, void(*func)(void) = NULL) :points(m_points), text(m_text), press(false), func(NULL) {
		colors.push_back({ 0.2,0.4,0.6 });
		colors.push_back({ 0.35,0.55,0.75 });
	}
	Button(vector<GLfloat> m_points, vector<GLfloat> hw, string m_text, void(*func)(void) = NULL) :text(m_text), press(false), func(NULL) {
		points.push_back(m_points[0]);
		points.push_back(m_points[1]);
		points.push_back(m_points[0] + hw[0]);
		points.push_back(m_points[1] + hw[1]);
		colors.push_back({ 0.2,0.4,0.6 });
		colors.push_back({ 0.35,0.55,0.75 });
	}
	Button(const Button &t) {
		press = t.press;
		text = t.text;
		points.assign(t.points.begin(), t.points.end());
		colors.assign(t.colors.begin(), t.colors.end());
		func = t.func;
	}
	~Button() {

	}
};

class Menu {
	vector<GLfloat> points;
	vector<GLfloat> hw;
	vector<Button *> buttons;
	int selected_index = 0;
public:
	Menu(vector<GLfloat> m_points, vector<GLfloat> m_hw) :points(m_points), hw(m_hw) {

	}
	void draw(void) {
		for (auto i = buttons.begin(); i != buttons.end(); i++)
			(*i)->draw();
	}
	void addButton(string text, void(*func)(void) = NULL) {
		Button *btn = new Button({ points[0],
			(points[1] + 15) + (hw[1] + 15)*(buttons.size() + 1) }, { hw[0],hw[1] }, text, func);
		btn->func = func;
		buttons.push_back(btn);

	}
	void selectButton(int index) {
		if (index < buttons.size() && index > -1) {
			for (auto i = buttons.begin(); i != buttons.end(); i++) (*i)->press = false;
			buttons[index]->press = true;
			selected_index = index;
		}
	}
	int getSelectedIndex(void) {
		return selected_index;
	}
	void callButtonFunc(int index) {
		if (buttons[index]->func != NULL) buttons[index]->func();
	}
	Menu(const Menu &t) {
		selected_index = t.selected_index;
		hw.assign(t.hw.begin(), t.hw.end());
		buttons.assign(t.buttons.begin(), t.buttons.end());
		points.assign(t.points.begin(), t.points.end());
	}
	~Menu() {
		for (auto i = buttons.begin(); i != buttons.end(); i++)
			delete (*i);
	}
};

#endif /* view_h */