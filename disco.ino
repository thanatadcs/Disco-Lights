const float multiplier =  500;
unsigned long prev_time = 0;
unsigned long cur_time = 0;
int state = 0;
int prev_state = 0;
int count = 0;
float voltage = 0;
const int startPin = 2;
const int endPin = 7;
int pinNum = startPin;

void setup()
{
	for (int i=startPin;i<=endPin;i++)
		pinMode(i, OUTPUT);
}

void loop()
{
	voltage = analogRead(A0) * 5.0 / 1023.0;
	cur_time = millis();

	if (voltage > 3 && (cur_time - prev_time >= (5.0 - voltage) * multiplier + 10))
	{
		digitalWrite(pinNum, LOW);
		digitalWrite(pinNum, HIGH);
		pinNum++;
		if (pinNum > endPin)
			pinNum = startPin;
	}
	else if (voltage <= 3 && (cur_time - prev_time >= voltage * multiplier + 10))
	{
		digitalWrite(pinNum, LOW);
		digitalWrite(pinNum, HIGH);
		pinNum--;
		if (pinNum < startPin)
			pinNum = endPin;
	}
}
