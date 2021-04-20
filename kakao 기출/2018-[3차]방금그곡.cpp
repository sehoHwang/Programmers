/** 솔루션 **/

/*
    1. 우선 #이 붙은 음에 대해 change 함수를 통해 기존 음 목록에 있는 알파벳과 겹치지 않는 알파벳으로 치환하였다.

    2. 시작 시간과 종료 시간 사이의 차이를 통해 재생 시간을 구하였다.

    3. 재생 시간보다 악보가 길면 재생 시간만큼 잘랐으며, 재생 시간이 더 길 경우 나누기를 통해 반복 횟수만큼 악보를 더해준 뒤,
    나머지 연산을 통해 나머지 부분들을 더해주었다.

    4. 여러개의 악보다 m을 포함하고 있을 경우 재생된 시간이 제일 긴 음악 제목을 반환하기 위해 따로 btime이라는 변수를 두어 비교하면서
    저장하였다.
*/


#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

string change(string &in, map<string, char> &s)
{
    string out = "";
    
    for(int i = 0; i < in.size(); i++)
    {
        if(in[i + 1] == '#')
        {
            out += s[in.substr(i, 2)];
            i++;
        }
         else
            out += in[i];
    }
    return out;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int bHour = 0, aHour = 0, bMin = 0, aMin = 0, time = 0, bTime = 0;
    string melody = "", title = "";
    map<string, char> s;
    
    s["C#"] = 'Q';
    s["D#"] = 'W';
    s["F#"] = 'R';
    s["G#"] = 'T';
    s["A#"] = 'Y';
    
    melody = change(m, s);
    
    for(int i = 0; i < musicinfos.size(); i++)
    {
        string tmp = "", music = "";
        
        bHour = stoi(musicinfos[i].substr(0, 2)) * 60;
        bMin = stoi(musicinfos[i].substr(3, 2));
        aHour = stoi(musicinfos[i].substr(6, 2)) * 60;
        aMin = stoi(musicinfos[i].substr(9, 2));
        time = (aHour + aMin) - (bHour + bMin);
        
        //Divide title and Melody from musicinfos
        //tmp == melody
        for(int j = 12; musicinfos[i].size(); j++)
        {
            if(musicinfos[i][j] == ',')
            {
                title = musicinfos[i].substr(12, j - 12);
                tmp = musicinfos[i].substr(j + 1);
                break;
            }
        }
        
        music = change(tmp, s);

        if(music.size() < time)
        {
            tmp = music;
        
            for(int j = 1; j < time / tmp.size(); j++)
                music += tmp;
            for(int j = 0; j < time % tmp.size(); j++)
                music += tmp[j];
        }
        else
            music = music.substr(0, time);
        
        if(music.find(melody) != string::npos)
        {
            if(bTime < time)
            {
                answer = title;
                bTime = time;
            }
        }
    }
    return answer;
}