#include <afstandssensor.h>
                                        // AfstandsSensor(triggerPin, echoPin);
AfstandsSensor s1(2, 5); 
AfstandsSensor s2(23, 22); 
//AfstandsSensor s3(2, 5); 
// Starter afstandssensoren på ben 13 og 12.

void setup () {
    Serial.begin(9600);  // Opsætter serial kommunikation tilbage til computeren
}

void loop () {
    // Måler afstanden for hver 500ms
    int a = s1.afstandCM();
    int b = s2.afstandCM();
    Serial.println(a);
    //Serial.print(" ");
    Serial.println(b);
    delay(100);
}
