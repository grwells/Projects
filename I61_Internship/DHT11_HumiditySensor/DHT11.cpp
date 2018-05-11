#include "DHT11.h"

DHT11::DHT11(int pinNum){
	wiringPiSetup();
	pinNumber = pinNum;
}

float DHT11::read(void){
	uint8_t laststate = HIGH;
	uint8_t counter = 0;
	uint8_t j = 0, i;
	float f;

	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

	pinMode(pinNumber, OUTPUT);

	digitalWrite(pinNumber, HIGH);
	delay(18);

	digitalWrite(pinNumber, LOW);
	delayMicroseconds(40);

	pinMode(pinNumber, INPUT);

	for(int i = 0; i < 85; i++){
		counter = 0;
		while(digitalRead(pinNumber) == laststate){
			counter++;
			delayMicroseconds(1);
			if(counter == 255){
				break;
			}
		}
		laststate = digitalRead(pinNumber);

		if(counter == 255){break;}
		
		if((i >= 4) && (i % 2 == 0)){
			dht11_dat[j/8] <<= 1;

			if(counter > 16){
				dht11_dat[j/8] = 1;
			}

			j++;
		}
	}

	if((j >= 40) && (dht11_dat[4] == (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3] & 0xFF))){
		f = dht11_dat[2] * 9. / 5. + 32;
		printf("Humidity = %d.%d %% Temperature = %d.%d C (%.1f F)\n", dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3], f);
	}else{
		printf("Data not good, skip\n");
	}

	return 0.0;
}
