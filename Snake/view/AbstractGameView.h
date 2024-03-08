#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/03/29 21:17:49

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
#ifndef _ABSTRACTGAMEVIEW_H_
#define _ABSTRACTGAMEVIEW_H_
/**
 * 视图状态枚举
 */
enum class ViewStatus {
	NONE, ON_ENTER, ON_UPDATE, ON_EXIT
};

/**
 * 书写一个抽象游戏视图类
 */
class AbstractGameView
{
public:
	// 进入视图，默认调用init函数
	virtual void onEnter();
	// 更新视图，默认调用draw和handleInput
	virtual void update();
	// 退出视图，用于处理退出视图后执行的逻辑
	virtual void onExit();
	// 获取视图状态
	ViewStatus getStaus();
protected:
	// 视图状态
	ViewStatus status = ViewStatus::ON_ENTER;
	// 视图初始化
	virtual void init() = 0;
	// 内容绘制
	virtual void draw() = 0;
	// 处理输入
	virtual void handleInput() = 0;
};

#endif // !_ABSTRACTGAMEVIEW_H_