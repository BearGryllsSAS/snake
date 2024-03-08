/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 16:31:42

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "ConsoleUtil.h"
#include <windows.h>

void ConsoleUtil::ctrCursorVisible(bool isShow)
{
	// ��ȡ����̨���
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ����̨�����ʾ���Կ���
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = isShow ? TRUE : FALSE;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void ConsoleUtil::gotoXY(short x, short y)
{
	// ��ȡ����̨���
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	// ���ÿ���̨���λ��
	COORD cursorPosition = { x, y };
	// ���ÿ���̨���λ��
	SetConsoleCursorPosition(consoleHandle, cursorPosition);
}
