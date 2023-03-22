#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL0KAIpaN5"
#define BLYNK_TEMPLATE_NAME "FEEDINGIOT"
#define BLYNK_AUTH_TOKEN "sQo_IUI80-hRq4RHLe3mzMWMk59FEZBk"
#include <BlynkSimpleEsp32.h>
char ssid[] = "Find Me Free Wifi";
char pass[] = "11333355555577777777";

// =============================== Define pin ===============================
#define ONOFF_FeedSpeed 26 //EN
#define ONOFF_Range 16 //EN
#define feedSpeed_control 25 // IN1
#define range_control 27 // IN2
#define onoffthis 32 
// 5v = 5V
// =============================== Declare Val ===============================
int feedstatus = 0; //V0
int FeedSpeed = 0; //V1
int Range = 0; //V2
// =============================== Blynk Update ===============================
BLYNK_WRITE(V0) // feed status
{
  feedstatus = param.asInt();
  Serial.println("Blynk button pressed");
}

BLYNK_WRITE(V1) // feed status
{
  FeedSpeed = param.asInt();
  Serial.println("Blynk button pressed");

}
BLYNK_WRITE(V2) // feed status
{
  Range = param.asInt();
  Serial.println("Blynk button pressed");
}

// =============================== Change to Range PWM   ===============================
int to_PWM(float percent){
  //Turn percent into PWM inversely from 170(slow) to 90(fast)
  return (int)(230- (percent/100) * (230-90));
}
// ====================================================

void setup()
{
  Serial.begin(115200);
  Serial.println("start");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // control pwm
  pinMode(ONOFF_FeedSpeed, OUTPUT);
  pinMode(ONOFF_Range, OUTPUT);
  pinMode(feedSpeed_control, OUTPUT);
  pinMode(range_control, OUTPUT);
  ledcSetup(0, 9000, 8);
  ledcSetup(1, 9000, 8);
}

void loop() {
  int CalFeedSpeed;
  int CalRange;
  ledcAttachPin(feedSpeed_control, 0);
  ledcAttachPin(range_control, 1);
  Serial.print("feedstatus:  ");
  Serial.println(feedstatus);
  CalFeedSpeed = to_PWM(FeedSpeed);
  CalRange = to_PWM(Range);
  // Code here ==============================================
  // Recievie : FeedSpeed 0-255,  Range 0-255,   feedstatus ON/OFF(0,1)   if want to change go config in app
  if(feedstatus == 1)
  {
    ledcWrite(0, CalFeedSpeed);
    ledcWrite(1, CalRange);
    digitalWrite(onoffthis, LOW);
    digitalWrite(ONOFF_FeedSpeed, HIGH);
    digitalWrite(ONOFF_Range, HIGH);
    Serial.print("FeedspeedPWM:  ");
    Serial.println(CalFeedSpeed);
    Serial.print("RangePWM:  ");
    Serial.println(CalRange);
    Serial.print("FeedSpeed:  ");
    Serial.println(FeedSpeed);
    Serial.print("Range:  ");
    Serial.println(Range);
  }
  else{
    digitalWrite(onoffthis, HIGH);
    digitalWrite(ONOFF_FeedSpeed, LOW);
    digitalWrite(ONOFF_Range, LOW);

  }
  delay(100);
  Blynk.run();
}
