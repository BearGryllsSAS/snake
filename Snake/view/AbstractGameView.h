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
 * ��ͼ״̬ö��
 */
enum class ViewStatus {
	NONE, ON_ENTER, ON_UPDATE, ON_EXIT
};

/**
 * ��дһ��������Ϸ��ͼ��
 */
class AbstractGameView
{
public:
	// ������ͼ��Ĭ�ϵ���init����
	virtual void onEnter();
	// ������ͼ��Ĭ�ϵ���draw��handleInput
	virtual void update();
	// �˳���ͼ�����ڴ����˳���ͼ��ִ�е��߼�
	virtual void onExit();
	// ��ȡ��ͼ״̬
	ViewStatus getStaus();
protected:
	// ��ͼ״̬
	ViewStatus status = ViewStatus::ON_ENTER;
	// ��ͼ��ʼ��
	virtual void init() = 0;
	// ���ݻ���
	virtual void draw() = 0;
	// ��������
	virtual void handleInput() = 0;
};

#endif // !_ABSTRACTGAMEVIEW_H_