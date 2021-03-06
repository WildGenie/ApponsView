#include "apponssetting.h"
#include <QSettings>
#include <settingdialog.h>
#include <QCoreApplication>

SettingParam ApponsSetting::param;

ApponsSetting::ApponsSetting()
{
   // LoadConfig();
}

void ApponsSetting::LoadConfig()
{
    path =  QCoreApplication::applicationDirPath ();
    QSettings setting(path+"/config.ini", QSettings ::IniFormat);
    param.ip = setting.value("Network/ip", "192.168.1.25").toString();
    param.width = setting.value("Image/width", 1280).toInt();
    param.height = setting.value("Image/height", 1024).toInt();

    param.gainEnable = setting.value("Detector/gain", 0).toInt();
    param.offsetEnable = setting.value("Detector/offset", 0).toInt();

    //param.scanSpeed = setting.value("Detector/scanSpeed", 200).toInt();
    //change speed to integration time unit is us
    param.scanSpeed = setting.value("Detector/scanSpeed", 2000).toInt();
    param.sensitivityLevel = setting.value("Detector/sensitivity", 1).toInt();
    param.dataPattern = setting.value("Detector/dataPattern", 0).toInt();
    param.targetValue = setting.value("Detector/targetValue", 10000).toInt();
    param.startPixel = setting.value("Detector/startPixel", 0).toInt();
    param.endPixel = setting.value("Detector/endPixel", param.width).toInt();


    param.scanMode = setting.value("Display/scanMode", 0).toInt();
    param.rayVoltage = setting.value("RaySource/rayVoltage", 120).toInt();
    param.rayCurrent = setting.value("RaySource/rayCurrent", 2).toInt();
    param.rayExposeTime = setting.value("RaySource/rayExposeTime", 2).toInt();
    param.autoSave = setting.value("Image/autoSave", false).toBool();
    param.autoSavePath = setting.value("Image/autoSavePath", path).toString();
    param.autoSaveSize = setting.value("Image/autoSaveSize", 10).toInt();
    param.autoSaveFrames = setting.value("Image/autoSaveFrames", 10).toInt();
    param.MixOrder = setting.value("Protocal/MixOrder",0).toBool();
    param.dualMode = setting.value("Protocal/DualMode", 0).toBool();
    param.revert = setting.value("Protocal/revert", 0).toBool();
}

QString ApponsSetting::ip()
{
    return param.ip;
}

long ApponsSetting::width()
{
    return param.width;
}

long ApponsSetting::height()
{
    return param.height;
}

int ApponsSetting::scanSpeed()
{
    return param.scanSpeed;
}

int ApponsSetting::sensitivityLevel()
{
    return param.sensitivityLevel;
}

int ApponsSetting::scanMode()
{
    return param.scanMode;
}

int ApponsSetting::dataPattern()
{
    return param.dataPattern;
}

int ApponsSetting::rayVoltage()
{
    return param.rayVoltage;
}

int ApponsSetting::rayCurrent()
{
    return param.rayCurrent;
}

int ApponsSetting::rayExposeTime()
{
    return param.rayExposeTime;
}

void ApponsSetting::setAutoSave(bool enable)
{
    param.autoSave = enable;
}

bool ApponsSetting::autoSave()
{
    return param.autoSave;
}

QString ApponsSetting::autoSavePath()
{
    return param.autoSavePath;
}

int ApponsSetting::autoSaveSize()
{
    return param.autoSaveSize;
}

int ApponsSetting::autoSaveFrames()
{
    return param.autoSaveFrames;
}

void ApponsSetting::setOffsetEnable(bool bEnabel)
{
    param.offsetEnable = bEnabel;
}

void ApponsSetting::setGainEnable(bool bEnabel)
{
    param.gainEnable = bEnabel;
}

int ApponsSetting::isGainEnable()
{
    return param.gainEnable   ;
}

int ApponsSetting::isOffsetEnable()
{
    return param.offsetEnable;
}

void ApponsSetting::normalize_slot()
{
    emit normalize();
}

int ApponsSetting::targetValue()
{
    return param.targetValue;
}

int ApponsSetting::startPixel()
{
    return param.startPixel;
}

int ApponsSetting::endPixel()
{
    return param.endPixel;
}

void ApponsSetting::save()
{
        QSettings setting(path+"/config.ini", QSettings ::IniFormat);

        setting.setValue("Network/ip", param.ip );
        setting.setValue("Detector/scanSpeed", param.scanSpeed);
        setting.setValue("Detector/sensitivity", param.sensitivityLevel);
        setting.setValue("Detector/dataPattern", param.dataPattern);
        setting.setValue("Detector/gain", param.gainEnable);
        setting.setValue("Detector/offset", param.offsetEnable);
        setting.setValue("Detector/targetValue", param.targetValue);
        setting.setValue("Detector/startPixel", param.startPixel);
        setting.setValue("Detector/endPixel", param.endPixel);

        setting.setValue("Display/scanMode", param.scanMode);
        setting.setValue("RaySource/rayVoltage", param.rayVoltage);
        setting.setValue("RaySource/rayCurrent", param.rayCurrent);
        setting.setValue("RaySource/rayExposeTime", param.rayExposeTime);
        setting.setValue("Image/autoSave", param.autoSave);
        setting.setValue("Image/autoSavePath", param.autoSavePath);

        setting.setValue("Image/autoSaveFrames", param.autoSaveFrames);

}

void ApponsSetting::showSettingDialog()
{
    SettingDialog dlg(&param);
    QObject::connect(&dlg, &SettingDialog::normalize, this, &ApponsSetting::normalize_slot, Qt::QueuedConnection);
    if(dlg.exec() == QDialog::Accepted){
        param.scanSpeed = dlg.scanSpeed();
        param.sensitivityLevel = dlg.sensitivityLevel();
        param.dataPattern = dlg.dataPattern();
        param.scanMode = dlg.scanMode();
        param.rayVoltage = dlg.rayVoltage();
        param.rayCurrent =dlg.rayCurrent();
        param.rayExposeTime = dlg.rayExposeTime();
       // param.autoSave = dlg.autoSave();
        param.autoSavePath =  dlg.autoSavePath();
        param.autoSaveFrames = dlg.autoSaveFrames();

        param.startPixel = dlg.startPixel();
        param.endPixel = dlg.endPixel();

    }
    save();
}
