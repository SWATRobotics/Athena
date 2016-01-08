#include "WPILib.h"
#include "Autonomous/Atm1.cpp"
#include "Autonomous/Atm2.cpp"
#include "Autonomous/Atm3.cpp"
#include "Autonomous/Atm4.cpp"
#include "Autonomous/Atm5.cpp"
#include "Autonomous/Atm6.cpp"
#include "Autonomous/Atm7.cpp"
#include "Autonomous/Atm8.cpp"
#include "Autonomous/Atm9.cpp"
#include "Autonomous/Atm10.cpp"

class Robot: public IterativeRobot {
	RobotDrive rdF;
	RobotDrive rdR;
	Joystick jsE;
	Joystick jsL;
	Joystick jsR;
	Victor vctR;
	Victor vctF;
	Victor vctE;
	Compressor cps;
	DoubleSolenoid ds1;
	DoubleSolenoid ds2;
	DigitalInput diMaxSwitch;
	DigitalInput diMinSwitch;

public:
	Robot() :
			rdF(0, 2), rdR(1, 3), jsE(2), jsL(0), jsR(1), vctR(4), vctF(5), vctE(
					7), cps(), ds1(0, 1), ds2(2, 3), diMaxSwitch(0), diMinSwitch(
					1) {
	}

private:
	void RobotInit() {
		SmartDashboard::PutBoolean("Autonomous 1", true);
		SmartDashboard::PutBoolean("Autonomous 2", true);
		SmartDashboard::PutBoolean("Autonomous 3", true);
		SmartDashboard::PutBoolean("Autonomous 4", true);
		SmartDashboard::PutBoolean("Autonomous 5", true);
		SmartDashboard::PutBoolean("Autonomous 6", true);
		SmartDashboard::PutBoolean("Autonomous 7", true);
		SmartDashboard::PutBoolean("Autonomous 8", true);
		SmartDashboard::PutBoolean("Autonomous 9", true);
		SmartDashboard::PutBoolean("Autonomous 10", true);
	}

	int pointer = 0;
	int index = 0;
	void AutonomousInit() {
		pointer = 0;

		if (SmartDashboard::GetBoolean("Autonomous 1")) {
			index = 1;
		} else if (SmartDashboard::GetBoolean("Autonomous 2")) {
			index = 2;
		} else if (SmartDashboard::GetBoolean("Autonomous 3")) {
			index = 3;
		} else if (SmartDashboard::GetBoolean("Autonomous 4")) {
			index = 4;
		} else if (SmartDashboard::GetBoolean("Autonomous 5")) {
			index = 5;
		} else if (SmartDashboard::GetBoolean("Autonomous 6")) {
			index = 6;
		} else if (SmartDashboard::GetBoolean("Autonomous 7")) {
			index = 7;
		} else if (SmartDashboard::GetBoolean("Autonomous 8")) {
			index = 8;
		} else if (SmartDashboard::GetBoolean("Autonomous 9")) {
			index = 9;
		} else if (SmartDashboard::GetBoolean("Autonomous 10")) {
			index = 10;
		} else {
			index = 0;
		}

	}

	void AutonomousPeriodic() {
		float leftInput;
		float rightInput;
		float elevatorInput;
		int wheelInput;
		int lowerClaw;
		int upperClaw;

		if (index == 1) {
			if (pointer >= Atm1Count) {
				return;
			}
			leftInput = Atm1[pointer][0];
			rightInput = Atm1[pointer][1];
			elevatorInput = Atm1[pointer][2];
			wheelInput = (int) Atm1[pointer][3];
			lowerClaw = (int) Atm1[pointer][4];
			upperClaw = (int) Atm1[pointer][5];
		} //else if (index == 2) {
//			if (pointer >= Atm2Count) {
//				return;
//			}
//			leftInput = Atm2[pointer][0];
//			rightInput = Atm2[pointer][1];
//			elevatorInput = Atm2[pointer][2];
//			wheelInput = (int) Atm2[pointer][3];
//			lowerClaw = (int) Atm2[pointer][4];
//			upperClaw = (int) Atm2[pointer][5];
//		} else if (index == 3) {
//			if (pointer >= Atm3Count) {
//				return;
//			}
//			leftInput = Atm3[pointer][0];
//			rightInput = Atm3[pointer][1];
//			elevatorInput = Atm3[pointer][2];
//			wheelInput = (int) Atm3[pointer][3];
//			lowerClaw = (int) Atm3[pointer][4];
//			upperClaw = (int) Atm3[pointer][5];
//		} else if (index == 4) {
//			if (pointer >= Atm4Count) {
//				return;
//			}
//			leftInput = Atm4[pointer][0];
//			rightInput = Atm4[pointer][1];
//			elevatorInput = Atm4[pointer][2];
//			wheelInput = (int) Atm4[pointer][3];
//			lowerClaw = (int) Atm4[pointer][4];
//			upperClaw = (int) Atm4[pointer][5];
//		} else if (index == 5) {
//			if (pointer >= Atm5Count) {
//				return;
//			}
//			leftInput = Atm5[pointer][0];
//			rightInput = Atm5[pointer][1];
//			elevatorInput = Atm5[pointer][2];
//			wheelInput = (int) Atm5[pointer][3];
//			lowerClaw = (int) Atm5[pointer][4];
//			upperClaw = (int) Atm5[pointer][5];
//		} else if (index == 6) {
//			if (pointer >= Atm6Count) {
//				return;
//			}
//			leftInput = Atm6[pointer][0];
//			rightInput = Atm6[pointer][1];
//			elevatorInput = Atm6[pointer][2];
//			wheelInput = (int) Atm6[pointer][3];
//			lowerClaw = (int) Atm6[pointer][4];
//			upperClaw = (int) Atm6[pointer][5];
//		} else if (index == 7) {
//			if (pointer >= Atm7Count) {
//				return;
//			}
//			leftInput = Atm7[pointer][0];
//			rightInput = Atm7[pointer][1];
//			elevatorInput = Atm7[pointer][2];
//			wheelInput = (int) Atm7[pointer][3];
//			lowerClaw = (int) Atm7[pointer][4];
//			upperClaw = (int) Atm7[pointer][5];
//		} else if (index == 8) {
//			if (pointer >= Atm8Count) {
//				return;
//			}
//			leftInput = Atm8[pointer][0];
//			rightInput = Atm8[pointer][1];
//			elevatorInput = Atm8[pointer][2];
//			wheelInput = (int) Atm8[pointer][3];
//			lowerClaw = (int) Atm8[pointer][4];
//			upperClaw = (int) Atm8[pointer][5];
//		} else if (index == 9) {
//			if (pointer >= Atm9Count) {
//				return;
//			}
//			leftInput = Atm9[pointer][0];
//			rightInput = Atm9[pointer][1];
//			elevatorInput = Atm9[pointer][2];
//			wheelInput = (int) Atm9[pointer][3];
//			lowerClaw = (int) Atm9[pointer][4];
//			upperClaw = (int) Atm9[pointer][5];
//		} else if (index == 10) {
//			if (pointer >= Atm10Count) {
//				return;
//			}
//			leftInput = Atm10[pointer][0];
//			rightInput = Atm10[pointer][1];
//			elevatorInput = Atm10[pointer][2];
//			wheelInput = (int) Atm10[pointer][3];
//			lowerClaw = (int) Atm10[pointer][4];
//			upperClaw = (int) Atm10[pointer][5];
//		} else {
//			return;
//		}

		pointer++;

		this->rdF.SetLeftRightMotorOutputs(leftInput, rightInput);
		this->rdR.SetLeftRightMotorOutputs(leftInput, rightInput);

		if ((elevatorInput < 0) && (!this->diMaxSwitch.Get())) //elevator up
				{
			this->vctE.Set(0);
		} else if ((elevatorInput > 0) && (!this->diMinSwitch.Get())) //elevator down
				{
			this->vctE.Set(0);
		} else {
			this->vctE.Set(elevatorInput);
		}

		if (wheelInput == 1) //In
				{
			this->vctR.Set(-1);
			this->vctF.Set(1);
		} else if (wheelInput == -1) //Out
				{
			this->vctR.Set(1);
			this->vctF.Set(-1);
		} else {
			this->vctR.Set(0);
			this->vctF.Set(0);
		}

		//kForward: 1; kReverse: -1;
		if (lowerClaw == 1) //Close
				{
			this->ds1.Set(DoubleSolenoid::kForward);
		} else if (lowerClaw == -1) //Open
				{
			this->ds1.Set(DoubleSolenoid::kReverse);
		} else {
			this->ds1.Set(DoubleSolenoid::kOff);
		}

		//kForward: 1; kReverse = -1;
		if (upperClaw == 1) {
			this->ds2.Set(DoubleSolenoid::kForward);
		} else if (upperClaw == -1) {
			this->ds2.Set(DoubleSolenoid::kReverse);
		} else {
			this->ds2.Set(DoubleSolenoid::kOff);
		}

		Wait(0.01);
	}

	void TeleopInit() {
		printf("Hello world! - From TeleopInit() \n");
		this->cps.Start();
	}

	void Drive() {
		//Tank Drive
		float leftInput = -1 * this->jsL.GetY();
		float rightInput = -1 * this->jsR.GetY();
		this->rdF.SetLeftRightMotorOutputs(leftInput, rightInput);
		this->rdR.SetLeftRightMotorOutputs(leftInput, rightInput);
	}

	void TeleopPeriodic() {
		this->Drive();

		float elevatorInput = this->jsE.GetY();
		if ((elevatorInput < 0) && (!this->diMaxSwitch.Get())) //elevator up
				{
			this->vctE.Set(0);
		} else if ((elevatorInput > 0) && (!this->diMinSwitch.Get())) //elevator down
				{
			this->vctE.Set(0);
		} else {
			this->vctE.Set(elevatorInput);
		}

		if (this->jsR.GetRawButton(2)) //In
				{
			this->vctR.Set(-1);
			this->vctF.Set(1);
		} else if (this->jsR.GetRawButton(3)) //Out
				{
			this->vctR.Set(1);
			this->vctF.Set(-1);
		} else {
			this->vctR.Set(0);
			this->vctF.Set(0);
		}

		if (this->jsR.GetRawButton(4)) //Close
				{
			this->ds1.Set(DoubleSolenoid::kForward);
		} else if (this->jsR.GetRawButton(5)) //Open
				{
			this->ds1.Set(DoubleSolenoid::kReverse);
		} else {
			this->ds1.Set(DoubleSolenoid::kOff);
		}

		if (this->jsE.GetRawButton(4)) {
			this->ds2.Set(DoubleSolenoid::kForward);
		} else if (this->jsE.GetRawButton(5)) {
			this->ds2.Set(DoubleSolenoid::kReverse);
		} else {
			this->ds2.Set(DoubleSolenoid::kOff);
		}

		//printf("Hello world! - From TeleopPeriodic() \n");
	}

	void TestPeriodic() {
//		float speedCoefficient;
//		if (this->jsE.GetRawButton(5))
//		{ speedCoefficient = 0.7; }
//		else if (this->jsE.GetRawButton(7))
//		{ speedCoefficient = 0.3; }
//		else
//		{ speedCoefficient = 1; }
//		if (!this->jsE.GetRawButton(8))
//		{
//			//Tank Drive
//			float leftInput = -1 * this->jsE.GetY();
//			float rightInput = -1 * this->jsE.GetThrottle();
//			this->rdF.SetLeftRightMotorOutputs(leftInput * speedCoefficient, rightInput * speedCoefficient);
//			this->rdR.SetLeftRightMotorOutputs(leftInput * speedCoefficient, rightInput * speedCoefficient);
//			printf("Hello world! - From TestPeriodic() Tank Drive, MotorOutput: %f; %f\n", leftInput * speedCoefficient, rightInput * speedCoefficient);
//		}
//		else
//		{
//			//Arcade Drive
//			float leftInput = -1 * this->jsE.GetY();
//			float rightInput = leftInput;
//			float rotate = this->jsE.GetX();
//			leftInput += rotate;
//			rightInput -= rotate;
//			this->rdF.SetLeftRightMotorOutputs(leftInput * speedCoefficient, rightInput * speedCoefficient);
//			this->rdR.SetLeftRightMotorOutputs(leftInput * speedCoefficient, rightInput * speedCoefficient);
//			printf("Hello world! - From TestPeriodic() Arcade Drive, MotorOutput: %f; %f\n", leftInput * speedCoefficient, rightInput * speedCoefficient);
//		}
//
//		float speedInput = (-1 * this->jsR.GetZ() + 1) / 2;
//		if (this->jsR.GetRawButton(5))
//		{
//			if (!this->diMinSwitch.Get())
//			{
//				this->vctE.Set(-1 * speedInput);
//				printf("Hello world! - From TestPeriodic() ElevatorDown, Speed: %f\n", speedInput);
//			}
//			else
//			{
//				printf("Hello world! - From TestPeriodic() MinSwitchOn");
//				this->vctE.Set(0);
//			}
//		}
//		else if (this->jsR.GetRawButton(4))
//		{
//			if (!this->diMaxSwitch.Get())
//			{
//				this->vctE.Set(1 * speedInput);
//				printf("Hello world! - From TestPeriodic() ElevatorUp, Speed: %f\n", speedInput);
//			}
//			else
//			{
//				printf("Hello world! - From TestPeriodic() MaxSwitchOn");
//				this->vctE.Set(0);
//			}
//		}
//		else
//		{ this->vctE.Set(0); }
//
//		if (this->jsE.GetRawButton(2))
//		{
//			this->vctR.Set(-1);
//			this->vctF.Set(1);
//			printf("Hello world! - From TestPeriodic() WheelIn\n");
//		}
//		else if (this->jsE.GetRawButton(4))
//		{
//			this->vctR.Set(1);
//			this->vctF.Set(-1);
//			printf("Hello world! - From TestPeriodic() WheelOut\n");
//		}
//		else
//		{
//			this->vctR.Set(0);
//			this->vctF.Set(0);
//		}
//
//		if (this->jsE.GetRawButton(1))
//		{
//			this->ds1.Set(DoubleSolenoid::kForward);
//			printf("Hello world! - From TestPeriodic() ClawClosed\n");
//		}
//		else if (this->jsE.GetRawButton(3))
//		{
//			this->ds1.Set(DoubleSolenoid::kReverse);
//			printf("Hello world! - From TestPeriodic() ClawOpened\n");
//		}
//		else
//		{ this->ds1.Set(DoubleSolenoid::kOff); }
//		this->Drive();

//		double NTe = this->table->GetNumber("E", 0.0);
//		float elevatorInput = this->jsE.GetY();
//		if ((NTe < 0) && (!this->diMaxSwitch.Get()))//elevator up
//		{ this->vctE.Set(0); }
//		else if ((NTe > 0) && (!this->diMinSwitch.Get()))//elevator down
//		{ this->vctE.Set(0); }
//		else
//		{ this->vctE.Set(elevatorInput); }
		///////////////////////////////////////////////////////////////

//		this->table->PutNumber("E", 1.0);
//		printf("PutNumber\n");
//
//		if (this->jsR.GetRawButton(2))//In
//		{ this->vctR.Set(-1); this->vctF.Set(1); }
//		else if (this->jsR.GetRawButton(3))//Out
//		{ this->vctR.Set(1); this->vctF.Set(-1); }
//		else
//		{ this->vctR.Set(0); this->vctF.Set(0); }
//
//		if (this->jsR.GetRawButton(4))//Close
//		{ this->ds1.Set(DoubleSolenoid::kForward); }
//		else if (this->jsR.GetRawButton(5))//Open
//		{ this->ds1.Set(DoubleSolenoid::kReverse); }
//		else
//		{ this->ds1.Set(DoubleSolenoid::kOff); }
//
//		if (this->jsE.GetRawButton(4))
//		{ this->ds2.Set(DoubleSolenoid::kForward); }
//		else if (this->jsE.GetRawButton(5))
//		{ this->ds2.Set(DoubleSolenoid::kReverse); }
//		else
//		{ this->ds2.Set(DoubleSolenoid::kOff); }

		float leftInput = -1 * this->jsL.GetY();
		float rightInput = -1 * this->jsR.GetY();
		this->rdF.SetLeftRightMotorOutputs(leftInput, rightInput);
		this->rdR.SetLeftRightMotorOutputs(leftInput, rightInput);

		float elevatorInput = this->jsE.GetY();
		if ((elevatorInput < 0) && (!this->diMaxSwitch.Get()))	//elevator up
				{
			this->vctE.Set(0);
		} else if ((elevatorInput > 0) && (!this->diMinSwitch.Get()))//elevator down
				{
			this->vctE.Set(0);
		} else {
			this->vctE.Set(elevatorInput);
		}

		int wheelInput = 0;
		if (this->jsR.GetRawButton(2))		//In
				{
			this->vctR.Set(-1);
			this->vctF.Set(1);
			wheelInput = 1;
		} else if (this->jsR.GetRawButton(3))		//Out
				{
			this->vctR.Set(1);
			this->vctF.Set(-1);
			wheelInput = -1;
		} else {
			this->vctR.Set(0);
			this->vctF.Set(0);
			wheelInput = 0;
		}

		int lowerClaw = 0;		//kForward: 1; kReverse: -1;
		if (this->jsR.GetRawButton(4))		//Close
				{
			this->ds1.Set(DoubleSolenoid::kForward);
			lowerClaw = 1;
		} else if (this->jsR.GetRawButton(5))		//Open
				{
			this->ds1.Set(DoubleSolenoid::kReverse);
			lowerClaw = -1;
		} else {
			this->ds1.Set(DoubleSolenoid::kOff);
			lowerClaw = 0;
		}

		int upperClaw = 0;		//kForward: 1; kReverse = -1;
		if (this->jsE.GetRawButton(4)) {
			this->ds2.Set(DoubleSolenoid::kForward);
			upperClaw = 1;
		} else if (this->jsE.GetRawButton(5)) {
			this->ds2.Set(DoubleSolenoid::kReverse);
			upperClaw = -1;
		} else {
			this->ds2.Set(DoubleSolenoid::kOff);
			upperClaw = 0;
		}

		printf("		{%f, %f, %f, %d, %d, %d},\n", leftInput, rightInput,
				elevatorInput, wheelInput, lowerClaw, upperClaw);

		Wait(0.01);
	}
};

START_ROBOT_CLASS(Robot);
