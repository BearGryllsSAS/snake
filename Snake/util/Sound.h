#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/11/13 16:45:11

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
#ifndef _SOUND_H_
#define _SOUND_H_

//ʹ��ʾ��
//************************************
// ���������ļ�
// loadSound("sounds\\bg1.mp3", "bg1");
// ��������
// playSound("bg1", true);
// ��������
// settingVolume("bg1", 100);
// ��������
// changeVolume("bg1", 900);
// ��ͣ����
// pauseSound("bg1");
// �ָ�����
// resumeSound("bg1");
//************************************

//************************************
// Method:    commonCmd
// FullName:  commonCmd
// Access:    public 
// Returns:   void
// Qualifier: ִ��ͨ�ü�ָ��
// Parameter: const char * cmd ָ�����磺close��stop��pause��resume��
// Parameter: const char * name ���غ�ı��
//************************************
void commonCmd(const char* cmd, const char* name);
//************************************
// Method:    loadSound
// FullName:  loadSound
// Access:    public 
// Returns:   void
// Qualifier: ������Ƶ
// Parameter: const char * path ��Ƶ·��,��f://mpeg//bg.mp3
// Parameter: const char * name ���غ�ı��
//************************************
void loadSound(const char* path, const char* name);
//************************************
// Method:    unloadSound
// FullName:  unloadSound
// Access:    public 
// Returns:   void
// Qualifier: ж����Ƶ
// Parameter: const char * name ���غ�ı��
//************************************
void unloadSound(const char* name);
//************************************
// Method:    playSound
// FullName:  playSound
// Access:    public 
// Returns:   void
// Qualifier: ������Ƶ
// Parameter: const char * name ���غ�ı��
// Parameter: bool isLoop �Ƿ�ѭ������
//************************************
void playSound(const char* name, bool isLoop = false);
//************************************
// Method:    seekSound
// FullName:  seekSound
// Access:    public 
// Returns:   void
// Qualifier: ������Ƶ����λ��
// Parameter: const char * name ���غ�ı��
// Parameter: int pos ����λ�ô�0��ʼ
//************************************
void seekSound(const char* name, int pos);
//************************************
// Method:    stopSound
// FullName:  stopSound
// Access:    public 
// Returns:   void
// Qualifier: ֹͣ����
// Parameter: const char * name ���غ�ı��
//************************************
void stopSound(const char* name);
//************************************
// Method:    pauseSound
// FullName:  pauseSound
// Access:    public 
// Returns:   void
// Qualifier: ��ͣ����
// Parameter: const char * name ���غ�ı��
//************************************
void pauseSound(const char* name);
//************************************
// Method:    resumeSound
// FullName:  resumeSound
// Access:    public 
// Returns:   void
// Qualifier: �ָ�����
// Parameter: const char * name ���غ�ı��
//************************************
void resumeSound(const char* name);
//************************************
// Method:    changeVolume
// FullName:  changeVolume
// Access:    public 
// Returns:   int �����޸ĺ������ֵ
// Qualifier: �޸�������Ĭ��Ϊ���ֵ
// Parameter: const char * name ���غ�ı��
// Parameter: int ch �޸�����ֵ����С�����ø���
//************************************
int changeVolume(const char* name, int ch);
//************************************
// Method:    settingVolume
// FullName:  settingVolume
// Access:    public 
// Returns:   int �����޸ĺ������ֵ
// Qualifier: ����������Ĭ��Ϊ���ֵ
// Parameter: const char * name ���غ�ı��
// Parameter: int volume ����Ϊ����ֵ����Ч��ΧΪ0-1000
//************************************
int settingVolume(const char* name, int volume);

#endif