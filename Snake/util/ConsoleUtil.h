#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 16:31:04

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
#ifndef _CONSOLEUTIL_H_
#define _CONSOLEUTIL_H_
/**
 * ��дһ������̨������
 */
class ConsoleUtil
{
public:
	//************************************
	// Method:    ctrCursorVisible
	// FullName:  ConsoleUtil::ctrCursorVisible
	// Access:    public static 
	// Returns:   void
	// Qualifier: ���ƹ����ʾ
	// Parameter: bool isShow �Ƿ���ʾ
	//************************************
	static void ctrCursorVisible(bool isShow);
	//************************************
	// Method:    gotoXY
	// FullName:  ConsoleUtil::gotoXY
	// Access:    public static 
	// Returns:   void
	// Qualifier: �ƶ���굽ָ��λ��
	// Parameter: short x x���꣬��0��ʼ
	// Parameter: short y y���꣬��0��ʼ
	//************************************
	static void gotoXY(short x, short y);
};

#endif // !_CONSOLEUTIL_H_