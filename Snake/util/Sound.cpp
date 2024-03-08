/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/13 16:51:56

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
#ifndef UNICODE
#define UNICODE
#define RM_UNICODE
#endif // !UNICODE

#include "Sound.h"
#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")

void commonCmd(const char* cmd, const char* name) {
	wchar_t cmdstr[100];
	wsprintf(cmdstr, L"%hs %hs", cmd, name);
	mciSendString(cmdstr, NULL, 0, NULL);
}

void loadSound(const char* path, const char* name) {
	/*
	 * �ο�˵����
	 * mciSendString "open mName type MPEGVideo alias movie parent %u Style %u notify",0&, 0, 0
	 * open:��������
	 * mName:ȫ·���ļ���
	 * type MPEGVideo:��ָ��MPEG,AVI�����ͣ����������һ�䣬���Ǵ�WAV,MP3��
	 * alias movie:�����˸ò����ı���Ϊmovie����������ֻҪָ����������
	 * parent %u:Դ
	 * Style %u:��ʽ
	 * notify:֪ͨ
	 */
	wchar_t cmd[500];
	wsprintf(cmd, L"open \"%hs\" alias %hs", path, name);
	mciSendString(cmd, NULL, 0, NULL);
}

void unloadSound(const char* name) {
	commonCmd("close", name);
}

void playSound(const char* name, bool isLoop/* = false*/) {
	seekSound(name, 0);
	/**
	 * play device_alias from pos1 to pos2 wait repeat
	 * ��ʡ��from��ӵ�ǰ�ŵ���ʼ���ţ���ʡ��to�򲥷ŵ�������
	 * ��ָ��wait��ȵ������������ŷ��ء�
	 * ��ָ��repeat��᲻ͣ���ظ����š���ͬʱָ��wait��repeat������᷵�أ����̲߳���������ͨ�����������ʧȥ��Ӧ��
	 */
	wchar_t cmd[100];
	wsprintf(cmd, L"play %hs %hs", name, isLoop ? "repeat" : "");
	mciSendString(cmd, NULL, 0, NULL);
}

void seekSound(const char* name, int pos) {
	wchar_t cmdstr[100];
	wsprintf(cmdstr, L"seek %hs to %i", name, pos);
	mciSendString(cmdstr, NULL, 0, NULL);
}

void stopSound(const char* name) {
	seekSound(name, 0);
	commonCmd("stop", name);
}

void pauseSound(const char* name)
{
	commonCmd("pause", name);
}

void resumeSound(const char* name)
{
	commonCmd("resume", name);
}

int changeVolume(const char* name, int ch)
{
	//��ȡ����
	wchar_t cmd1[100];
	wchar_t volume[256];
	wsprintf(cmd1, L"status %hs volume", name);
	mciSendString(cmd1, volume, sizeof(volume) / 2, 0);
	int v0 = _wtoi(volume);
	//�޸�����
	wchar_t cmd2[100];
	wsprintf(cmd2, L"setaudio %hs volume to %i", name, v0 + ch);
	mciSendString(cmd2, NULL, 0, NULL);
	//�ٴλ�ȡ����
	mciSendString(cmd1, volume, sizeof(volume) / 2, 0);
	v0 = _wtoi(volume);
	return v0;
}

int settingVolume(const char* name, int volume)
{
	//�޸�����
	wchar_t cmd2[100];
	wsprintf(cmd2, L"setaudio %hs volume to %i", name, volume);
	mciSendString(cmd2, NULL, 0, NULL);
	//��ȡ����
	wchar_t cmd1[100];
	wchar_t volumeBuff[256];
	wsprintf(cmd1, L"status %hs volume", name);
	mciSendString(cmd1, volumeBuff, sizeof(volumeBuff) / 2, 0);
	return _wtoi(volumeBuff);
}

#ifdef RM_UNICODE
#undef UNICODE
#undef RM_UNICODE
#endif // RM_UNICODE
