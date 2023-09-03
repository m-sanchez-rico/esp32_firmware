// Arduino libraries.
#include <Arduino.h>

// Encoder pins definition
// Left encoder
#define Left_Encoder_PinA 17  // Interrupt PIN
#define Left_Encoder_PinB 16
volatile long Left_Encoder_Ticks = 0; // Count the number of ticks
volatile bool LeftEncoderBSet;        // Variable to read current state of left encoder pin

// Right Encoder
#define Right_Encoder_PinA 4 //Interrupt PIN
#define Right_Encoder_PinB 0
volatile long Right_Encoder_Ticks = 0; // Count the numbers of ticks
volatile bool RightEncoderBSet;        // Variable to read current state of right encoder pin

void do_Left_Encoder()
{
    LeftEncoderBSet = digitalRead(Left_Encoder_PinB); // read the input pin
    Left_Encoder_Ticks -= LeftEncoderBSet ? -1 : +1;
}
void do_Right_Encoder()
{
    RightEncoderBSet = digitalRead(Right_Encoder_PinB); // read the input pin
    Right_Encoder_Ticks += RightEncoderBSet ? -1 : +1;
}

void SetupEncoders()
{
    // Quadrature encoders
    // Right encoder
    pinMode(Right_Encoder_PinA, INPUT_PULLUP); // sets pin A as input
    pinMode(Right_Encoder_PinB, INPUT_PULLUP); // sets pin B as input
    attachInterrupt(digitalPinToInterrupt(Right_Encoder_PinA), do_Right_Encoder, RISING);

    // Left encoder
    pinMode(Left_Encoder_PinA, INPUT_PULLUP); // sets pin A as input
    pinMode(Left_Encoder_PinB, INPUT_PULLUP); // sets pin B as input
    attachInterrupt(digitalPinToInterrupt(Left_Encoder_PinA), do_Left_Encoder, RISING);
}


void setup()
{
    Serial.begin(115200); // Init Serial port with 115200 buad rate
    SetupEncoders();
}

void Update_Encoders()
{
    Serial.print("e");
    Serial.print("\t");
    Serial.print(Left_Encoder_Ticks);
    Serial.print("\t");
    Serial.print(Right_Encoder_Ticks);
    Serial.print("\n");
}

void loop()
{
    Update_Encoders();
}
