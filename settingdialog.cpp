#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QSettings>
#include "apponssetting.h"

SettingDialog::SettingDialog(SettingParam* param, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    ui->sensitivty->addItem("Low");
    ui->sensitivty->addItem("High");
    ui->scanMode->addItem("Frame");
    ui->scanMode->addItem("Continues");

    setScanMode(param->scanMode);
    setScanSpeed(param->scanSpeed);
    setSensitivityLevel(param->sensitivityLevel);
    setDataPattern(param->dataPattern);
    setRayVoltage(param->rayVoltage);
    setRayCurrent(param->rayCurrent);
    setRayExposeTime(param->rayExposeTime);
    setAutoSave(param->autoSave);
}


SettingDialog::~SettingDialog()
{
    delete ui;
}

int SettingDialog::scanSpeed()
{
    return ui->scanSpeed->text().toInt();
}

void SettingDialog::setScanSpeed(int s)
{
    ui->scanSpeed->setText(QString::number(s));
}

int SettingDialog::sensitivityLevel()
{
    return ui->sensitivty->currentIndex();
}

void SettingDialog::setSensitivityLevel(int s)
{
    ui->sensitivty->setCurrentIndex(s);
}

int SettingDialog::scanMode()
{
    return ui->scanMode->currentIndex();
}

void SettingDialog::setScanMode(int m)
{
    ui->scanMode->setCurrentIndex(m);
}

int SettingDialog::dataPattern ()
{
    return ui->dataPattern->isChecked();
}

void SettingDialog::setDataPattern (int b)
{
    ui->dataPattern->setChecked(b);
}

int SettingDialog::rayVoltage()
{
    return ui->rayVoltage->text().toInt();
}

void SettingDialog::setRayVoltage(int v)
{
    ui->rayVoltage->setText(QString::number(v));
}

int SettingDialog::rayCurrent()
{
    return ui->rayCurrent->text().toInt();
}

void SettingDialog::setRayCurrent(int c)
{
    ui->rayCurrent->setText(QString::number(c));

}

int SettingDialog::rayExposeTime()
{
    return ui->exposeTime->text().toInt();
}

void SettingDialog::setRayExposeTime(int s)
{
    ui->exposeTime->setText(QString::number(s));
}

int SettingDialog::autoSave()
{
    return ui->autoSave->isChecked();
}

void SettingDialog::setAutoSave(int b)
{
    return ui->autoSave->setChecked(b);
}
