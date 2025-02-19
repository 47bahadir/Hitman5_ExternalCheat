#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_Hitman5_External.h"
#include "mem.h"

class Hitman5_External : public QMainWindow
{
    Q_OBJECT

public:
    Hitman5_External(QWidget *parent = nullptr);
    ~Hitman5_External();

private:
    Ui::Hitman5_ExternalClass ui;

	//User Voluble
	DWORD procID;                               //Process id
	HANDLE hProc;                               //Process Handle
	uintptr_t modBaseAddy;                      //Module Base Address
	uintptr_t ammo_BaseAddy;                    //Ammo Base Address
	uintptr_t health_BaseAddy;					//Health Base Address
	uintptr_t position_BaseAddy;                //Position Base Address
	uintptr_t l_PistolAmmo_Addy;                //Left Pistol Ammo Address
	int l_PistolAmmo;							//Left Pistol Ammo Value
	uintptr_t r_PistolAmmo_Addy;                //Right Pistol Ammo Address
	int r_PistolAmmo;							//Right Pistol Ammo Value
	uintptr_t health_Addy;                      //Health Address
	float health;								//Health value
	uintptr_t x_position_Addy;                  //X Position Address
	float x_position;							//X Position Value
	uintptr_t y_position_Addy;                  //Y Position Address
	float y_position;							//Y Position Value
	uintptr_t z_position_Addy;                  //Z Position Address
	float z_position;							//Z Position Value

	//User Function
    void processInfo();

private slots:
	//Apply Button
    void onHealthApplyClicked();
    void onR_PistolAmmo_ApplyClicked();
	void onL_PistolAmmo_ApplyClicked();
	void onX_Posation_ApplyClicked();
	void onY_Posation_ApplyClicked();
	void onZ_Posation_ApplyClicked();
	//Check Box
	void onCheckBoxChanged();
};
