#include "Gadget.h"

void Gadget::CreateQuadrangle2D()
{
	ATENGINE->CreateQuadrangle(
		ATATRGB::RED, ATATPOS2D(-205, +205),
		ATATRGB::YELLOW, ATATPOS2D(-205, -205),
		ATATRGB::GREEN, ATATPOS2D(+205, -205),
		ATATRGB::WHITE, ATATPOS2D(+205, +205));
	ATENGINE->DrawEnd();
}

void Gadget::CreateQuadrangle3D()
{
	ATENGINE->CreateQuadrangle(
		ATATRGB::RED, ATATPOS3D(-205, +205,0),
		ATATRGB::YELLOW, ATATPOS3D(-205, -205,0),
		ATATRGB::GREEN, ATATPOS3D(+205, -205,0),
		ATATRGB::WHITE, ATATPOS3D(+205, +205,0));
	ATENGINE->DrawEnd();
}

void Gadget::CreateCircular2D(int Side, float R)
{
	ATENGINE->EnableBase(GL_POLYGON);

	//半径为1的圆的周长

	//弧长 = PI * R
	//弧长 / 1 = 360
	//弧长 / 0.5 = 180

	float Perimeter = (2.0f * M_PI);

	for (float i = 0; i < Side; i++)
	{
		float SideNum = (i / Side);
		//周长 / 边 = Angle
		//Angle = 周长 / 边

		//弧长 / 边 = Angle
		//Angle = 弧长 / 边
		float Angle = Perimeter * SideNum;

		float COS = cos(Angle);
		float SIN = sin(Angle);

		ATENGINE->Color3F(ATATRGB(rand() % 255,rand() % 10,255));
		ATENGINE->Draw_Points(R * COS, R * SIN);
	}
	ATENGINE->DrawEnd();
}

void Gadget::CreateMusicMapCircular2D(float *Data, int DataLen, int Side, float R)
{
	//半径为1的圆的周长
	float Perimeter = (2.0f * M_PI);
	//float Scale = (float)Side / (float)DataLen;//=>
	for (float i = 0; i < DataLen; i++)
	{
		//float SideNum1 = (i * Scale / Side); //=>
		//float SideNum2 = ((i + 1.0f) * Scale / Side); //=>
		float SideNum1 = (i / DataLen);
		float SideNum2 = ((i + 1.0f) / DataLen);

		float Angle1 = Perimeter * SideNum1;
		float Angle2 = Perimeter * SideNum2;

		float COS1 = cos(Angle1);
		float SIN1 = sin(Angle1);

		float COS2 = cos(Angle2);
		float SIN2 = sin(Angle2);

		ATVector2D TempVec(ATVector2D(R * COS1, R * SIN1) + ATVector2D(R * COS2, R * SIN2));

		float Points = TempVec.Length() / 2.0f;
		int Point = Points;

		if (i <= 92)
		{
			int MusicData = Data[(int)i] * 1000;
			float Tmp = MusicData % Point;
			TempVec /= ((int)Tmp % 20);
		}
		else
		{
			int MusicData = Data[(int)i] * 10000;
			float Tmp = MusicData % Point;
			TempVec /= ((int)Tmp % 20);
		}

		ATENGINE->CreateTriangle(
			ATATRGB::WHITE, ATATPOS2D(TempVec.x, TempVec.y),
			ATATRGB::GREEN,ATATPOS2D(R * COS1,R * SIN1),
			ATATRGB::GREEN, ATATPOS2D(R * COS2, R * SIN2));
	}
	ATENGINE->DrawEnd();
}
void Gadget::CreateMusicMapLine2D(float *Data, int DataLen, int Side, float R)
{
	ATENGINE->EnableBase(GL_LINES);
	//半径为1的圆的周长
	float Perimeter = (2.0f * M_PI);
	for (float i = 0; i < DataLen; i++)
	{
		float SideNum1 = (i / DataLen);
		float SideNum2 = ((i + 1.0f) / DataLen);

		float Angle1 = Perimeter * SideNum1;
		float Angle2 = Perimeter * SideNum2;

		float COS1 = cos(Angle1);
		float SIN1 = sin(Angle1);

		float COS2 = cos(Angle2);
		float SIN2 = sin(Angle2);

		ATVector2D TempVec(ATVector2D(R * COS1, R * SIN1) + ATVector2D(R * COS2, R * SIN2));

		float Points = TempVec.Length() / 2.0f;
		int Point = Points;

		if (i <= 92)
		{
			int MusicData = Data[(int)i] * 1000;
			float Tmp = MusicData % Point;
			TempVec /= ((int)Tmp % 20);
		}
		else
		{
			int MusicData = Data[(int)i] * 10000;
			float Tmp = MusicData % Point;
			TempVec /= ((int)Tmp % 20);
		}

		ATENGINE->Draw_Points(ATATPOS2D(TempVec.x, TempVec.y));
		ATVector2D Vertex = ATVector2D(R * COS1, R * SIN1) + ATVector2D(R * COS2, R * SIN2);
		Vertex /= 2;
		ATENGINE->Draw_Points(ATATPOS2D(Vertex.x, Vertex.y));
	}
	ATENGINE->DrawEnd();
}

void Gadget::CreateNotRing2D(int Side, float R, float Width)
{
	//半径为1的圆的周长
	float Perimeter = (2.0f * M_PI);

	for (float i = 0; i < Side; i++)
	{
		float SideNum1 = (i / Side);
		float SideNum2 = ((i + 1.0f) / Side);

		float Angle1 = Perimeter * SideNum1;
		float Angle2 = Perimeter * SideNum2;

		float COS1 = cos(Angle1);
		float SIN1 = sin(Angle1);

		float COS2 = cos(Angle2);
		float SIN2 = sin(Angle2);

		ATVector2D TempVec(ATVector2D(R * COS1, R * SIN1) + ATVector2D(R * COS2, R * SIN2));
		float Points = TempVec.Length() / 2.0f;
		TempVec *= Width;

		ATENGINE->CreateTriangle(
			ATATRGB::WHITE, ATATPOS2D(TempVec.x, TempVec.y),
			ATATRGB::GREEN, ATATPOS2D(R * COS1, R * SIN1),
			ATATRGB::GREEN, ATATPOS2D(R * COS2, R * SIN2));
	}
	ATENGINE->DrawEnd();
}