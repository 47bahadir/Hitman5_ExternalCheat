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
	uintptr_t character_BaseAddy;				//Character Base Address
	uintptr_t ammo_BaseAddy;                    //Ammo Base Address
	uintptr_t position_BaseAddy;                //Position Base Address
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
	void onX_Posation_ApplyClicked();
	void onY_Posation_ApplyClicked();
	void onZ_Posation_ApplyClicked();
	//Check Box
	void onCheckBoxChanged();
};
