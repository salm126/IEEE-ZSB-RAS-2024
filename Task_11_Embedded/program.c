#include <avr/io.h>


// Define pins switches
#define RIGHT_BUTTON PB0
#define LEFT_BUTTON PB1
#define FORWARD_BUTTON PB2
#define BACKWARD_BUTTON PB3
#define STOP_BUTTON PB4



#define MOTOR1_IN1 PC0
#define MOTOR1_IN2 PC1
#define MOTOR2_IN1 PC2
#define MOTOR2_IN2 PC3

void right() {
    PORTC &= ~(1 << MOTOR1_IN1);
    PORTC |= (1 << MOTOR1_IN2);
    PORTC |= (1 << MOTOR2_IN1);
    PORTC &= ~(1 << MOTOR2_IN2);

}


void left() {
    PORTC |= (1 << MOTOR1_IN1);
    PORTC &= ~(1 << MOTOR1_IN2);
    PORTC &= ~(1 << MOTOR2_IN1);
    PORTC |= (1 << MOTOR2_IN2);
}

void forward() {
    PORTC |= (1 << MOTOR1_IN1);
    PORTC &= ~(1 << MOTOR1_IN2);
    PORTC |= (1 << MOTOR2_IN1);
    PORTC &= ~(1 << MOTOR2_IN2);
}


void backward() {
    PORTC &= ~(1 << MOTOR1_IN1);
    PORTC |= (1 << MOTOR1_IN2);
    PORTC &= ~(1 << MOTOR2_IN1);
    PORTC |= (1 << MOTOR2_IN2);
}

void stop() {
    PORTC &= ~(1 << MOTOR1_IN1);
    PORTC &= ~(1 << MOTOR1_IN2);
    PORTC &= ~(1 << MOTOR2_IN1);
    PORTC &= ~(1 << MOTOR2_IN2);
}







int main(void) {
    // Set direction of ports
    DDRB = 0x00; // PORTB as input for buttons
    DDRC = 0xFF; // PORTC as output for motor control

    while (1) {
        // Check button states
        if ((PINB & (1 << RIGHT_BUTTON)) == 0) {
            right();
        } else if ((PINB & (1 << LEFT_BUTTON)) == 0) {
            left();
        } else if ((PINB & (1 << FORWARD_BUTTON)) == 0) {
            forward();
        } else if ((PINB & (1 << BACKWARD_BUTTON)) == 0) {
            backward();
        } else if ((PINB & (1 << STOP_BUTTON)) == 0) {
            stop();
        }
    }
}
