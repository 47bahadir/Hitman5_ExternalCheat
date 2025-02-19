#include "Hitman5_External.h"

Hitman5_External::Hitman5_External(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	//Set window title
	this->setWindowTitle("HITMAN:Absolution External Cheat");

	//Set window icon
	this->setWindowIcon(QIcon(":/Hitman5_External/hitman5.ico"));

	//call user function
	processInfo();

	//connect the apply button
	connect(ui.Health_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onHealthApplyClicked);
	connect(ui.R_PistolAmmo_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onR_PistolAmmo_ApplyClicked);
	connect(ui.L_PistolAmmo_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onL_PistolAmmo_ApplyClicked);
	connect(ui.X_Posation_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onX_Posation_ApplyClicked);
	connect(ui.Y_Posation_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onY_Posation_ApplyClicked);
	connect(ui.Z_Posation_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onZ_Posation_ApplyClicked);

	//connect the Check box
	connect(ui.LockHealth_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
	connect(ui.LockAmmo_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
}

Hitman5_External::~Hitman5_External()
{}


void Hitman5_External::processInfo()
{
	//Get process id
	procID = mem::getProcId(L"HMA.exe");
	if (procID == 0)
	{
		QMessageBox::warning(this, "Error", "Failed to get process ID !");
	}

	//Get handle for process
	hProc = OpenProcess(PROCESS_ALL_ACCESS, false, procID);
	if (hProc == INVALID_HANDLE_VALUE)
	{
		QMessageBox::warning(this, "Error", "Failed to get process HANDLE !");
	}

	//Get process base address
	modBaseAddy = mem::getModuleBase(L"HMA.exe", procID);
	if (modBaseAddy == 0)
	{
		QMessageBox::warning(this, "Error", "Failed to get Module Base Address !");
	}

	//Calculate Ammo base address
	ammo_BaseAddy = modBaseAddy + 0x00E214FC;

	//Calculate Health base address
	health_BaseAddy = modBaseAddy + 0x00E17748;

	//Calculate Position base address
	position_BaseAddy = modBaseAddy + 0x00E3951C;

	//Get left pistol ammo address
	l_PistolAmmo_Addy = mem::findDMAAddy(hProc, ammo_BaseAddy, { 0x4C,0xC,0x406 });

	//Get right pistol ammo address
	r_PistolAmmo_Addy = mem::findDMAAddy(hProc, ammo_BaseAddy, { 0x4C,0x4,0x406});

	//Get Health address
	health_Addy = mem::findDMAAddy(hProc, health_BaseAddy, { 0x60C,0xA50,0xC,0x780,0x24,0xA2C,0x218});

	//Get XYZ position 
	x_position_Addy = mem::findDMAAddy(hProc, position_BaseAddy, { 0x2C,0xE80 });
	y_position_Addy = x_position_Addy + 0x4;
	z_position_Addy = y_position_Addy + 0x4;

}




/////////////////////////////////////////////////////////////////////////Apply Clicked///////////////////////////////////////////////////////////////////////////////////////////////////////



void Hitman5_External::onHealthApplyClicked()
{
	//check input value is valid or not
	bool ok;
	float newHealth = ui.Health_EditLine->text().toFloat(&ok);
	if (!ok)
	{
		QMessageBox::warning(this, "Error", "Please enter a valid float number for Health!");
		return;
	}

	//Check Health value is valid or not
	BOOL retRPM = ReadProcessMemory(hProc, (void*)health_Addy, &health, sizeof(health), 0);
	if (retRPM)
	{
		if (!WriteProcessMemory(hProc, (void*)health_Addy, &newHealth, sizeof(newHealth), 0))
		{
			QMessageBox::warning(this, "Error", "Failed to write health value !");
		}
	}
	else
	{
		QMessageBox::warning(this, "Error", "Failed to read health value !");
		return;
	}
}


void Hitman5_External::onR_PistolAmmo_ApplyClicked()
{
	//check input value is valid or not
	bool ok;
	int newAmmo = ui.R_PistolAmmo_EditLine->text().toInt(&ok);
	if (!ok)
	{
		QMessageBox::warning(this, "Error", "Please enter a valid integer number for Ammo!");
		return;
	}

	//Check Right Pistol Ammo value is valid or not
	BOOL retRPM = ReadProcessMemory(hProc, (void*)r_PistolAmmo_Addy, &r_PistolAmmo, sizeof(r_PistolAmmo), 0);
	if (retRPM)
	{
		if (!WriteProcessMemory(hProc, (void*)r_PistolAmmo_Addy, &newAmmo, sizeof(newAmmo), 0))
		{
			QMessageBox::warning(this, "Error", "Failed to write ammo value !");
		}
	}
	else
	{
		QMessageBox::warning(this, "Error", "Failed to read ammo value !");
		return;
	}

}

void Hitman5_External::onL_PistolAmmo_ApplyClicked()
{
	//check input value is valid or not
	bool ok;
	int newAmmo = ui.L_PistolAmmo_EditLine->text().toInt(&ok);
	if (!ok)
	{
		QMessageBox::warning(this, "Error", "Please enter a valid integer number for Ammo!");
		return;
	}

	//Check Left Pistol Ammo value is valid or not
	BOOL retRPM = ReadProcessMemory(hProc, (void*)l_PistolAmmo_Addy, &l_PistolAmmo, sizeof(l_PistolAmmo), 0);
	if (retRPM)
	{
		if (!WriteProcessMemory(hProc, (void*)l_PistolAmmo_Addy, &newAmmo, sizeof(newAmmo), 0))
		{
			QMessageBox::warning(this, "Error", "Failed to write ammo value !");
		}
	}
	else
	{
		QMessageBox::warning(this, "Error", "Failed to read ammo value !");
		return;
	}
}

void Hitman5_External::onX_Posation_ApplyClicked()
{
	//check input value is valid or not
	bool ok;
	float newPosition = ui.X_Posation_EditLine->text().toFloat(&ok);
	if (!ok)
	{
		QMessageBox::warning(this, "Error", "Please enter a valid float number for Position!");
		return;
	}

	//Check X Position value is valid or not
	BOOL retRPM = ReadProcessMemory(hProc, (void*)x_position_Addy, &x_position, sizeof(x_position), 0);
	if (retRPM)
	{
		if (!WriteProcessMemory(hProc, (void*)x_position_Addy, &newPosition, sizeof(newPosition), 0))
		{
			QMessageBox::warning(this, "Error", "Failed to write position value !");
		}
	}
	else
	{
		QMessageBox::warning(this, "Error", "Failed to read position value !");
		return;
	}
}


void Hitman5_External::onY_Posation_ApplyClicked()
{
	//check input value is valid or not
	bool ok;
	float newPosition = ui.Y_Posation_EditLine->text().toFloat(&ok);
	if (!ok)
	{
		QMessageBox::warning(this, "Error", "Please enter a valid float number for Position!");
		return;
	}

	//Check Y Position value is valid or not
	BOOL retRPM = ReadProcessMemory(hProc, (void*)y_position_Addy, &y_position, sizeof(y_position), 0);
	if (retRPM)
	{
		if (!WriteProcessMemory(hProc, (void*)y_position_Addy, &newPosition, sizeof(newPosition), 0))
		{
			QMessageBox::warning(this, "Error", "Failed to write position value !");
		}
	}
	else
	{
		QMessageBox::warning(this, "Error", "Failed to read position value !");
		return;
	}


}


void Hitman5_External::onZ_Posation_ApplyClicked()
{
	//check input value is valid or not
	bool ok;
	float newPosition = ui.Z_Posation_EditLine->text().toFloat(&ok);
	if (!ok)
	{
		QMessageBox::warning(this, "Error", "Please enter a valid float number for Position!");
		return;
	}

	//Check Z Position value is valid or not
	BOOL retRPM = ReadProcessMemory(hProc, (void*)z_position_Addy, &z_position, sizeof(z_position), 0);
	if (retRPM)
	{
		if (!WriteProcessMemory(hProc, (void*)z_position_Addy, &newPosition, sizeof(newPosition), 0))
		{
			QMessageBox::warning(this, "Error", "Failed to write position value !");
		}
	}
	else
	{
		QMessageBox::warning(this, "Error", "Failed to read position value !");
		return;
	}


}


/////////////////////////////////////////////////////////////////////////Check Box///////////////////////////////////////////////////////////////////////////////////////////////////////

//check box control the script
void Hitman5_External::onCheckBoxChanged()
{
	QCheckBox* checkbox = qobject_cast<QCheckBox*>(sender());
	
	if (!checkbox) return;
	//LockHealth_checkBox
	if (checkbox == ui.LockHealth_checkBox)
	{
		//Checked
		if (checkbox->isChecked())
		{
			//HMA.exe+4082E4 - 90 90 90 90 90 90
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x4082E4), 6);
		}
		//UnChecked
		else
		{
			//HMA.exe+4082E4 - D9 9E 18 02 00 00
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x4082E4), (BYTE*)"\xD9\x9E\x18\x02\x00\x00", 6);
		}
	}

	//LockAmmo_checkBox
	if (checkbox == ui.LockAmmo_checkBox)
	{
		//Checked
		if (checkbox->isChecked())
		{
			//HMA.exe+2F5C80 - 90 90 90 90 90 90 90
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x2F5C80), 7);
		}
		//UnChecked
		else
		{
			//HMA.exe+2F5C80 - 66 89 86 16 03 00 00
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x2F5C80), (BYTE*)"\x66\x89\x86\x16\x03\x00\x00", 7);
		}
	}

}