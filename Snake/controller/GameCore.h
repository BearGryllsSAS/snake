#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/25 18:19:32

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
#ifndef _GAMECORE_H_
#define _GAMECORE_H_
/**
 * 游戏过程控制
 */
class GameCore
{
private:
	// 游戏设置：设置游戏运行过程中不变动的设置
	void setup();
	// 游戏结束：游戏结束对应资源处理
	void end();
public:
	// 开始游戏
	void start();
};

#endif // !_GAMECORE_H_