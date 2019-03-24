//
//  event.cpp
//  Spanner
//
//  Created by Saturn&Eric on 2018/12/30.
//  Copyright © 2018年 Bakantu. All rights reserved.
//
//  胡大佬深夜拔刀相助，小生没齿难忘 /斜眼笑

#include "../include/event.h"
#include "../include/main.h"
#include "../include/control.h"
#include "../include/gameresult.h"

extern bool menu;
extern int window_id;

void start_onClick(void){
    resetGame();
    replay = true;
}

void about_onClick(void) {
	menu = false;
}

void exit_onClick(void) {
	glutDestroyWindow(window_id);
}
