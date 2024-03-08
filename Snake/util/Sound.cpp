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
	 * 参考说明：
	 * mciSendString "open mName type MPEGVideo alias movie parent %u Style %u notify",0&, 0, 0
	 * open:操作命令
	 * mName:全路径文件名
	 * type MPEGVideo:是指打开MPEG,AVI等类型，如果不加这一句，就是打开WAV,MP3等
	 * alias movie:定义了该操作的别名为movie，后续操作只要指明别名即可
	 * parent %u:源
	 * Style %u:样式
	 * notify:通知
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
	 * 若省略from则从当前磁道开始播放，若省略to则播放到结束。
	 * 若指明wait则等到播放完毕命令才返回。
	 * 若指明repeat则会不停的重复播放。若同时指明wait和repeat则命令不会返回，本线程产生堵塞，通常会引起程序失去响应。
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
	//获取音量
	wchar_t cmd1[100];
	wchar_t volume[256];
	wsprintf(cmd1, L"status %hs volume", name);
	mciSendString(cmd1, volume, sizeof(volume) / 2, 0);
	int v0 = _wtoi(volume);
	//修改音量
	wchar_t cmd2[100];
	wsprintf(cmd2, L"setaudio %hs volume to %i", name, v0 + ch);
	mciSendString(cmd2, NULL, 0, NULL);
	//再次获取音量
	mciSendString(cmd1, volume, sizeof(volume) / 2, 0);
	v0 = _wtoi(volume);
	return v0;
}

int settingVolume(const char* name, int volume)
{
	//修改音量
	wchar_t cmd2[100];
	wsprintf(cmd2, L"setaudio %hs volume to %i", name, volume);
	mciSendString(cmd2, NULL, 0, NULL);
	//获取音量
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
