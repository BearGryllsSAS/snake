#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 16:34:56

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
#ifndef _POSTION_H_
#define _POSTION_H_

/**
 * 定义一个坐标类
 */
class Postion {
public:
	// x坐标
	int x;
	// y坐标
	int y;
	// 成员变量初始化构造
	Postion(int x, int y);
	// 默认构造
	Postion();
	// 比较是否相等
	bool isEqual(int x, int y);
	bool isEqual(const Postion& pos);
	// 定义加减坐标
	void addX(int x);
	void addY(int y);
	void addXY(int x, int y);
};

#endif // !_POSTION_H_