#ifndef APPONSSETTING_H
#define APPONSSETTING_H
#include <QString>

class SettingParam{
public:
    QString ip;
    int width;
    int height;

    int scanSpeed;
    int sensitivityLevel;
    int scanMode;
    int dataPattern;
    int rayVoltage;
    int rayCurrent;
    int rayExposeTime;
    bool autoSave;
};

class ApponsSetting
{
public:

    ApponsSetting();
    static void showSettingDialog();

    int scanSpeed();
    void setScanSpeed(int s);
    int sensitivityLevel();
    void setSensitivityLevel(int s);
    int scanMode();
    void setScanMode(int m);
    int dataPattern();
    void setDataPattern(int b);
    int rayVoltage();
    void setRayVoltage(int v);
    int rayCurrent();
    void setRayCurrent(int c);
    int rayExposeTime();
    void setRayExposeTime(int s);
    bool autoSave();
    int setAutoSave(int b);

private:
    static SettingParam param;
    void LoadConfig();
};

#endif // APPONSSETTING_H
