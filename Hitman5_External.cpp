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
	connect(ui.Score_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onScoreApplyClicked);
	connect(ui.X_Posation_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onX_Posation_ApplyClicked);
	connect(ui.Y_Posation_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onY_Posation_ApplyClicked);
	connect(ui.Z_Posation_ApplyButton, &QPushButton::clicked, this, &Hitman5_External::onZ_Posation_ApplyClicked);

	//connect the Check box
	connect(ui.InfiniteHealth_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
	connect(ui.UnlimitedBullets_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
	connect(ui.NoRecoil_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
	connect(ui.oneShootKill_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
	connect(ui.NoSpread_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
	connect(ui.NonStopShooting_checkBox, &QCheckBox::stateChanged, this, &Hitman5_External::onCheckBoxChanged);
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

	//Calculate BaseCharacter
	character_BaseAddy = modBaseAddy + 0x00E21358;

	//Calculate Position base address
	position_BaseAddy = modBaseAddy + 0x00E3951C;

	//Get Health address
	health_Addy = mem::findDMAAddy(hProc, character_BaseAddy, { 0x780,0x24,0xA2C,0x218});

	//Get Score address
	score_Addy = modBaseAddy + 0xD64A78;

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


void Hitman5_External::onScoreApplyClicked()
{
	//check input value is valid or not
	bool ok;
	int newScore = ui.Score_EditLine->text().toInt(&ok);
	if (!ok)
	{
		QMessageBox::warning(this, "Error", "Please enter a valid integer number for Score!");
		return;
	}

	//Check Score value is valid or not
	BOOL retRPM = ReadProcessMemory(hProc, (void*)score_Addy, &g_score, sizeof(g_score), 0);
	if (retRPM)
	{
		if (!WriteProcessMemory(hProc, (void*)score_Addy, &newScore, sizeof(newScore), 0))
		{
			QMessageBox::warning(this, "Error", "Failed to write score value !");
		}
	}
	else
	{
		QMessageBox::warning(this, "Error", "Failed to read score value !");
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
	//InfiniteHealth_checkBox
	if (checkbox == ui.InfiniteHealth_checkBox)
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

	//UnlimitedBullets_checkBox
	if (checkbox == ui.UnlimitedBullets_checkBox)
	{
		//Checked
		if (checkbox->isChecked())
		{
			//HMA.exe+5ECEAD - 90                    - nop
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x5ECEAD), 1);
		}
		//UnChecked
		else
		{
			//HMA.exe+5ECEAD - 48                    - dec eax
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x5ECEAD), (BYTE*)"\x48", 1);
		}
	}

	//NoRecoil_checkBox
	if (checkbox == ui.NoRecoil_checkBox)
	{
		//Checked
		if (checkbox->isChecked())
		{
			//HMA.exe+55ECFD - 90 90                 - nop nop
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x55ECFD), 2);

			//HMA.exe+55ED0B - 90 90                 - nop nop
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x55ED0B), 2);
		}
		//UnChecked
		else
		{
			//HMA.exe+55ECFD - 7A 20                 - jp HMA.exe+55ED1F
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x55ECFD), (BYTE*)"\x7A\x20", 2);

			//HMA.exe+55ED0B - 7A 12                 - jp HMA.exe+55ED1F
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x55ED0B), (BYTE*)"\x7A\x12", 2);
		}
	}

	//oneShootKill_checkBox
	if (checkbox == ui.oneShootKill_checkBox)
	{
		//Checked
		if (checkbox->isChecked())
		{
			//HMA.exe+5FADB6 - 90 90                 - nop nop
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x5FADB6), 2);
		}
		//UnChecked
		else
		{
			//HMA.exe+5FADB6 - 7A 0A                 - jp HMA.exe+5FADC2
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x5FADB6), (BYTE*)"\x7A\x0A", 2);
		}
	}

	//NoSpread_checkBox
	if (checkbox == ui.NoSpread_checkBox)
	{
		//Checked
		if (checkbox->isChecked())
		{
			//HMA.exe+5ECA10 - 90 90 90 90 90 90        - nop * 6
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x5ECA10), 6);
		}
		//UnChecked
		else
		{
			//HMA.exe+5ECA10 - D9 9F 20 04 00 00        - fstp dword ptr [edi+00000420]
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x5ECA10), (BYTE*)"\xD9\x9F\x20\x04\x00\x00", 6);
		}
	}

	//NonStopShooting_checkBox
	if (checkbox == ui.NonStopShooting_checkBox)
	{
		//Checked
		if (checkbox->isChecked())
		{
			//HMA.exe+5ECE7B - 90 90 90 90 90 90 90     - nop * 7
			mem::nopEx(hProc, (BYTE*)(modBaseAddy + 0x5ECE7B), 7);
		}
		//UnChecked
		else
		{
			//HMA.exe+5ECE7B - 66 FF 87 04 04 00 00     - inc word ptr [edi+00000404]
			mem::patchEx(hProc, (BYTE*)(modBaseAddy + 0x5ECE7B), (BYTE*)"\x66\xFF\x87\x04\x04\x00\x00", 7);
		}
	}


}