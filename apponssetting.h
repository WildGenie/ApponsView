#ifndef APPONSSETTING_H
#define APPONSSETTING_H
#include <QString>
#include <QObject>

class SettingParam{
public:
    QString ip;
    int width;
    int height;

    int scanSpeed;
    int sensitivityLevel;
    int scanMode;
    int dataPattern;
    int gainEnable;
    int offsetEnable;
    int rayVoltage;
    int rayCurrent;
    int rayExposeTime;
    bool autoSave;
    QString autoSavePath;
    int autoSaveSize;
};

class ApponsSetting: public QObject
{
    Q_OBJECT
public:

    ApponsSetting();
    void showSettingDialog();

    QString ip();
    long width();
    long height();

    int scanSpeed();
    //void setScanSpeed(int s);
    int sensitivityLevel();
    //void setSensitivityLevel(int s);
    int scanMode();
    //void setScanMode(int m);
    int dataPattern();
    //void setDataPattern(int b);
    int rayVoltage();
    //void setRayVoltage(int v);
    int rayCurrent();
    //void setRayCurrent(int c);
    int rayExposeTime();
    //void setRayExposeTime(int s);
    bool autoSave();
    //int setAutoSave(int b);

    int isGainEnable();
    int isOffsetEnable();

    QString autoSavePath();
    int autoSaveSize();
    void LoadConfig();
signals:
    void normalize();
private slots:
    void normalize_slot();
private:
    static SettingParam param;
};

#endif // APPONSSETTING_H
